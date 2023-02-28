//
// Created by Administrator on 2023/2/14.
//

#ifndef CJVM_CLASSPATH_H
#define CJVM_CLASSPATH_H

#include <string>
#include <vector>
#include "zip.h"

const std::string PATH_LIST_SEPARATOR = ";";

class ClassPathEntry {
public:
    virtual void init(const std::string &path) = 0;

    virtual std::string readClass(const std::string &className) = 0;

    virtual std::string toString() = 0;

    virtual ~ClassPathEntry() = default;
};

class ClassPath {
public:

    std::string readClass(const std::string& className);

    void parseBootAndExtClasspath(const std::string &jreOption);

    void parseUserClasspath(const std::string &cpOption);

    ~ClassPath();
private:
    ClassPathEntry *bootClasspath;
    ClassPathEntry *extClasspath;
    ClassPathEntry *userClasspath;
};

ClassPath *parse(const std::string &jreOption, const std::string &cpOption);

std::string get_jre_dir(const std::string& jreOption);

ClassPathEntry *newClasspathEntry(const std::string &path);

class DirEntry : public ClassPathEntry {
public:

    void init(const std::string &path) override;

    std::string readClass(const std::string &className) override;

    std::string toString() override;

private:
    std::string baseDir;
};

class CompositeEntry : public ClassPathEntry {
public:

    void init(const std::string &path) override;

    std::string readClass(const std::string &className) override;

    std::string toString() override;

    void addEntry(ClassPathEntry *entry);

    ~CompositeEntry() override;

private:
    std::vector<ClassPathEntry *> *entries = new std::vector<ClassPathEntry *>;
};

class WildcardEntry : public CompositeEntry {

public:
    void init(const std::string &path) override;
};

class JarEntry : public ClassPathEntry {
public:

    void init(const std::string &path) override;

    std::string readClass(const std::string &className) override;

    std::string toString() override;

    ~JarEntry() override;

private:
    Zip *jarZip;
};

ClassPathEntry *newJarEntry(const std::string &pathList);

ClassPathEntry *newCompositeEntry(const std::string &pathList);

ClassPathEntry *newWildcardEntry(const std::string &pathList);

#endif //CJVM_CLASSPATH_H
