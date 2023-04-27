#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "JSON.h"
#include "StringUtils.h"
/*
    UNTESTED
*/
int equalsParse(char **jsonSubString, char *string, int length){
    int i = 0;
    while(**jsonSubString == string[i] && (i++ < length))
        jsonSubString++;
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
*/
int parseNumber(char **jsonSubString){
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
            return parseString(jsonSubString);
        default:
            return parseNumber(jsonSubString);
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

/*
  * UNTESTED
*/
int parsePopulate(char **jsonDataText, char **jsonTemplateText, Storage *s){
    return 0;
}

/*  
    Populate Storage s with the jsonText, using the storage
    rules provided by DeSerializationTemplate t

    DOES accept all texts that conform to the JSON grammar.
    
    DOES NOT accept non-JSON forms or extensions.
    DOES NOT set limits on the size of texts that it can parse
    DOES NOT set limits on the maximum depth of nesting.  
    DOES NOT set limits on the range and precision of numbers.  
    DOES NOT set limits on the length of strings
    DOES set limits on character content of strings

    
    UNTESTED

*/
void deserializeFromTemplate(char **jsonText, char **templateText, Storage *s){
    //Parse JSON text using the help of the tree nodes
    parsePopulate(jsonText, templateText, s);
}
