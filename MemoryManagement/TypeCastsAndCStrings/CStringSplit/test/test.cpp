#include <gtest/gtest.h>

#include <cstring>

#include "testing.hpp"

size_t split(const char* str, const char* seps, char**& res);

namespace expected {
    size_t split(const char* str, const char* seps, char**& res) {
        // firstly we calculate the number of substrings
        size_t size = 0;
        const char* p = str;
        while (*p) {
            p += strspn(p, seps);
            p = strpbrk(p, seps);
            size++;
        }
        // now that we know the number of substrings,
        // we can allocate sufficient amount of memory
        res = (char**) malloc(size * sizeof(char*));
        // finally, we copy the substrings
        p = str;
        const char* q = p;
        for (size_t i = 0; i < size; ++i) {
            p += strspn(p, seps);
            q = strpbrk(p, seps);
            size_t len = q - p;
            res[i] = (char*) malloc(len + 1);
            strncpy(res[i], p, len);
            res[i][len] = '\0';
            p = q;
        }
        return size;
    }
}

struct Cleanup {
    char** p  = nullptr;
    size_t sz = 0;

    Cleanup(char** p, size_t sz):
        p(p), sz(sz)
    {}

    ~Cleanup() {
        if (!p)
            return;
        for (size_t i = 0; i < sz; ++i) {
            free(p[i]);
        }
        free(p);
    }
};

template <typename T>
using unique_Cptr = std::unique_ptr<T, free_deleter>;

std::string error_msg(const char* str, const char* seps,
                      const char** expected, size_t expected_size,
                      const char** actual, size_t actual_size) {
    std::ostringstream stream;

    stream << "Test data:"             << std::endl
           << "  str  = "   << str     << std::endl
           << "  seps = "   << seps    << std::endl;

    stream << "Expected: "                   << std::endl
           << "  size   = " << expected_size << std::endl
           << "  result = ";
    if (expected) {
        stream << "[ ";
        for (size_t i = 0; i < expected_size; ++i) {
            stream << "\"" << expected[i] << "\"";
            if (i < expected_size - 1) {
                stream << ", ";
            }
        }
        stream << " ]" << std::endl;
    } else {
        stream << "nullptr" << std::endl;
    }

    stream << "Actual: "                   << std::endl
           << "  size   = " << actual_size << std::endl
           << "  result = ";

    if (actual) {
        stream << "[ ";
        for (size_t i = 0; i < actual_size; ++i) {
            stream << "\"" << actual[i] << "\"";
            if (i < actual_size - 1) {
                stream << ", ";
            }
        }
        stream << " ]" << std::endl;
    } else {
        stream << "nullptr" << std::endl;
    }

    return stream.str();
}

void check_results(const char* str, const char* seps,
                   const char** expected, size_t expected_size,
                   const char** actual, size_t actual_size) {

    ASSERT_EQ(expected_size, actual_size)
        << error_msg(str, seps, expected, expected_size, actual, actual_size);

    for (size_t i = 0; i < actual_size; ++i) {
        ASSERT_STREQ(expected[i], actual[i])
            << error_msg(str, seps, expected, expected_size, actual, actual_size);
    }

}

TEST(skipTest, HelloWorldTest) {
    const char* str  = "Hello, World!";
    const char* seps = " ,!";
    const size_t expected_size = 2;
    const char* expected[] = { "Hello",  "World" };

    char** actual = nullptr;
    size_t actual_size = split(str, seps, actual);
    auto cleanup = Cleanup(actual, actual_size);

    check_results(str, seps, expected, expected_size, (const char**) actual, actual_size);
}

TEST(skipTest, EmptyStringTest) {
    const char* str  = "";
    const char* seps = " ,!";
    const size_t expected_size = 0;
    const char** expected = nullptr;

    char** actual = nullptr;
    size_t actual_size = split(str, seps, actual);
    auto cleanup = Cleanup(actual, actual_size);

    check_results(str, seps, expected, expected_size, (const char**) actual, actual_size);
}

TEST(skipTest, EmptySeparatorsTest) {
    const char* str  = "Hello, World!";
    const char* seps = "";
    const size_t expected_size = 1;
    const char* expected[] = { str } ;

    char** actual = nullptr;
    size_t actual_size = split(str, seps, actual);
    auto cleanup = Cleanup(actual, actual_size);

    check_results(str, seps, expected, expected_size, (const char**) actual, actual_size);
}

TEST(skipTest, SkipAllTest) {
    const char* str  = "oooooooo";
    const char* seps = "o";
    const size_t expected_size = 0;
    const char** expected = nullptr;

    char** actual = nullptr;
    size_t actual_size = split(str, seps, actual);
    auto cleanup = Cleanup(actual, actual_size);

    check_results(str, seps, expected, expected_size, (const char**) actual, actual_size);
}

TEST(skipTest, SkipStardAndEndTest) {
    const char* str  = "ooOOOooo";
    const char* seps = "o";
    const size_t expected_size = 1;
    const char* expected[] = { "OOO" };

    char** actual = nullptr;
    size_t actual_size = split(str, seps, actual);
    auto cleanup = Cleanup(actual, actual_size);

    check_results(str, seps, expected, expected_size, (const char**) actual, actual_size);
}

TEST(skipTest, LoremIpsumTest) {
    const char* str  =
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
        "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    const char* seps = " ,.";
    const size_t expected_size = 19;
    const char* expected[] = {
        "Lorem", "ipsum", "dolor", "sit", "amet",
        "consectetur", "adipiscing", "elit", "sed", "do",
        "eiusmod", "tempor", "incididunt", "ut", "labore",
        "et", "dolore", "magna", "aliqua"
    };

    char** actual = nullptr;
    size_t actual_size = split(str, seps, actual);
    auto cleanup = Cleanup(actual, actual_size);

    check_results(str, seps, expected, expected_size, (const char**) actual, actual_size);
}

