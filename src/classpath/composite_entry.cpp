//
// Created by Administrator on 2023/2/15.
//


#include "classpath.h"
#include <vector>

class CompositeEntry: ClassPathEntry {
public:
    char* readClassPathEntry(string pathList) override {
        //pathList.
        return nullptr;
    }
private:
    vector<ClassPathEntry*>* items;
};