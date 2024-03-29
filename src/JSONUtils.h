#ifndef JSON_h
#define JSON_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StringUtils.h"
//#include "utils/ArrayUtils.h"


#define BEGIN_ARRAY  0x5B
#define BEGIN_OBJECT  0x7B

#define END_ARRAY  0x5D
#define END_OBJECT  0x7D

#define NAME_SEPARATOR  0x3A
#define VALUE_SEPARATOR  0x2C


typedef enum { OBJECT, ARRAY, NUMBER, STRING, TRUE, FALSE, NULLY, INVALID } ValueType;

#define DECIMALPOINT 0x2E
#define PLUS 0x2B
#define MINUS 0x2D
#define QUOTATIONMARK 0x22
#define REVERSESOLIDUS 0x5C
#define CTRLCHARSTART 0x0
#define CTRLCHAREND 0x1F

/*
    Error codes
*/
#define VALID 0
#define ERROR_EMPTY_TEXT 1
#define ERROR_INVALID_MEMBER 2


typedef enum {
    ZERO = 0x30,
    ONE = 0x31,
    TWO = 0x32,
    THREE = 0x33,
    FOUR = 0x34,
    FIVE = 0x35,
    SIX = 0x36,
    SEVEN = 0x37,
    EIGHT = 0x38,
    NINE = 0x39
} DIGIT;


int equalsParse(char **jsonSubString, char *string, int length);
int parseString(char **jsonSubString);
int parseNumber(char **jsonSubString, char type);
int parseKeyName(char **jsonSubString, char **templateSubString);
int parseSingleton(char **jsonSubString);
int parseMember(char **jsonSubString, char **templateSubString);
int parseJSONVal(char **jsonSubString, char **templateSubString);
int parseA(char **jsonSubString, char **templateSubString);


#endif
