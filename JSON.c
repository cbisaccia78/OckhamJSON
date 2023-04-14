#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "JSON.h"
#include "StringUtils.h"


/*
    GIVEN: 
    
        an unvalidated json string contained with root

        a struct that characterizes expected schema of json
                
    
    WILL:
        Parse jsonText and make sure 2 conditions are met:
            1. Valid JSON text as specified by RFC-8259
            2. JSON text conforms to custom structure provided by *t
    
    
    UNTESTED
*/

/*
    object = begin-object [ member *( value-separator member ) ] end-object

        member = string name-separator value

    array = begin-array [ value *( value-separator value ) ] end-array

    insignificant whitespace allowed before or after any of the 6 structural characters

*/
int parseJSONVal(char *jsonSubString, char *templateSubString){
    jsonSubString = jsonSubString + stripLeadingWhiteSpace(jsonSubString);
    templateSubString = templateSubString + stripLeadingWhiteSpace(templateSubString);
    char c;
    while((c = *jsonSubString) != '\0'){
        if(c == BEGIN_OBJECT){
            int valid = 1;
            int numWS = stripLeadingWhiteSpace(jsonSubString);
            if(numWS == -1){
                jsonSubString += numWS;
                parseName(jsonSubString);

            }
        }else if(c == BEGIN_ARRAY){
            int valid = 1;
        }else{
            return parseSingleton(jsonSubString, templateSubString)
        }
    }
    return 0;
}

/*
  * UNTESTED

    want to parse jsonDataText and templateText in tandem. 
    jsonDataText: "w*?Vws*"
    templateText: "(num|string|object|array|null|true|false)"
*/
int parseA(char *jsonDataText, char *templateText){
    if(jsonDataText[0] == '\0')
        return 1;
    return parseJSONVal(jsonDataText, templateText);
}

/*
  * UNTESTED
*/
int parsePopulate(char *jsonDataText, char *jsonTemplateText, Storage *s){
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
void deserializeFromTemplate(char *jsonText, char *templateText, Storage *s){
    //Parse JSON text using the help of the tree nodes
    parsePopulate(jsonText, templateText, s);
}
