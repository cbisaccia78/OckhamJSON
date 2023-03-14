#ifndef JSON_h
#define JSON_h

#include <stdio.h>
#include <stdbool.h>
#include "StringUtils.h"
#include "ArrayUtils.h"

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

//node declaration

struct nAryTreeNode {
    char *jsonText;
    char *keyName;
    char *value; // should not be set until leaf node
    ValueType valueType;
    bool validSoFar;
    struct nAryTreeNode *parent;
    struct nAryTreeNode *firstChild; 
};
typedef struct nAryTreeNode nAryTreeNode;

//node validation functions

bool nodeIsLeaf(nAryTreeNode *node){
    return true;
}

//node modification functions

int createRootValue(nAryTreeNode *root, char *rootJsonText){
    root->jsonText = rootJsonText;
    root->validSoFar = false;
    root->keyName = NULL;
    root->value = NULL;
    root->valueType = INVALID;
    root->parent = NULL;
    root->firstChild = NULL;
}


int parseKeyOffset(nAryTreeNode *node){
    node->jsonText = (node->jsonText + stripLeadingWS(node->jsonText)); // pointer arithmetic
}

int parseKey(nAryTreeNode *node){
    //do parse key
    char *key = "test";
    node->keyName = key;
}

int parseValueOffset(nAryTreeNode *node){
    node->jsonText = (node->jsonText + stripValue(node->jsonText)); // pointer arithmetic
}

int parseValue(nAryTreeNode *node){
    //do parse value
}



struct DeSerializationTemplate {
    char *key;
    ValueType valueType;

    struct DeSerializationTemplate *parent;
    struct DeSerializationTemplate *firstChild;
};
typedef struct DeSerializationTemplate DeSerializationTemplate;

DeSerializationTemplate* getChildFromKey(DeSerializationTemplate *node, char *key){
    DeSerializationTemplate *child;

    return child;
}

char** enumerateChildKeys(DeSerializationTemplate *node){
    DeSerializationTemplate *child = node->firstChild;
    int i = 0;
    char **childKeys;
    while(child){
        
    }
    return childKeys;
}

struct Storage {

};
typedef struct Storage Storage;

/*
    GIVEN: 
    
        an unvalidated json string contained with root

        a struct that characterizes expected schema of json
                
        struct that will hold the parsed data
    
    WILL:
        Parse jsonText and make sure it's valid

        Populate Storage s with the jsonText, using the storage
        rules provided by DeSerializationTemplate t
   
*/
bool parse(nAryTreeNode *root, DeSerializationTemplate *t){
    if(nodeIsLeaf(root)){
        parseKeyOffset(root);
        if(root->validSoFar){
            parseKey(root);
            if(root->validSoFar){
                if(root->keyName == t->key){
                    parseValueOffset(root);
                    if(root->validSoFar){
                        parseValue(root);
                        if(root->valueType != INVALID && root->valueType == t->valueType){
                            return true;
                        }
                    }
                }
                
            }
        }
        return false;
    }
    bool validChildren = true;
    nAryTreeNode *child = root->firstChild;
    while(child){
        if(!contains(enumerateChildKeys(t), child->keyName))
            return false;
        validChildren = validChildren && parse(child, getChildFromKey(t, child->keyName));
    }
    return validChildren;
}

void _deserializeFromTemplate(nAryTreeNode *root, DeSerializationTemplate *t, Storage *s){

}

/*
    DOES accept all texts that conform to the JSON grammar.
    
    DOES NOT accept non-JSON forms or extensions.
    DOES NOT set limits on the size of texts that it can parse
    DOES NOT set limits on the maximum depth of nesting.  
    DOES NOT set limits on the range and precision of numbers.  
    DOES NOT set limits on the length of strings
    DOES set limits on character content of strings
*/

void deserializeFromTemplate(char *jsonText, DeSerializationTemplate *t, Storage *s){
    //Create root node to represent top level JSON value
    nAryTreeNode *rootJSONValue;
    createRootValue(rootJSONValue, jsonText);

    //Parse JSON text using the help of the tree nodes
    bool parsedSuccessfully = parse(rootJSONValue, t);

    if(parsedSuccessfully){
        _deserializeFromTemplate(rootJSONValue, t, s);
    }
}

/*
    generate produces strictly conforming JSON text from a struct.  
*/
int generate(){

}


#endif