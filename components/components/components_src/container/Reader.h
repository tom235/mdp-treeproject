#ifndef READER_H
#define READER_H
#include "OATree.h"
#include <string>
using namespace std;


class Reader{

public:
    static OATree<string>* readTree(char*);


};

#endif
