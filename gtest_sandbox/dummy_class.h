#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>


template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m) {
    os << "map: {";
    for (auto[k,v]: m) {
        os << "{" << k << ":" << v << "}, ";
    os << "}" << std::endl;
    }
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "vector [";
    for (auto e: v) {
        os << e << ", ";
    os << "]" << std::endl;
    }
    return os;
}


class DummyClass {
public:
    DummyClass() = default;
    void SetMap(const std::map<std::string, int>& i_map);
    std::map<std::string, int> GetMap() const {return _map;}
    void SetVec(const std::vector<int>& i_vec);
    std::vector<int> GetVec() const {return _vec;}

    bool operator==(const DummyClass& other) const {
        return (_map == other._map) &&
                (_vec == other._vec);
    }

    int Serialize(std::ostream& os) const;
    DummyClass& Deserialize(std::istream& is);
private:
    std::map<std::string, int> _map;
    std::vector<int> _vec;
};


std::ostream& operator<<(std::ostream& os, const DummyClass& obj);
int serialize(const DummyClass& obj, const std::string& path);
DummyClass deserialize(const std::string& path);
DummyClass makeTestObject();
