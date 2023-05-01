#include <stdio.h>


int equalsParse(char **jsonSubString, char *string, int length){
    int i = 0;
    while(i < length && *(*jsonSubString)++ == string[i++])
        ;
    return i == length;
}

int EqualsParse(int argc, char **argv){
    char *jsonText = "nulltruefalse";
    char *nully = "null";
    char *truey = "true";
    char *falsey = "false";
    return !(equalsParse(&jsonText, nully, 4) && equalsParse(&jsonText, truey, 4) && equalsParse(&jsonText, falsey, 5));
}