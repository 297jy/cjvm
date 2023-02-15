#include <iostream>
#include "common.h"

using namespace std;

int main(int nArgc, char *argv[]) {

    vector<string> & res = split_string("test;test1;test2", ";");
    for (int i = 0; i < res.size(); ++i) {
        cout<< res[i]<< endl;
    }
    cout<<sizeof res<<endl;
    cout<<sizeof &res<<endl;
    delete &res;
    return 0;
}
