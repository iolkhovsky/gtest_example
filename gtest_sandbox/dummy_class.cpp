#include "dummy_class.h"

void DummyClass::SetMap(const std::map<std::string, int>& i_map) {
    _map = i_map;
}

void DummyClass::SetVec(const std::vector<int>& i_vec) {
    _vec = i_vec;
}

int DummyClass::Serialize(std::ostream& os) const {
    int sz = sizeof(DummyClass);
    os.write(reinterpret_cast<const char*>(this), sz);
    return sz;
}

DummyClass& DummyClass::Deserialize(std::istream& is) {
    is.read(reinterpret_cast<char*>(this), sizeof(DummyClass));
    return *this;
}

int serialize(const DummyClass& obj, const std::string& path) {
    std::ofstream os(path, std::ios::binary);
    int sz = obj.Serialize(os);
    os.close();
    return sz;
}

DummyClass deserialize(const std::string& path) {
    std::ifstream is(path, std::ios::binary);
    DummyClass out;
    out.Deserialize(is);
    is.close();
    return out;
}

DummyClass makeTestObject() {
    DummyClass object;
    std::map<std::string, int> tmap;
    tmap["first"] = 1;
    tmap["second"] = 2;
    std::vector<int> tvec = {0, 5, 3, 17, 28, 75, 100};
    object.SetMap(tmap);
    object.SetVec(tvec);
    return object;
}

std::ostream& operator<<(std::ostream& os, const DummyClass& obj) {
    os << "DummyObject content:" << std::endl;
    os << obj.GetMap()
       << obj.GetVec();
    return os;
}
