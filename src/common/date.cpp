//
// Created by Administrator on 2023/3/3.
//


#include <chrono>
#include "date.h"
using namespace std;

long long get_timestamp() {
    chrono::milliseconds ms = std::chrono::duration_cast< std::chrono::milliseconds >(
            std::chrono::system_clock::now().time_since_epoch()
    );
    return ms.count();
}