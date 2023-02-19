//
// Created by Administrator on 2023/2/16.
//

#include "file.h"
#include <fstream>
#include <filesystem>
#include "str.h"
#include <iostream>

using namespace std;


string read_file(const string &path) {
    ifstream inf(path, ios::in | ios::binary);
    stringstream in;
    in << inf.rdbuf();
    string content = in.str();
    inf.close();
    return content;
}


bool is_dir(const string &path) {
    if (path.empty()) {
        return false;
    }

    filesystem::path p(path);
    filesystem::directory_entry entry(p);
    return entry.status().type() == filesystem::file_type::directory;
}

bool remove_file(const string &path) {
    return std::filesystem::remove(path);
}

bool remove_directory(const string &path) {
    return std::filesystem::remove_all(path) > 0;
}

void get_all_file(const filesystem::path &p, vector<filesystem::path> &fileList) {
    filesystem::directory_entry entry(p);
    if (entry.status().type() != filesystem::file_type::directory) {
        fileList.push_back(p);
        return;
    }
    filesystem::directory_iterator list(p);
    for (auto &it: list) {
        get_all_file(it.path(), fileList);
    }
}

/**
 * 读取目录的文件名列表
 * @return
 */
vector<filesystem::path> &read_all_file(const string &path) {
    auto *fileList = new vector<filesystem::path>();
    filesystem::path p(path);
    if (!filesystem::exists(path)) {
        return *fileList;
    }
    get_all_file(p, *fileList);
    return *fileList;
}

string get_no_suffix_filename(const string &path) {
    filesystem::path p(path);
    string filename = p.filename().string();
    vector<string> &names = split_string(filename, ".");
    string noSuffixName = names[0];
    delete &names;
    return noSuffixName;
}

bool create_directory(const string &path) {
    if (filesystem::exists(path)) {
        return true;
    }
    return filesystem::create_directory(path);
}

string get_dir(const string &path) {
    if (is_dir(path)) {
        return path;
    }
    int n = path.find_last_of(FILE_PATH_SEPARATOR);
    return path.substr(0, n + 1);
}
