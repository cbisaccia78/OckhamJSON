# Ockham JSON
# Build Stats

[![pipeline status](https://gitlab.com/utilities6655811/OckhamJSON/badges/main/pipeline.svg)](https://gitlab.com)
[![coverage report](https://gitlab.com/utilities6655811/OckhamJSON/badges/main/coverage.svg)](https://gitlab.com)
# Description
**C library** for non-json experts to control the **serialization**/**deserialization** process
of **JSON** text data

I want to provide **clear control mechanisms** for users of the library to be able to 
**define structure and type of expected data**, and also **custom storage mechanisms** for after
the parsing process has completed successfully. 

# Usage:
    
    /*
        First: 

            Create a custom string template for your particular use case:

            (Templates) are strings which represent the expected structure of the incoming json data text

            Define one as follows:

            char *template = "{'field1': int, 'field2': string, 'field3': {'field4': true, 'field5': false', 'field6': null, 'field7': decimal}, 'field8': [int]}"

           
        Second: 
            
            Create custom (Storage) which implements your template
        
            (Storage) will be a struct that contains your JSON text data in the way 
            you need it to. 

            Structure it like this:

                struct Storage {

                };
                typedef struct Storage Storage;
        
        Third:
            
            Call the following function:

                void deserializeFromTemplate(char *jsonText, Template t, Storage s);

            This function attempts to populate the Storage struct with parsed JSON text data
            in the manner specified by the Template. 

            It will store error codes / meta info within the Storage struct

    */

    //Actual example: 

        #include <stdio.h>
        #include "JSON.h"
        #include "StringUtils.h"

        #define LINELIMIT 4096

        int main(int argc, char **argv){
            int c, i = 0;
            char jsonText[LINELIMIT];
            
            getAll(jsonText, LINELIMIT);

            DeSerializationTemplate *t;
            Storage *s;
            
            deserializeFromTemplate(jsonText, t, s);
        }
            
        
# A Brief Introduction to JSON (From [RFC-8259](https://www.rfc-editor.org/rfc/rfc8259)):
    
    JavaScript Object Notation (JSON) is a text format for the
    serialization of structured data.  It is derived from the object
    literals of JavaScript, as defined in the ECMAScript Programming
    Language Standard, Third Edition [ECMA-262].

    JSON can represent four primitive types (strings, numbers, booleans,
    and null) and two structured types (objects and arrays).

    A string is a sequence of zero or more Unicode characters [UNICODE].
    Note that this citation references the latest version of Unicode
    rather than a specific release.  It is not expected that future
    changes in the Unicode specification will impact the syntax of JSON.

    An object is an unordered collection of zero or more name/value
    pairs, where a name is a string and a value is a string, number,
    boolean, null, object, or array.

    An array is an ordered sequence of zero or more values.

    The terms "object" and "array" come from the conventions of
    JavaScript.

    JSON's design goals were for it to be minimal, portable, textual, and
    a subset of JavaScript.

    Future Changes:
        ECMA and IETF will work together to reconcile any differences between
        RFC8259 and [ECMA-404]. 

# History

    I was looking to work with some JSON text streams in C. 

    However, I couldn't find a JSON library in C that was palletable at a first glance.

    I started to build one myself with the goal of abstracting away the nuances of JSON structure
    from the concerns of the user. 
