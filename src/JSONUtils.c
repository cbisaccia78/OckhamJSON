#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StringUtils.h"
#include "JSONUtils.h"

/*
    TESTED
*/
int equalsParse(char **jsonSubString, char *string, int length){
    int i = 0;
    while(i < length && *(*jsonSubString)++ == string[i++])
        ;
    return i == length;
}

/*
    UNTESTED
*/
int parseString(char **jsonSubString){
    return 0;
}
/*
    UNTESTED

    Numeric values that cannot be represented in the grammar below (such
    as Infinity and NaN) are not permitted.

      number = [ minus ] int [ frac ] [ exp ]

      decimal-point = %x2E       ; .

      digit1-9 = %x31-39         ; 1-9

      e = %x65 / %x45            ; e E

      exp = e [ minus / plus ] 1*DIGIT

      frac = decimal-point 1*DIGIT
      
      int = zero / ( digit1-9 *DIGIT )

      minus = %x2D               ; -

      plus = %x2B                ; +

      zero = %x30                ; 0
*/
int parseNumber(char **jsonSubString, char type){
    //"1234"
    int i = 0;
    char c = **jsonSubString;
    int negative = c == '-' ? 1 : 0;
    if(negative){
        i++;
    }

    while((c = (*jsonSubString)[i]) != '\0' && c == ZERO){
        i++;
    }
    if(c == '\0') return -1; // either "-" or "-0[0]", valid JSON? 

    while((c = (*jsonSubString)[i]) != '\0' && c >= ZERO && c < NINE){
        i++;
    }
    if(c == '\0') return -1; // either "-" or "-0[0]", valid JSON? 

    if(type == 'i'){
        if(c == VALUE_SEPARATOR || c == END_ARRAY || c == END_OBJECT)
            return i;
        else
            return -1;
    }
    //by this point we know type should be a float
    int frac = c == DECIMALPOINT ? 1 : 0;
    if(!frac) return -1;
    i++;
    while((c = (*jsonSubString)[i]) != '\0' && c >= ZERO && c < NINE){
        i++;
    }
    if(c == VALUE_SEPARATOR || c == END_ARRAY || c == END_OBJECT){
        return i;
    }else if (c != 'e'){
        return -1;
    }

    int eNegative = 0;
    if((c = (*jsonSubString)[i]) != '\0' && (c == MINUS || c == PLUS)){
        i++;
        eNegative = c == MINUS;
    }else{
        if(c == VALUE_SEPARATOR || c == END_ARRAY || c == END_OBJECT){
            return -1;
        }
        if(c < ZERO || c > NINE)
            return -1;
        //c is a digit
    }
    i++;
    while((c = *(++(*jsonSubString))) != '\0' && c >= ZERO && c < NINE){
        i++;
    }
    
    return 0;
}

int parseKeyName(char **jsonSubString, char **templateSubString){
    return 0;
}
/*
    UNTESTED
*/
int parseSingleton(char **jsonSubString){
    stripLeadingWhiteSpace(jsonSubString);
    char c = **jsonSubString;
    switch(c){
        case 'n':
            return equalsParse(jsonSubString, "ull", 3);
        case 'f':
            return equalsParse(jsonSubString, "alse", 4);
        case 't':
            return equalsParse(jsonSubString, "rue", 3);
        case '"':
            return !(parseUntilControlCharacter(jsonSubString, '"') > 0);
        default:
            return parseNumber(jsonSubString, 'i'); //currently hardcoded, need templtae
    }
}

/*
    Parse name
    parse name separator
    parse value

    UNTESTED
*/
int parseMember(char **jsonSubString, char **templateSubString){
    int status;
    if(!(status = (parseKeyName(jsonSubString, templateSubString) == VALID)))
        if(!(status = (stripWSUntilControlCharacter(jsonSubString, NAME_SEPARATOR) == VALID)))
            status = (parseJSONVal(jsonSubString, templateSubString) == VALID);
    return status;
}

/*
    GIVEN: 
    
        an unvalidated json string contained with root

        a struct that characterizes expected schema of json
                
    
    WILL:
        Parse jsonText and make sure 2 conditions are met:
            1. Valid JSON text as specified by RFC-8259
            2. JSON text conforms to custom structure provided by *t

    insignificant whitespace allowed before or after any of the 6 structural characters

    UNTESTED

*/
int parseJSONVal(char **jsonSubString, char **templateSubString){
    int statusCode = VALID;
    stripLeadingWhiteSpace(jsonSubString);
    stripLeadingWhiteSpace(templateSubString);
    char c = **jsonSubString;
    if(c != '\0'){
        if(c == BEGIN_OBJECT){
            /*
                object = begin-object [ member *( value-separator member ) ] end-object 

                member = string name-separator value
            */
            while(!(statusCode = parseMember(jsonSubString, templateSubString))) //this logic traverses and validates the whole tree
                ;
            return statusCode;

        }else if(c == BEGIN_ARRAY){
            /*
                array = begin-array [ value *( value-separator value ) ] end-array
            */
            int statusCode;
            while(!(statusCode = parseJSONVal(jsonSubString, templateSubString))) //this logic traverses and validates the whole tree.
                ;
            return statusCode;
        }else{
            return parseSingleton(jsonSubString);
        }
    }
    return statusCode;
}

/*
  * UNTESTED

    want to parse jsonDataText and templateText in tandem. 
    jsonDataText: "ws*?Vws*?"
    templateText: "(num|string|object|array|null|true|false)"
*/
int parseA(char **jsonDataText, char **templateText){
    if(**jsonDataText == '\0')
        return ERROR_EMPTY_TEXT;
    return parseJSONVal(jsonDataText, templateText);
}



