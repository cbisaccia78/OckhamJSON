#include <string.h>
#include <stdio.h>
#include "StringUtils.h"

/*int main(){
    char *test = "  \n\t{hello}";
    int numStripped = stripWSUntilControlCharacter(test, '{');
    return !(numStripped == 4 && equals(test + 4, "{hello}"));
}*/

/*
    TESTED
*/
int equals(char *str1, char *str2){
    
    int char1, char2, i = 0;
    while((char1 = str1[i]) != '\0' && (char2 = str2[i++]) != '\0'){
        if(char1 != char2){
            return 0;
        }
    }
    char2 = str2[i];
    return char1 == char2; // this is testing for null byte == null byte
}

/*
    TESTED

*/
int contains(char **strArray, char *str, int length){
    char *nextStr;
    while(length >= 0 && !equals(strArray[--length], str))
        ;
    return length >= 0;
}

/*
    UNTESTED
*/
int copy(char str[], char buffer[], int length){
    char c;
    for(int i = 0; i < length && !(c = '\0'); buffer[i] = str[i++])
        ;
    
}

/*
    UNTESTED
*/
int stripLeadingWhiteSpace(char **str){
    
    char c;
    char *base = *str;

    while((c = **str) != '\0'){
        if(!(c == SPACE || c == TAB || c == NEWLINE || c == CARRIAGE_RETURN))
            break;
        (*str)++;
    }
    return *str - base; //number of ws removed
}

/*
    Untested
*/
int stripUntilControlCharacter(char **str, char controlCharacter){
    char c;
    char *base = *str;

    while((c = **str) != '\0' && c != controlCharacter)
        (*str)++;
    
    if(c != controlCharacter)
        return -1;
    return *str - base; //number of ws removed
}

/*
    Untested
*/

int stripWSUntilControlCharacter(char **str, char controlCharacter){
    char c;
    char *base = *str;
    while((c = **str) != '\0' && c != controlCharacter){
         if(!(c == SPACE || c == TAB || c == NEWLINE || c == CARRIAGE_RETURN))
            return -1;
        (*str)++;
    }
    
    if(c != controlCharacter)
        return -1;

    return *str - base; 
}

/*
    UNTESTED
*/
void getLine(char buffer[], int limit){
    int c, i = 0;
    while((c = getchar()) != EOF && c != '\n'){
        buffer[i++] = c;
    }
    buffer[i] = '\0';
}

/*
    UNTESTED
*/
void getAll(char buffer[], int limit){
    int c, i = 0;
    while((c = getchar()) != '|'){
        buffer[i++] = c;
    }
    buffer[i] = '\0';
}


