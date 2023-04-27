#include <stdio.h>
#include "JSON.h"


int EqualsParse(int argc, char **argv){
    char **jsonText = "nulltruefalse";
    char *nully = "null";
    char *truey = "true";
    char *falsey = "false";
    return !(equalsParse(jsonText, nully, 4) && equalsParse(jsonText, truey, 4) && equalsParse(jsonText, falsey, 5));
}