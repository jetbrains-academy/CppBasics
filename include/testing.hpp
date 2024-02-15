#ifndef CPPBASICS_TESTING_HPP
#define CPPBASICS_TESTING_HPP

#include <cstdlib>
#include <ctime>
#include <memory>
#include <type_traits>

#include <gtest/gtest.h>

#include "point.hpp"
#include "utils.hpp"

inline void initGen() {
    // fix seed to generate test data deterministically
    srand(1);
}

inline float genFloat(float min, float max) {
    return min + ((float) rand() / RAND_MAX) * (max - min);
}

class TestEnvironment : public ::testing::Environment {
public:
    ~TestEnvironment() override = default;

    void SetUp() override {
        initGen();
    }

    void TearDown() override {}
};

const int N_ITER = 10;
const float EPS = 0.0001f;

template <typename TestDataGen, typename TestAssert>
void property_test(TestDataGen gen, TestAssert test) {
    for (int i = 0; i < N_ITER; ++i) {
        test(gen());
        if (::testing::Test::HasFailure())
            return;
    }
}

template <typename TestDataGen, typename TestDataCmp, typename TestDataPrint>
void randomness_test(TestDataGen gen, TestDataCmp cmp, TestDataPrint print) {
    // it is highly unlikely that properly implemented
    // random generator will return N_ITER equal values in a row
    decltype(gen()) generated[N_ITER];
    for (int i = 0; i < N_ITER; ++i) {
        generated[i] = gen();
    }

    bool different = false;
    for (int i = 0; i < N_ITER; ++i) {
        for (int j = 0; j < N_ITER; ++j) {
            if (i == j) continue;
            if (!cmp(generated[i], generated[j])) {
                different = true;
                break;
            }
        }
        if (different) break;
    }

    std::string seq;
    for (int i = 0; i < N_ITER; ++i) {
        seq += print(generated[i]);
        if (i < N_ITER - 1) {
            seq += ", ";
        }
    }

    ASSERT_TRUE(different) << "Failed to generate sequence of different random values.\n"
                           << "Generated sequence: " << seq << "\n";
}

// RAII clean-up for plain C style pointers,
// adapted from: https://stackoverflow.com/a/43626234/4676150

struct free_deleter {
    template <typename T>
    void operator()(T *p) const {
        std::free(const_cast<std::remove_const_t<T>*>(p));
    }
};

template <typename T>
using unique_Cptr = std::unique_ptr<T, free_deleter>;

typedef unique_Cptr<char> unique_Cstr;

inline unique_Cstr random_Cstr() {
    size_t len = rand() % 10;
    char* str = (char*) malloc(len + 1);
    memset(str, '\0', len + 1);
    for (int i = 0; i < len; ++i) {
        int rng = 'z' - 'a' + 1;
        char c = 'a' + (rand() % rng);
        str[i] = c;
    }
    return unique_Cstr(str);
}

#endif //CPPBASICS_TESTING_HPP
