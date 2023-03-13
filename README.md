_________________________________________________________________________________________
# Ockham JSON

# Purpose: 
    C Libary providing the following functionality: 
        - User controlled serialization/de-serialization of JSON text data

# Usage:
    
    /*
        First: 

            Create a custom (Template) for your particular use case:

            (Templates) are C structs which contain the expected structure of 
            your incoming JSON data.

            Structure it like this:

                struct Template {

                };
                typedef struct Template Template;
        
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

                int deserializeFromTemplate(char *jsonText, Template t, Storage s);

            This function attempts to populate the Storage struct with parsed JSON text data
            in the manner specified by the Template. 

            It will return 0 on failure and 1 on success.

    */

    //Actual example: 

    Template myCustomTemplate = { . . . };
    Storage myCustomStorage = { . . . };
    deserializeFromTemplate(char *jsonText, Template t, Storage s);
            
        
    


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