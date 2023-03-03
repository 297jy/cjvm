#include <iostream>
#include <cstdlib>
#include "classpath.h"
#include "str.h"
#include "file.h"
#include "jar.h"
#include "unzip.h"
#include "date.h"

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
    //cout << replace_all("java.lang.string", "j", "j") << endl;
    //cout<<contain("test", "t")<<endl;
    ClassPath *p = parse("", "");
    p->readClass("java.lang.Object");
    long long oldTime = get_timestamp();
    p->readClass("java.lang.String");
    long long nowTime = get_timestamp();
    cout<<"now_date: "<< nowTime - oldTime<<endl;
    std::vector<char> data = p->readClass("java.lang.Object");
    if(!data.empty()){
        for(auto a: data) {
            cout<<((int)a+256)%256<<" ";
        }
        cout<<endl;
    }
    cout<<"size: "<<data.size()<<endl;
    //delete p;

    /**
    HZIP hz = OpenZip("C:\\Program Files\\Java\\jdk1.8.0_181\\jre\\lib\\javaws.jar", 0);
    ZIPENTRY ze;
    GetZipItem(hz, -1, &ze);
    int numitems = ze.index;
    cout << "numitems: " << numitems << endl;
    for (int i = 0; i < numitems; i++) {
        GetZipItem(hz, i, &ze);
        if(ze.unc_size > 0) {
            char *ibuf = new char[ze.unc_size];
            UnzipItem(hz, i, ibuf, ze.unc_size);
            //CloseZip(hz);

            for(int j=0;j<ze.unc_size;j++){
                cout<<ibuf[j]<<" ";
            }
            cout<<endl;
            cout << "testname: " << ibuf << endl;
            break;
        }
    }
    cout<<"yes"<<endl;**/
    return 0;
    //replace_all(className, ".", "\\");
}
