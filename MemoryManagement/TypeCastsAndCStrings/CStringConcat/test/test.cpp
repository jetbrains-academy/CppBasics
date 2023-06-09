#include <gtest/gtest.h>

#include <cstring>

#include "testing.hpp"

char* concat(const char* fst, const char* snd);

namespace expected {
    char* concat(const char* fst, const char* snd) {
        size_t fst_len = strlen(fst);
        size_t len = fst_len + strlen(snd);
        char* res = (char*) malloc(len + 1);
        strcpy(res, fst);
        strcpy(res + fst_len, snd);
        res[len] = '\0';
        return res;
    }
}

std::string error_msg(const char* fst, const char* snd,
                      const char* expected, const char* actual) {
    std::ostringstream stream;
    stream << "Test data:"             << "\n"
           << "  fst = "   << fst      << "\n"
           << "  snd = "   << snd      << "\n";
    stream << "Expected: " << expected << "\n";
    stream << "Actual: "   << actual   << "\n";
    return stream.str();
}

TEST(concatTest, HelloWorldTest) {
    const char* fst = "Hello ";
    const char* snd = "World!";
    const char* expected = "Hello World!";
    auto actual = unique_Cstr(concat(fst, snd));

    ASSERT_STREQ(expected, actual.get())
        << error_msg(fst, snd, expected, actual.get());
}

TEST(concatTest, EmptyTest) {
    const char* str = "qwerty";
    const char* emp = "";
    const char* expected = "qwerty";
    auto actual0 = unique_Cstr(concat(emp, emp));
    auto actual1 = unique_Cstr(concat(str, emp));
    auto actual2 = unique_Cstr(concat(emp, str));

    ASSERT_STREQ(emp, actual0.get())
        << error_msg(emp, emp, emp, actual0.get());

    ASSERT_STREQ(expected, actual1.get())
        << error_msg(str, emp, expected, actual1.get());

    ASSERT_STREQ(expected, actual2.get())
        << error_msg(emp, str, expected, actual2.get());
}

TEST(concatTest, RandomTest) {
    for (int i = 0; i < N_ITER; ++i) {
        auto fst = random_Cstr();
        auto snd = random_Cstr();
        auto expected = unique_Cstr(expected::concat(fst.get(), snd.get()));
        auto actual = unique_Cstr(concat(fst.get(), snd.get()));

        ASSERT_STREQ(expected.get(), actual.get())
            << error_msg(fst.get(), snd.get(), expected.get(), actual.get());
    }
}