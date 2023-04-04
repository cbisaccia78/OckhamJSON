#include <stdio.h>
#include <stdlib.h>
#include "../StringUtils.h"
#include "TestUtils.h"



int Equals(int argc, int **argv){
    CaseList *testData;
    Case equality = {"hello", "hello"};
    Case inequality = {"hello", "hellos"};
    Case nullEquality = {"", ""};
    Case nullInequality = {"", "hello"};
    Case cases[4] = {equality, inequality, nullEquality, nullInequality};
    initTestData(testData, 4, cases);
    int passed = 0;
    for(int i = 0; i < testData->numCases; i++){
        char **dataTuple = testData->cases[i].data;
        passed = passed && !equals(dataTuple[0], dataTuple[1]);
    }
    
    return passed;
}