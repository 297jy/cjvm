//
// Created by Administrator on 2023/2/14.
//

#ifndef CJVM_CLASSPATH_H
#define CJVM_CLASSPATH_H

#include <string>

using namespace std;

const string PATH_LIST_SEPARATOR = ";";

class ClassPathEntry {
public:
    virtual char *readClassPathEntry(string pathList) = 0;

    virtual string toString() = 0;

    ClassPathEntry* newEntry(string path);

};

#endif //CJVM_CLASSPATH_H
