#include <stdio.h>
#include "../StringUtils.h"

int Equals(int argc, int **argv){
    char *hello = "hello";
    char *hello2 = "hello";
    return !equals(hello, hello2);
}