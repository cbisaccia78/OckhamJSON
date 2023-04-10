#include <stdio.h>
#include "../StringUtils.h"

int StripUntilControlCharacter(int argc, char **argv){
    char *test = "  \n\t{hello}";
    int numStripped = stripUntilControlCharacter(test, '{');
    return !(numStripped == 4 && equals(test + 4, "{hello}"));
}