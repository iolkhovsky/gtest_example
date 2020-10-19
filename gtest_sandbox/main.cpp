#include <iostream>

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    std::cout << "Running unit-tests..." << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    int res = RUN_ALL_TESTS();
    std::cout << "Runnning main program..." << std::endl;

    return res;
}
