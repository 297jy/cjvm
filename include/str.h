//
// Created by Administrator on 2023/2/16.
//

#ifndef CJVM_STR_H
#define CJVM_STR_H

#include <string>
#include <vector>

std::vector<std::string> &split_string(const std::string &str, const std::string &splits);

std::string join_string(std::vector<std::string> &src, const std::string &splits);

bool contain(const std::string &str, const std::string &substr);

bool startsWith(const std::string &str, const std::string &prefix);

bool endsWith(const std::string &str, const std::string &suffix);

#endif //CJVM_STR_H
