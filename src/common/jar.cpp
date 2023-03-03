//
// Created by Administrator on 2023/2/17.
//

#include "jar.h"
#include <iostream>
#include <algorithm>
#include "byte.h"
#include "unzip.h"

using namespace std;

Jar::Jar(const std::string &path) {
    originPath = path;

    // 提前缓存类名和索引的映射关系，优化性能
    HZIP hz = OpenZip(path.c_str(), 0);
    ZIPENTRY ze;
    GetZipItem(hz, -1, &ze);
    int numitems = ze.index;
    for (int i = 0; i < numitems; i++) {
        GetZipItem(hz, i, &ze);
        if (ze.unc_size > 0) {
            string name = ze.name;
            classNameIndexs.emplace_back(ze.name, i);
            classNameIndexMap[ze.name] = i + 1;
        }
        //cout<<"filename:"<<ze.name<<"index:"<<i<<endl;
    }
    CloseZip(hz);
}

vector<char> Jar::readFile(const std::string &relativeFilePath) {
    /**
    HZIP hz = OpenZip(originPath.c_str(), 0);
    int zi;
    ZIPENTRY ze;
    FindZipItem(hz, relativeFilePath.c_str(), false, &zi, &ze);
    string res;
    if(ze.unc_size != 0) {
        char *ibuf = new char[ze.unc_size];
        UnzipItem(hz, zi, ibuf, ze.unc_size);
        for (int i = 0; i < ze.unc_size; i++) {
            cout<<(int)ibuf[i]<<" ";
        }
        cout<<endl;
        res = ibuf;
    }else{
        res="";
    }
    CloseZip(hz);
    return res;**/
    int index = classNameIndexMap[relativeFilePath];
    if(index == 0) {
        return {};
    }
    index--;
    HZIP hz = OpenZip(originPath.c_str(), 0);
    ZIPENTRY ze;
    GetZipItem(hz, index, &ze);
    char *ibuf = new char[ze.unc_size];
    UnzipItem(hz, index, ibuf, ze.unc_size);
    CloseZip(hz);
    vector<char> res = to_bytes(ibuf, ze.unc_size);
    delete[] ibuf;
    return res;
}

void Jar::refresh() {
}

string Jar::getTempPath() {
    return originPath;
}

Jar::~Jar() {
    //remove_directory(tempPath);
    refresh();
}

bool Jar::decompression() {
    //cout << "create directory: " << create_directory(tempPath) << endl;
    //string cmd = "tar -zxf \"" + originPath + "\" -C \"" + tempPath + "\"";
    //cout << "cmd: " + cmd << endl;
    //return ::system(cmd.c_str()) == 0;
    return true;
}