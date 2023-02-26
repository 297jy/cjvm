//
// Created by Administrator on 2023/2/25.
//

#include "classpath.h"
#include <vector>
#include "str.h"
#include "file.h"

using namespace std;

void WildcardEntry::init(const std::string &path) {
    string baseDir = get_dir(path);
    // 读取目录下的所有文件
    vector<filesystem::path> &files = read_all_file(path);
    for (auto &file: files) {
        // 将所有jar包都进行解压
        if (ends_with(file.filename().string(), ".jar") || ends_with(file.filename().string(), ".JAR")) {
            addEntry(newJarEntry(file.string()));
        }
    }
    delete &files;
}
