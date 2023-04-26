#ifndef StringUtils_h
#define StringUtils_h

typedef enum {
    SPACE = 0x20,
    TAB = 0x09,
    NEWLINE = 0x0A,
    CARRIAGE_RETURN = 0x0D
} WhiteSpace; 

int equals(char *str1, char *str2);
int copy(char str[], char buffer[], int length);
int contains(char **strArray, char *str, int length);
int stripLeadingWhiteSpace(char str[]);
int stripUntilControlCharacter(char str[], char controlCharacter);
int stripWSUntilControlCharacter(char str[], char controlCharacter);
void getLine(char buffer[], int limit);
void getAll(char buffer[], int limit);

#endif
