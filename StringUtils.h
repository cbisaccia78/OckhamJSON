#ifndef StringUtils_h
#define StringUtils_h

#include <string.h>

/*
    UNTESTED
*/
int squeeze(char str[], int startIndex, char removalChar, char controlChar){
    if(startIndex < 0 || startIndex > strlen(str))
        return -1;

    char c;
    int i,j;
    i = j = startIndex;
    while((c = str[startIndex++]) != '\0' && c != controlChar){
        if(c != removalChar)
            str[j++] = c;

    }
    str[j] = '\0';
    return i - j - startIndex;
}

#endif