#include <stdio.h>
#include "../StringUtils.h"



int Equals(int argc, int **argv){
    char *hello = "hello";
    char *null = "";
    return !(equals(null, null));
}