#ifndef JSON_h
#define JSON_h

#include <stdio.h>

typedef enum { 
    BEGIN_ARRAY = 0x5B,
    BEGIN_OBJECT = 0x7B,
} StructuralOpener;

typedef enum { 
    END_ARRAY = 0x5D,
    END_OBJECT = 0x7D, 
} StructuralCloser;

typedef enum {
    NAME_SEPARATOR = 0x3A,
    VALUE_SEPARATOR = 0x2C
} Separator;

typedef enum {
    SPACE = 0x20,
    TAB = 0x09,
    NEWLINE = 0x0A,
    CARRIAGE_RETURN = 0x0D
} WhiteSpace; 

typedef enum { OBJECT, ARRAY, NUMBER, STRING, TRUE, FALSE, NULLY, INVALID } ValueType;

char DECIMALPOINT = 0x2E;
char PLUS = 0x2B;
char MINUS = 0x2D;

typedef enum {
    ZERO = 0x30,
    ONE = 0x31,
    TWO = 0x32,
    THREE = 0x33,
    FOUR = 0x34,
    FIVE = 0x35,
    SIX = 0x36,
    SEVEN = 0x37,
    EIGHT = 0x38,
    NINE = 0x39
} DIGIT;

char QUOTATIONMARK = 0x22;
char REVERSESOLIDUS = 0x5C;
const struct {
    int start;
    int endl;
} CTRLCHARRANGE = {0x0, 0x1F};

struct JSONValue {
    ValueType t;
};
typedef struct JSONValue JSONValue;

/*
    
    
*/

/*
    Given: 
    an unvalidated json string
        and
    a struct that characterizes expected schema of json
        and
    struct that will hold the parsed data
    parse transforms a JSON text into a struct representation. 
   
    DOES accept all texts that conform to the JSON grammar.
    DOES NOT accept non-JSON forms or extensions.
    DOES NOT set limits on the size of texts that it can parse
    DOES NOT set limits on the maximum depth of nesting.  
    DOES NOT set limits on the range and precision of numbers.  
    DOES NOT set limits on the length of strings
    DOES set limits on character content of strings
*/
int parse(char *json){
    /*
        Strip all leading ws

        Grab first token (t)

        t is ?
            [
            {
            QUOTATIONMARK
        Yes?
            exit(-1)

        stack.push(t)
        while(!stack.empty()){
            StructuralOpener opener
            switch(opener = stack.peek(0))
                {
                    case(StructuralOpener):
                        StructuralCloser closer = getCloser(opener)
                        strip leading ws
                        BEGINOBJECT?

                        BEGINARRAY?
                        break;
                    case(StructuralCloser):
                        break;
                    case(QUOTATIONMARK):
                        stack.peek(1) != QUOTATIONMARK?
                            do
                        else
                            do    
                    case(Separator):
                        break;
                    default:
                        !valid token based on context?
                            exit(-1)
                        do
                        break;
                }
            
                
                    
        }
    */
   printf("%s\n", json);
}

/*
    generate produces strictly conforming JSON text from a struct.  
*/
int generate(){

}


#endif