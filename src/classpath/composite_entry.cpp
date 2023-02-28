//
// Created by Administrator on 2023/2/15.
//


#include <vector>
#include <iostream>
#include "str.h"
#include "classpath.h"
using namespace std;

void CompositeEntry::init(const string &pathList) {
    entries->clear();
    vector<string> &paths = split_string(pathList, PATH_LIST_SEPARATOR);
    for (const string &p: paths) {
        ClassPathEntry *e = newClasspathEntry(p);
        addEntry(e);
    }
    delete &paths;
}

void CompositeEntry::addEntry(ClassPathEntry *entry) {
    entries->push_back(entry);
}

string CompositeEntry::readClass(const std::string &className) {
    cout<<className<<endl;
    for (ClassPathEntry *e: *entries) {
        string data = e->readClass(className);
        if (!data.empty()) {
            return data;
        }
    }
    return "";
}

std::string CompositeEntry::toString() {
    if (entries->empty()) {
        return "";
    }
    vector<string> src(entries->size());
    for (ClassPathEntry *e: *entries) {
        string s = e->toString();
        src.push_back(s);
    }

    return join_string(src, PATH_LIST_SEPARATOR);
}

CompositeEntry::~CompositeEntry() {
    cout<<"~CompositeEntry"<<endl;
    for(auto* e: *entries){
        delete e;
    }
    delete entries;
}