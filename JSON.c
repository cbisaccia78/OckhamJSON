#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "JSON.h"
#include "StringUtils.h"
//#include "utils/ArrayUtils.h"

/*
  * UNTESTED
*/
bool nodeIsLeaf(nAryTreeNode *node){
    return true;
}

//node modification functions

/*
  * UNTESTED
*/
void createRootValue(nAryTreeNode *root, char *rootJsonText){
    root->jsonText = rootJsonText;
    root->validSoFar = false;
    root->keyName = NULL;
    root->value = NULL;
    root->valueType = INVALID;
    root->parent = NULL;
    root->prevSibling = NULL;
    root->nextSibling = NULL;
    root->firstChild = NULL;
}

/*
  * UNTESTED
*/
void parseKeyOffset(nAryTreeNode *node){
    int offset = stripWSUntilControlCharacter(node->jsonText, QUOTATIONMARK);
    if(offset < 0){
        node->validSoFar = false;
        return;
    }
    node->jsonText = node->jsonText + offset; // returns a pointer to stripped string
}

/*
  * UNTESTED
*/
void parseKey(nAryTreeNode *node){
    //do parse key
    node->keyName = "";
}

/*
  * UNTESTED
*/
void parseValueOffset(nAryTreeNode *node){
    node->jsonText = (node->jsonText + stripWSUntilControlCharacter(node->jsonText, VALUE_SEPARATOR)); // pointer arithmetic
}

/*
  * UNTESTED
*/
void parseValue(nAryTreeNode *node){
    //do parse value
}

DeSerializationTemplate* getChildFromKey(DeSerializationTemplate *node, char *key){
    DeSerializationTemplate *child = malloc(sizeof(DeSerializationTemplate));
    return child;
}

/*
  * UNTESTED
*/
char** enumerateChildKeys(DeSerializationTemplate *node){
    DeSerializationTemplate *child = node->firstChild;
    //int i = 0;
    char **childKeys = malloc(sizeof(char *)); //THIS IS WRONG, JUST GETTING TO COMPILE
    while(child){
        
    }
    return childKeys;
}

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
        if(!contains(enumerateChildKeys(t), child->keyName, t->numChildren))
            return false;
        validChildren = validChildren && parse(child, getChildFromKey(t, child->keyName));
    }
    return validChildren;
}

/*
  * UNTESTED
*/
int parseA(char *jsonDataText, char *jsonTemplateText,){
    return 0;
}

/*
  * UNTESTED
*/
int parsePopulate(char *jsonDataText, char *jsonTemplateText,, Storage *s){
    return 0;
}

/*
  * UNTESTED
*/
void _deserializeFromTemplate(nAryTreeNode *root, DeSerializationTemplate *t, Storage *s){

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
void deserializeFromTemplate(char *jsonText, DeSerializationTemplate *t, Storage *s){
    //Create root node to represent top level JSON value
    nAryTreeNode *rootJSONValue = malloc(sizeof (nAryTreeNode));
    createRootValue(rootJSONValue, jsonText);

    //Parse JSON text using the help of the tree nodes
    bool parsedSuccessfully = parse(rootJSONValue, t);

    if(parsedSuccessfully){
        _deserializeFromTemplate(rootJSONValue, t, s);
    }
}

/*
  * UNTESTED
*/
int deserializeFromArrayTemplate(char *jsonText, char **arrayTemplate, Storage *s){
    //int numFields = parsePopulate(jsonText, arrayTemplate, s); 
    return 0;
}
