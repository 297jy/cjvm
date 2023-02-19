//
// Created by Administrator on 2023/2/15.
//


#include "classpath.h"
#include <vector>
#include "str.h"

using namespace std;

CompositeEntry::CompositeEntry(const string &pathList) {
    entries = new std::vector<ClassPathEntry*>();
    vector<string> &paths = split_string(pathList, PATH_LIST_SEPARATOR);
    for (const string &p: paths) {
        ClassPathEntry *e = newClasspathEntry(p);
        entries->push_back(e);
    }
    delete &paths;
}

char *CompositeEntry::readClass(const std::string &className) {

}

std::string CompositeEntry::toString() {

}

CompositeEntry::~CompositeEntry() {
    delete entries;
}