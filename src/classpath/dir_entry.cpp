//
// Created by Administrator on 2023/2/25.
//

#include "classpath.h"
#include "file.h"

using namespace std;

void DirEntry::init(const std::string &path) {
    baseDir = path;
}

std::string DirEntry::readClass(const std::string &className) {
    string path = baseDir + FILE_PATH_SEPARATOR + className;
    return read_file(path);
}

std::string DirEntry::toString() {
    return baseDir;
}

