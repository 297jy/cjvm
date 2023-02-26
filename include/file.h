//
// Created by Administrator on 2023/2/16.
//

#ifndef CJVM_FILE_H
#define CJVM_FILE_H

#include <vector>
#include <string>
#include <filesystem>
#include <initializer_list>

const char FILE_PATH_SEPARATOR = '/';

const std::string TEMP_DIRECTORY = "C:/project/cjvm/temp/";

std::string get_no_suffix_filename(const std::string &path);

bool is_dir(const std::string &path);

std::string get_dir(const std::string &path);

bool create_directory(const std::string &path);

std::string read_file(const std::string &path);

std::vector<std::filesystem::path> &read_all_file(const std::string &path);

std::string join_path(const std::string &base, std::initializer_list<const std::string> paths);

bool remove_directory(const std::string &path);

bool remove_file(const std::string &path);

bool exist(const std::string &path, bool isDirectory);

#endif //CJVM_FILE_H
