#include <stdio.h>
#include "../../../JSON.h" //this is machine dependent, need a better solution

int ParseNumber(int argc, char **argv){
    char *intNum = "1234";
    char *negativeInt = "-1234";
    char *floatNum = "1234.56";
    char *negativeFloatNum = "-1234.56";
    char *floatNumWithE = "1234.56e24";
    char *floatNumWithE+ = "1234.56e+24";
    char *floatNumWithE- = "1234.56e-24";
    return !(parseNumber(&intNum, 'i') == 4)
}