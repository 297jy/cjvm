//
// Created by Administrator on 2023/2/15.
//

#include "classpath.h"
#include "str.h"
using namespace std;


ClassPathEntry *newClasspathEntry(const string &path) {
    if (contain(path, PATH_LIST_SEPARATOR)) {
        return new CompositeEntry(path);
    }
    return nullptr;
}