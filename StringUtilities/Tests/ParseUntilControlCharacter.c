#include "../StringUtils.h"

int validParseUntilControlCharacter(){
    char *validString = "hello\"";
    return parseUntilControlCharacter(&validString, '"') == 5;
}

int error1ParseUntilControlCharacter(){
    char *errorString = "hello";
    return parseUntilControlCharacter(&errorString, '"') == -1;
}

int ParseUntilControlCharacter(int argc, char **argv){
    return !(validParseUntilControlCharacter() && error1ParseUntilControlCharacter());
}