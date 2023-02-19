//
// Created by Administrator on 2023/2/14.
//

#ifndef CJVM_CLASSPATH_H
#define CJVM_CLASSPATH_H

#include <string>
#include <vector>

const std::string PATH_LIST_SEPARATOR = ";";

class ClassPathEntry {
public:
    virtual char *readClass(const std::string& className) = 0;

    virtual std::string toString() = 0;
};

class ClassPath {
public:

    void parseBootAndExtClasspath(const std::string &jreOption);

    void parseUserClasspath(const std::string &cpOption);

private:
    ClassPathEntry *bootClasspath;
    ClassPathEntry *extClasspath;
    ClassPathEntry *userClasspath;
};

ClassPath *parse(const std::string &jreOption, const std::string &cpOption);

ClassPathEntry *newClasspathEntry(const std::string &path);

class CompositeEntry : public ClassPathEntry {
public:

    explicit CompositeEntry(const std::string& pathList);

    ~CompositeEntry();

    char *readClass(const std::string& className) override;

    std::string toString() override;

private:
    std::vector<ClassPathEntry*> *entries;
};

#endif //CJVM_CLASSPATH_H
