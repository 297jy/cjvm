//
// Created by Administrator on 2023/2/16.
//

#ifndef CJVM_ZIP_H
#define CJVM_ZIP_H

#include <string>
#include <vector>
#include <filesystem>

class Zip {
public:
    Zip(const std::string& path);
    std::string readFile(const std::string& relativeFilePath);
    std::vector<std::filesystem::path>* readFileList();
protected:
    bool decompression();
private:
    std::string originPath;
    std::string tempPath;
    const std::vector<std::filesystem::path> *fileList;
};
#endif //CJVM_ZIP_H
