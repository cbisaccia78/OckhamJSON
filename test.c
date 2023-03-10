#include <stdio.h>
#include "JSON.h"
#include "StringUtils.h"

#define LINELIMIT 4096

struct Holder {
    char *key;
    char *val;
};
typedef struct Holder Holder;

int main(int argc, char **argv){
    int c, i = 0;
    char buffer[LINELIMIT];
    getLine(buffer, LINELIMIT);
    squeezeWhiteSpace(buffer, 0, QUOTATIONMARK);
    parse(buffer);
}