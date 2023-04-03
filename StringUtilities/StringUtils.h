#ifndef StringUtils_h
#define StringUtils_h



typedef enum {
    SPACE = 0x20,
    TAB = 0x09,
    NEWLINE = 0x0A,
    CARRIAGE_RETURN = 0x0D
} WhiteSpace; 

/*
  UNTESTED
*/

int contains(char **strArray, char *str);

/*
    TESTED
        SPACESPACETABTABSPACESPACEhello\n -> 6 hello
*/
int stripLeadingWhiteSpace(char str[]);

/*
    UNTESTED
*/
int stripUntilControlCharacter(char str[], char controlCharacter);

/*
    TESTED
        SPACESPACETABTABSPACESPACE"hello" expected 6 result 6
        SPACESPACETABTABSPACESPACEhello" expected 6 result 6
        SPACESPACETABTABSPACESPACEhello expected -1 result -1
*/

int stripWSUntilControlCharacter(char str[], char controlCharacter);

/*
    UNTESTED
*/

int stripValue(char str[]);

/*
    Tested
        SPACESPACETABSPACESPACE"hello"\n
*/
void getLine(char buffer[], int limit);

/*
    TESTED
        { "test" : "test" }
*/
void getAll(char buffer[], int limit);


#endif
