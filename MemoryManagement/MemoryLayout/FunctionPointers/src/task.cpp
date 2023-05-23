#include <cstddef>

int fold(int* array, size_t size, int init, int (*f)(int, int)) {
    int res = init;
    for (size_t i = 0; i < size; ++i) {
        res = f(res, array[i]);
    }
    return res;
}