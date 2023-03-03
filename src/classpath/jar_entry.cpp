//
// Created by Administrator on 2023/2/25.
//

#include "classpath.h"
#include <iostream>
using namespace std;

void JarEntry::init(const string &pathList) {
    jarZip = new Jar(pathList);
}


vector<char> JarEntry::readClass(const std::string &className) {
    if (jarZip == nullptr) {
        return {};
    }
    return jarZip->readFile(className);
}

std::string JarEntry::toString() {
    if (jarZip == nullptr) {
        return "";
    }
    return jarZip->getTempPath();
}

JarEntry::~JarEntry() {
    cout<<"~JarEntry"<<endl;
    delete jarZip;
}