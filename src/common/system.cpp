//
// Created by Administrator on 2023/2/26.
//

#include "system.h"
#include <iostream>
using namespace std;


std::string getEnv(const std::string &varName) {
    char *p;
    if ((p = getenv(varName.c_str()))) {
        return p;
    }
    return "";
}