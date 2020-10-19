#include <dummy_class.h>

#include <gtest/gtest.h>

TEST(SerializationTest, SaveAndRestore) {
    auto object = makeTestObject();
    std::string path = "test_dummyobject.dat";
    serialize(object, path);
    auto restored = deserialize(path);
    ASSERT_TRUE(object == restored);
}

TEST(SerializationTest, DifferentObjects) {
    auto object = makeTestObject();
    DummyClass wrong;
    ASSERT_FALSE(object == wrong);
}
