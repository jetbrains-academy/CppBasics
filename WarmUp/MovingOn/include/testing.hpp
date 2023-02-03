#ifndef CPPBASICS_TESTING_HPP
#define CPPBASICS_TESTING_HPP

#include <cstdlib>
#include <ctime>

#include "scene.hpp"

inline void initGen() {
    // fix seed to generate test data deterministically
    srand(1);
}

inline float genFloat(float min, float max) {
    return min + (rand() / (RAND_MAX / (max - min)));
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

template <typename TestDataGen, typename TestAssert>
void property_test(TestDataGen gen, TestAssert test) {
    for (int i = 0; i < N_ITER; ++i) {
        test(gen());
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

    ASSERT_TRUE(different) << "Failed to generate sequence of different random values\n"
                           << "Generated sequence: " << seq;
}

const float EPS = 0.0001f;

#endif //CPPBASICS_TESTING_HPP
