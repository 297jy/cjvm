//
// Created by Administrator on 2023/2/17.
//

#include "file.h"
#include "zip.h"
#include <iostream>
#include <algorithm>

using namespace std;

Zip::Zip(const std::string &path) {
    originPath = path;
    tempPath = TEMP_DIRECTORY + get_no_suffix_filename(path) + FILE_PATH_SEPARATOR;
    fileList = nullptr;
}

vector<filesystem::path> *Zip::readFileList() {
    if (fileList == nullptr) {
        decompression();
    }

    auto *filenames = new vector<filesystem::path>();
    vector<filesystem::path> &files = read_all_file(tempPath);
    for (const auto &file: files) {
        filenames->push_back(file);
    }
    fileList = &files;
    return filenames;
}

string Zip::readFile(const std::string &relativeFilePath) {
    if (fileList == nullptr) {
        readFileList();
    }

    for (const auto &file: *fileList) {
        string path = file.string();
        if (file.string().find(relativeFilePath) != -1) {
            return read_file(file.string());
        }
    }
    return "";
}

bool Zip::decompression() {
    create_directory(tempPath);
    string cmd = "tar -zxf " + originPath + " -C " + tempPath;
    cout << "cmd: " + cmd << endl;
    return ::system(cmd.c_str()) == 0;
}