//
// Created by Administrator on 2023/2/16.
//

#ifndef CJVM_FILE_H
#define CJVM_FILE_H

#include <vector>
#include <string>
#include <filesystem>

const char FILE_PATH_SEPARATOR = '/';

const std::string TEMP_DIRECTORY = "C:/project/cjvm/temp/";

std::string get_no_suffix_filename(const std::string &path);

bool is_dir(const std::string &path);

std::string get_dir(const std::string &path);

bool create_directory(const std::string &path);

std::string read_file(const std::string &path);

std::vector<std::filesystem::path> &read_all_file(const std::string &path);

bool remove_directory(const std::string &path);

bool remove_file(const std::string &path);

#endif //CJVM_FILE_H
