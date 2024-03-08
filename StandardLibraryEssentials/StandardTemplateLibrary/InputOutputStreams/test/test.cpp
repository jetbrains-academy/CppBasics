#include <gtest/gtest.h>
#include <sstream>

bool isNumber(const std::string& token);
void streamReader();

TEST(streamReaderTester, SimpleTest) {
    std::string testInput = "Hello\n123\nend\n";

    std::istringstream in(testInput);
    std::streambuf* cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());

    std::stringstream out;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());

    streamReader();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    std::string expectedOutput = "Got string: Hello\nGot number: 123.000\n";
    ASSERT_EQ(out.str(), expectedOutput);
}

TEST(streamReaderTester, IsNumberTest) {
    ASSERT_TRUE(isNumber("123"));
    ASSERT_TRUE(isNumber("123.456"));
    ASSERT_TRUE(isNumber("-123"));
    ASSERT_TRUE(isNumber("-123.456"));
    ASSERT_FALSE(isNumber("123."));
    ASSERT_FALSE(isNumber(".123"));
    ASSERT_FALSE(isNumber("123.456.789"));
    ASSERT_FALSE(isNumber("123-456"));
    ASSERT_FALSE(isNumber("123-"));
    ASSERT_FALSE(isNumber("-123-"));
    ASSERT_FALSE(isNumber("-123-456"));
    ASSERT_FALSE(isNumber("-.123"));
    ASSERT_FALSE(isNumber("-"));
    ASSERT_FALSE(isNumber("."));
    ASSERT_FALSE(isNumber(""));
    ASSERT_FALSE(isNumber("-."));
    ASSERT_FALSE(isNumber("a"));
    ASSERT_FALSE(isNumber("a123"));
}

TEST(streamReaderTester, BiggerInput) {
    std::string testInput = "Hello\n"
                            "-123.8956\n"
                            "1aa5\n"
                            "BeepBoop\n"
                            "0\n"
                            "end\n";
    std::istringstream in(testInput);
    std::streambuf* cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());

    std::stringstream out;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());

    streamReader();

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    std::string expectedOutput = "Got string: Hello\n"
                                "Got number: -123.896\n"
                                "Got string: 1aa5\n"
                                "Got string: BeepBoop\n"
                                "Got number: 0.000\n";
    ASSERT_EQ(out.str(), expectedOutput);
}