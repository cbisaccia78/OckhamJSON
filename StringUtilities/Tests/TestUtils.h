#ifndef TestUtils_h
#define TestUtils_h

struct Case {
    char *name;
    char **data;
};
typedef struct Case Case;

struct CaseList {
    int numCases;
    Case *cases;
};
typedef struct CaseList CaseList;

#endif