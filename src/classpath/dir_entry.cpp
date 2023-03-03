//
// Created by Administrator on 2023/2/25.
//

#include "classpath.h"
#include "file.h"
#include "byte.h"
#include <iostream>
using namespace std;

void DirEntry::init(const std::string &path) {
    baseDir = path;
}

vector<char> DirEntry::readClass(const std::string &className) {
    string path = baseDir + FILE_PATH_SEPARATOR + className;
    cout<<"dirClass: "<< path<<endl;
    string res = read_file(path);
    return to_bytes(res.data(), res.length());
}

std::string DirEntry::toString() {
    return baseDir;
}

