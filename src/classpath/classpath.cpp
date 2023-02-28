//
// Created by Administrator on 2023/2/15.
//

#include "classpath.h"
#include "str.h"
#include "file.h"
#include "system.h"
#include <iostream>

using namespace std;

ClassPathEntry *newCompositeEntry(const string &pathList) {
    ClassPathEntry *entry = new CompositeEntry();
    entry->init(pathList);
    return entry;
}

ClassPathEntry *newJarEntry(const string &pathList) {
    ClassPathEntry *entry = new JarEntry();
    entry->init(pathList);
    return entry;
}

ClassPathEntry *newWildcardEntry(const string &pathList) {
    ClassPathEntry *entry = new WildcardEntry();
    entry->init(pathList);
    return entry;
}

ClassPathEntry *newDirEntry(const string &pathList) {
    ClassPathEntry *entry = new DirEntry();
    entry->init(pathList);
    return entry;
}

ClassPathEntry *newClasspathEntry(const string &path) {
    if (contain(path, PATH_LIST_SEPARATOR)) {
        return newCompositeEntry(path);
    }
    if (ends_with(path, "*")) {
        return newWildcardEntry(path);
    }
    if (ends_with(path, ".jar") || ends_with(path, ".JAR")
        || ends_with(path, ".zip") || ends_with(path, ".ZIP")) {
        return newJarEntry(path);
    }
    return newDirEntry(path);
}

ClassPath *parse(const std::string &jreOption, const std::string &cpOption) {
    auto *path = new ClassPath();
    path->parseBootAndExtClasspath(jreOption);
    path->parseUserClasspath(cpOption);
    return path;
}

string ClassPath::readClass(const std::string &className) {
    string fullClassName = className + ".class";
    string data;
    // 依次从根目录、扩展目录、用户目录查找要加载的类的字节码文件
    ClassPathEntry *entries[] = {bootClasspath, extClasspath, userClasspath};
    for (auto e: entries) {
        data = e->readClass(fullClassName);
        if (!data.empty()) {
            return data;
        }
    }
    return "";
}

void ClassPath::parseBootAndExtClasspath(const std::string &jreOption) {
    string jreDir = get_jre_dir(jreOption);
    string jreLibPath = join_path(jreDir, {"lib", "*"});
    bootClasspath = newWildcardEntry(jreLibPath);
    cout << "jreLibPath: " << jreLibPath << endl;

    string jreExtPath = join_path(jreDir, {"lib", "ext", "*"});
    extClasspath = newWildcardEntry(jreExtPath);
    cout << "jreExtPath: " << jreExtPath << endl;

}

void ClassPath::parseUserClasspath(const std::string &cpOption) {
    if (cpOption.empty()) {
        userClasspath = newClasspathEntry(".");
    } else {
        userClasspath = newClasspathEntry(cpOption);
    }
}

ClassPath::~ClassPath() {
    cout<<"~ClassPath"<<endl;
    delete userClasspath;
    delete bootClasspath;
    delete extClasspath;
}

std::string get_jre_dir(const std::string &jreOption) {
    if (!jreOption.empty() && exist(jreOption, true)) {
        return jreOption;
    }
    if (exist("./jre", true)) {
        return "./jre";
    }
    string javaHome = getEnv("JAVA_HOME");
    if (!javaHome.empty()) {
        return join_path(javaHome, {"jre"});
    }

    throw "Can not find jre folder!";
}


