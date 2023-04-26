#include <stdio.h>
#include "JSON.h"


int EqualsParse(int argc, char **argv){
    char **jsonText = "{\"hello\": null, \"hello\": null, \"hello\": null}";
    char *nully = "null \t}";
    char *truey = "true \t}";
    char *falsey = "false \t}";
    return !(equalsParse(jsonText, nully) && equalsParse(jsonText, truey) && equalsParse(jsonText, falsey));
}