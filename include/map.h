//
// Created by Administrator on 2023/2/14.
//

#ifndef CJVM_MAP_H
#define CJVM_MAP_H

template<class T, class V>
class Map {
public:
    class Entry {
    public:
        T key;
        V value;
    };

private:
    Entry *data;
};

#endif //CJVM_MAP_H
