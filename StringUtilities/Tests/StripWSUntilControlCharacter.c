#include <stdio.h>
#include "../StringUtils.h"

int simpleTest(){
    char *test = "  \n\t{hello}";
    int numStripped = stripWSUntilControlCharacter(test, '{');
    return !(numStripped == 4 && equals(test + 4, "{hello}"));
}

int errorTest1(){
    char *test = "  \n\t{hello}";
    int numStripped = stripWSUntilControlCharacter(test, '{');
    return !(numStripped == -1);
}

int errorTest2(){
    char *test = "  R\n\t{hello}";
    int numStripped = stripWSUntilControlCharacter(test, '{');
    return !(numStripped == -1);
}

int StripWSUntilControlCharacter(int argc, int **argv){
    return simpleTest() || errorTest1() || errorTest2();
}