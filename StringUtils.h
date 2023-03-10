#ifndef StringUtils_h
#define StringUtils_h

#include <string.h>
#include <stdio.h>
#include "JSON.h"

/*
    UNTESTED
*/
int squeezeWhiteSpace(char str[], int startIndex, char controlChar){
    if(startIndex < 0 || startIndex > strlen(str))
        return -1;
    char c;
    int i,j;
    i = j = startIndex;
    while((c = str[startIndex++]) != '\0' && c != controlChar){
        if(c != SPACE && c != TAB && c != NEWLINE && c != CARRIAGE_RETURN)
            str[j++] = c;

    }
    str[j] = '\0';
    return i - j - startIndex;
}

/*
    UNTESTED
*/
int getLine(char buffer[], int limit){
    int c, i = 0;
    while((c = getchar()) != EOF && c != '\n'){
        buffer[i++] = c;
    }
    buffer[i] = '\0';
}


#endif