#include <stdio.h>
#include <stdlib.h>
#include "../StringUtils.h"
#include "TestUtils.h"

void initTestData(CaseList *data){
    data = malloc(sizeof(CaseList)*2);
    data->numCases = 2;
    data->cases
}

int Equals(int argc, int **argv){
    CaseList *testData;
    initTestData(testData);
    int passed = 0;
    for(int i = 0; i < testData->numCases; i++){
        char **dataTuple = testData->cases[i].data;
        passed = passed && !equals(dataTuple[0], dataTuple[1]);
    }
    
    return passed;
}