#ifndef TestUtils_h
#define TestUtils_h

#include <stdlib.h>

#define Case char**

struct CaseList {
    int numCases;
    Case *cases;
};
typedef struct CaseList CaseList;

CaseList* initTestData(int numCases, Case *cases){
    CaseList *data = (CaseList *)malloc(sizeof(CaseList) + numCases*sizeof(Case));
    data->numCases = numCases;
    data->cases = cases;
    return data;
}

#endif