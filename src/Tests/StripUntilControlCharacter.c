#include <stdio.h>
#include "../StringUtils.h"

int simpleStripTest(){
    char *test = "  \n\t{hello}";
    int numStripped = stripUntilControlCharacter(&test, '{');
    return !(numStripped == 4 && equals(test, "{hello}"));
}

int errorStripTest(){
    char *test = "  \n\thello}";
    int numStripped = stripUntilControlCharacter(&test, '{');
    return !(numStripped == -1);
}

int StripUntilControlCharacter(int argc, char **argv){
    return simpleStripTest() || errorStripTest();
}