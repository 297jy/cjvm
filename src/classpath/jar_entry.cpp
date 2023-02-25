//
// Created by Administrator on 2023/2/25.
//

#include "classpath.h"

using namespace std;

void JarEntry::init(const string &pathList) {
    jarZip = new Zip(pathList);
}


string JarEntry::readClass(const std::string &className) {
    if (jarZip == nullptr) {
        return "";
    }
    string content = jarZip->readFile(className);
    if (content.empty()) {
        return "";
    }
    return content;
}

std::string JarEntry::toString() {
    if (jarZip == nullptr) {
        return "";
    }
    return jarZip->getTempPath();
}

JarEntry::~JarEntry() {
    delete jarZip;
}