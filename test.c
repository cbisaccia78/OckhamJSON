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