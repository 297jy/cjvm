//
// Created by Administrator on 2023/2/14.
//

#ifndef CJVM_COMMON_H
#define CJVM_COMMON_H

#include <string>
#include <vector>

using namespace std;

typedef struct Pair {
    string key;
    string value;
} Pair;

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

#endif //CJVM_COMMON_H
