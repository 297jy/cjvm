//
// Created by Administrator on 2023/2/15.
//

#include "classpath.h"
#include "str.h"

using namespace std;

ClassPathEntry *newCompositeEntry(const string &pathList) {
    ClassPathEntry *entry = new CompositeEntry();
    entry->init(pathList);
    return entry;
}

ClassPathEntry *newJarEntry(const string &pathList) {
    ClassPathEntry *entry = new JarEntry();
    entry->init(pathList);
    return entry;
}

ClassPathEntry *newClasspathEntry(const string &path) {
    if (contain(path, PATH_LIST_SEPARATOR)) {
        return newCompositeEntry(path);
    }
    return nullptr;
}