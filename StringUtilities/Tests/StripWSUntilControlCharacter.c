#include <stdio.h>
#include "../StringUtils.h"

int simpleWSTest(){
    char *test = "  \n\t{hello}";
    int numStripped = stripWSUntilControlCharacter(test, '{');
    return !(numStripped == 4 && equals(test + 4, "{hello}"));
}

int errorWSTest1(){
    char *test = "  \n\thello}";
    int numStripped = stripWSUntilControlCharacter(test, '{');
    return !(numStripped == -1);
}

int errorWSTest2(){
    char *test = "  R\n\t{hello}";
    int numStripped = stripWSUntilControlCharacter(test, '{');
    return !(numStripped == -1);
}

int StripWSUntilControlCharacter(int argc, int **argv){
    return simpleWSTest() || errorWSTest1() || errorWSTest2();
}