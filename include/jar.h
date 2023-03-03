//
// Created by Administrator on 2023/2/16.
//

#ifndef CJVM_JAR_H
#define CJVM_JAR_H

#include <string>
#include <vector>
#include <filesystem>
#include <map>

class Jar {
public:
    explicit Jar(const std::string& path);
    void refresh();
    std::vector<char> readFile(const std::string& relativeFilePath);
    //std::vector<std::filesystem::path>* readFileList();
    std::string getTempPath();
    ~Jar();
protected:
    bool decompression();
private:
    std::string originPath;
    std::vector<std::pair<std::string, int>> classNameIndexs;
    std::map<std::string , int> classNameIndexMap;

};
#endif //CJVM_JAR_H
