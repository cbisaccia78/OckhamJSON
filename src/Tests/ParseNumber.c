#include <stdio.h>
#include "JSONUtils.h"

int ParseNumber(int argc, char **argv){
    char *intNum = "1234";
    char *negativeInt = "-1234";
    char *floatNum = "1234.56";
    char *negativeFloatNum = "-1234.56";
    char *floatNumWithE = "1234.56e24";
    char *floatNumWithEPlus = "1234.56e+24";
    char *floatNumWithEMinus = "1234.56e-24";
    return !(parseNumber(&intNum, 'i') == 4);
}