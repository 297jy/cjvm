#include <iostream>
#include <cstdlib>
#include "classpath.h"
#include "str.h"
#include "file.h"
#include "zip.h"

using namespace std;

int main(int nArgc, char *argv[]) {
    string path = "C:/project/cjvm/temp";
    //cout << create_directory(path) << endl;
    //cout << remove_directory("C:/project/cjvm/test.txt") << endl;

    //cout << get_no_suffix_filename("/test/src.zip") << endl;
    //Zip zip("C:/project/cjvm/temp/charsets.jar");
    //vector<std::filesystem::path> *list = zip.readFileList();
    //cout << "文件总个数: " << list->size() << endl;
    //cout << zip.readFile(R"(org\xml\sax\SAXNotSupportedException.java)") << endl;

    //char *p;
    //if ((p = getenv("JAVA_HOME"))) {
    //cout << "JAVA_HOME: " << p << endl;
    //}

    //cout<<contain("test", "t")<<endl;
    ClassPath *p = parse("", "");
    cout << "class: "<<p->readClass("java\\lang\\String") << endl;
    delete p;
    return 0;
}
