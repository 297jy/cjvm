//
// Created by Administrator on 2023/3/3.
//

#include "byte.h"

using namespace std;

vector<char> to_bytes(char *cs, unsigned long long len) {
    vector<char> bytes;
    for (int i = 0; i < len; i++) {
        bytes.push_back(cs[i]);
    }
    return bytes;
}