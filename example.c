#include <stdio.h>
#include "JSON.h"
#include "StringUtils.h"

#define L1_CACHE_SIZE 128000 //specific to my development machine, don't read into this

/*
 * bool parse(nAryTreeNode *root, DeSerializationTemplate *t);
 * void _deserializeFromTemplate(nAryTreeNode *root, DeSerializationTemplate *t, Storage *s);
 * void deserializeFromTemplate(char *jsonText, DeSerializationTemplate *t, Storage *s);
*/

int main(int argc, char **argv){
    printf("Version Major: %d\nVersion Minor: %d\n", OckhamJSON_VERSION_MAJOR, OckhamJSON_VERSION_MINOR );
    char dataBuffer[L1_CACHE_SIZE/4]; //try to allow room for storage / deserialization template in cache as well if possible. 
    char templateBuffer[L1_CACHE_SIZE/4];
    getAll(dataBuffer, L1_CACHE_SIZE/4);
    getAll(templateBuffer, L1_CACHE_SIZE/4);

    //at this point we've got cachesize/2 left for the storage structure
    int res = parseA(dataBuffer, templateBuffer);
    printf("%s", res == 0 ? "true" : "false");
}