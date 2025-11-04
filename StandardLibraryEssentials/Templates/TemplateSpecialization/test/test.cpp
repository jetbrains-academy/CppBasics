#include <gtest/gtest.h>
#include "../include/DataPair.hpp"


TEST(DataPairPrintTest, PrintIntString) {
    DataPair<int, std::string> pair{10, "Hello"};
    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    printDataPair(pair);
    std::cout.rdbuf(sbuf);
    ASSERT_EQ(buffer.str(), "DataPair: 10, Hello\n");
}

TEST(DataPairPrintTest, PrintDoubleDouble) {
    DataPair<double, double> pair{20.22, 30.33};
    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    printDataPair(pair);
    std::cout.rdbuf(sbuf);
    ASSERT_EQ(buffer.str(), "double DataPair: 20.22, 30.33\n");
}

TEST(DataPairPrintTest, PrintIntInt) {
    DataPair<int, int> pair{10, 20};
    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    printDataPair(pair);
    std::cout.rdbuf(sbuf);
    ASSERT_EQ(buffer.str(), "int DataPair: 10, 20\n");
}

TEST(DataPairPrintTest, PrintStringString) {
    DataPair<std::string, std::string> pair{"Hello", "World"};
    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    printDataPair(pair);
    std::cout.rdbuf(sbuf);
    ASSERT_EQ(buffer.str(), "std::string DataPair: Hello, World\n");
}

TEST(DataPairPrintTest, PrintCharChar) {
    DataPair<char, char> pair{'a', 'b'};
    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    printDataPair(pair);
    std::cout.rdbuf(sbuf);
    ASSERT_EQ(buffer.str(), "DataPair: a, b\n");
}

TEST(DataPairPrintTest, PrintStringInt) {
    DataPair<std::string, int> pair{"Hello", 10};
    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    printDataPair(pair);
    std::cout.rdbuf(sbuf);
    ASSERT_EQ(buffer.str(), "DataPair: Hello, 10\n");
}

