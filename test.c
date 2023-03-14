#include <stdio.h>
#include "JSON.h"
#include "StringUtils.h"

#define LINELIMIT 4096

int main(int argc, char **argv){
    /*
        int c, i = 0;
        char jsonText[LINELIMIT];
        
        getAll(jsonText, LINELIMIT);

        DeSerializationTemplate *t;
        Storage *s;
        
        deserializeFromTemplate(jsonText, t, s);
    */

    char *jsonText = "  \t\n  hello\n";
    //getLine(jsonText, LINELIMIT);
    printf("Echo: %s\n", jsonText);
    int wsStripped = stripWSUntilControlCharacter(jsonText, QUOTATIONMARK);
    printf("Number of white space parsed: %d\n", wsStripped);
    printf("Result: %s\n", jsonText + wsStripped);
}