//
// Created by Administrator on 2023/2/16.
//

#include "file.h"
#include <fstream>
#include <filesystem>
#include "str.h"
#include <stack>
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
    cout<<"remove_directory: "<<path<<endl;
    return std::filesystem::remove_all(path) > 0;
}

bool exist(const string &path, bool isDirectory) {
    std::error_code error;
    auto file_status = std::filesystem::status(path, error);
    if (error) {
        return false;
    }

    if (!std::filesystem::exists(file_status)) {
        return false;
    }
    return std::filesystem::is_directory(file_status) && isDirectory;
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

std::string join_path(const std::string &base, std::initializer_list<const std::string> paths) {
    filesystem::path p(base);
    for (const auto &path: paths) {
        p = p / path;
    }
    return p.string();
}

/**
 * 读取目录的文件名列表
 * @return
 */
vector<filesystem::path> &read_all_file(const string &path) {
    auto *fileList = new vector<filesystem::path>();
    filesystem::path p(path);
    if (!filesystem::exists(path)) {
        cout << "file path not exits: " << path << endl;
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
    filesystem::path p(path);
    stack<filesystem::path> needCreateStack;
    while (!filesystem::exists(p)) {
        needCreateStack.push(p);
        p = p.parent_path();
    }
    while (!needCreateStack.empty()) {
        filesystem::create_directory(needCreateStack.top());
        needCreateStack.pop();
    }
    cout<<"create_directory: "<< path<<endl;
    return true;
}

string get_dir(const string &path) {
    filesystem::path p(path);
    return p.parent_path().string();
}
