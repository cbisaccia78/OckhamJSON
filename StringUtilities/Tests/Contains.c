#include <stdio.h>
#include "../StringUtils.h"

int Contains(int argc, char **argv){
    char *helloVariants[3] = {"hi", "ni hao", "hello"};
    return !(contains(helloVariants, "hello", 3));
}