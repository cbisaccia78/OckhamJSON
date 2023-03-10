#include <stdio.h>
#include "JSON.h"

struct Holder {
    char *key;
    char *val;
};
typedef struct Holder Holder;

int main(int argc, char **argv){
    int c, i = 0;
    char buffer[4096];
    Holder *simple = malloc()
    while((c = getchar()) != EOF){
        buffer[i++] = c;
    }

    parse(buffer);
}