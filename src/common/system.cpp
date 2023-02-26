//
// Created by Administrator on 2023/2/26.
//

#include "system.h"

using namespace std;


std::string getEnv(const std::string &varName) {
    char *p;
    if ((p = getenv(varName.c_str()))) {
        std::stringstream ss;
        ss << p;
        std::string res;
        ss >> res;
        delete p;
        return res;
    }
    return "";
}