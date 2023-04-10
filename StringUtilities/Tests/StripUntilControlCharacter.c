#include <stdio.h>
#include "../StringUtils.h"

int simpleTest(){
    char *test = "  \n\t{hello}";
    int numStripped = stripUntilControlCharacter(test, '{');
    return !(numStripped == 4 && equals(test + 4, "{hello}"));
}

int errorTest(){
    char *test = "  \n\thello}";
    int numStripped = stripUntilControlCharacter(test, '{');
    return !(numStripped == -1);
}

int StripUntilControlCharacter(int argc, char **argv){
    return simpleTest() || errorTest();
}