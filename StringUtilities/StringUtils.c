#include <string.h>
#include <stdio.h>
#include "StringUtils.h"

/*
int main(){
  char *jsonText = "  \t\n  \"hello\"\n";
  printf("%d\n", stripWSUntilControlCharacter(jsonText, '"'));
}
*/

/*
    UNTESTED
*/

int contains(char **strArray, char *str){
    return 0;
}

/*
    TESTED
        SPACESPACETABTABSPACESPACEhello\n -> 6 hello
*/
int stripLeadingWhiteSpace(char str[]){
    
    char c;
    int i = 0;

    while((c = str[i++]) != '\0'){
        if(!(c == SPACE || c == TAB || c == NEWLINE || c == CARRIAGE_RETURN))
            break;

    }
    return i-1; //number of ws removed
}

/*
    UNTESTED
*/
int stripUntilControlCharacter(char str[], char controlCharacter){
    char c;
    int i = 0;
    while((c = str[i++]) != '\0' && c != controlCharacter)
        ;
    
    if(c != controlCharacter)
        return -1;
    return i-1; //number of ws removed
}

/*
    TESTED
        SPACESPACETABTABSPACESPACE"hello" expected 6 result 6
        SPACESPACETABTABSPACESPACEhello" expected 6 result 6
        SPACESPACETABTABSPACESPACEhello expected -1 result -1
*/

int stripWSUntilControlCharacter(char str[], char controlCharacter){
    char c;
    int i, j;
    i = j = 0;
    int encounteredNonWS = 0;
    while((c = str[i++]) != '\0' && c != controlCharacter){
         if(!(c == SPACE || c == TAB || c == NEWLINE || c == CARRIAGE_RETURN)){
            encounteredNonWS = 1;
        }else if(!encounteredNonWS){
            j++;
        }
    }
    
    if(c != controlCharacter)
        return -1;
    
    
    return j; //number of ws removed
}

/*
    UNTESTED
*/

int stripValue(char str[]){
    int i,j;
    i = j = 0;

    return j; 
}

/*
    Tested
        SPACESPACETABSPACESPACE"hello"\n
*/
void getLine(char buffer[], int limit){
    int c, i = 0;
    while((c = getchar()) != EOF && c != '\n'){
        buffer[i++] = c;
    }
    buffer[i] = '\0';
}

/*
    TESTED
        { "test" : "test" }
*/
void getAll(char buffer[], int limit){
    int c, i = 0;
    while((c = getchar()) != '|'){
        buffer[i++] = c;
    }
    buffer[i] = '\0';
}


