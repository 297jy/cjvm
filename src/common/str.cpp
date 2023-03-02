//
// Created by Administrator on 2023/2/15.
//

#include "str.h"
#include <iostream>

using namespace std;

vector<string> &split_string(const string &str, const string &splits) {
    auto *v = new vector<string>();
    if (str.empty()) {
        return *v;
    }

    string strs = str + splits;
    size_t pos = strs.find(splits);
    unsigned long long step = splits.size();
    while (pos != string::npos) {
        string temp = strs.substr(0, pos);
        v->push_back(temp);
        strs = strs.substr(pos + step, strs.size());
        pos = strs.find(splits);
    }

    return *v;
}

int *build_kmp_next(const string &str) {
    int *next = new int[str.size()];
    next[0] = 0;
    int temp = 0;
    int now = 1;
    while (now < str.size()) {
        if (str[now] == str[temp]) {
            next[now] = temp + 1;
            now++;
            temp++;
        } else {
            if (temp > 0) {
                temp = next[temp - 1];
            } else {
                next[now] = 0;
                now++;
            }
        }
    }
    return next;
}

int search_str(const std::string &str, const std::string &target, const int *next) {
    bool freeFlag = false;
    if(next == nullptr) {
        freeFlag = true;
        next = build_kmp_next(target);
    }
    int pos = 0;
    int tar = 0;
    int res = -1;
    while (pos < str.size()) {
        if (str[pos] == target[tar]) {
            pos++;
            tar++;
        } else {
            if (tar > 0) {
                tar = next[tar - 1];
            } else {
                pos++;
            }
        }
        if (tar == target.size()) {
            res = pos - tar;
            break;
        }
    }
    if(freeFlag) {
        delete[] next;
    }
    return res;
}

int search_str(const std::string &str, const std::string &target) {
    return search_str(str, target, nullptr);
}

string replace_all(const string &str, const string &oldVal, const string &nowVal) {
    if (oldVal == nowVal) {
        return str;
    }
    string newStr = str;
    cout << newStr << " " << oldVal << " " << nowVal << endl;
    int *next = build_kmp_next(nowVal);
    while (true) {
        int pos = search_str(newStr, oldVal, next);
        if (pos == -1) {
            delete[] next;
            return newStr;
        }
        newStr = newStr.substr(0, pos) + nowVal +
                 newStr.substr(pos + oldVal.size(), newStr.size() - pos - oldVal.size());
    }
}

bool contain(const string &str, const string &substr) {
    return str.find(substr) != -1;
}

string join_string(std::vector<std::string> &src, const std::string &splits) {
    string res;
    if (src.empty()) return res;

    auto it = src.begin();
    res += *it;
    for (it++; it != src.end(); it++) {
        res += splits;
        res += *it;
    }
    return res;
}

bool starts_with(const std::string &str, const std::string &prefix) {
    return (str.rfind(prefix, 0) == 0);
}

bool ends_with(const std::string &str, const std::string &suffix) {
    if (suffix.length() > str.length()) { return false; }

    return (str.rfind(suffix) == (str.length() - suffix.length()));
}
