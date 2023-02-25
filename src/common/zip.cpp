//
// Created by Administrator on 2023/2/17.
//

#include "file.h"
#include "zip.h"
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

Zip::Zip(const std::string &path) {
    originPath = path;
    time_t myt = time(nullptr);
    tempPath =
            TEMP_DIRECTORY + to_string(myt) + FILE_PATH_SEPARATOR + get_no_suffix_filename(path) + FILE_PATH_SEPARATOR;
    fileList = nullptr;
}

vector<filesystem::path> *Zip::readFileList() {
    if (fileList == nullptr) {
        decompression();
        vector<filesystem::path> &files = read_all_file(tempPath);
        fileList = &files;
    }

    auto *filenames = new vector<filesystem::path>();
    for (const auto &file: *fileList) {
        filenames->push_back(file);
    }
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

void Zip::refresh() {
    delete fileList;
    fileList = nullptr;
}

string Zip::getTempPath() {
    return tempPath;
}

Zip::~Zip() {
    remove_directory(tempPath);
    refresh();
}

bool Zip::decompression() {
    create_directory(tempPath);
    string cmd = "tar -zxf " + originPath + " -C " + tempPath;
    cout << "cmd: " + cmd << endl;
    return ::system(cmd.c_str()) == 0;
}