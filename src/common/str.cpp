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