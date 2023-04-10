#ifndef TestUtils_h
#define TestUtils_h

#include <stdlib.h>

#define Case char**

struct CaseList {
    int numCases;
    Case *cases;
};
typedef struct CaseList CaseList;

void initTestData(CaseList *data, int numCases, Case *cases){
    data = malloc(sizeof(CaseList)*2);
    data->numCases = 2;
}

#endif