//
// Created by Administrator on 2023/2/15.
//

#include "str.h"

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

bool startsWith(const std::string &str, const std::string &prefix) {
    return (str.rfind(prefix, 0) == 0);
}

bool endsWith(const std::string &str, const std::string &suffix) {
    if (suffix.length() > str.length()) { return false; }

    return (str.rfind(suffix) == (str.length() - suffix.length()));
}
