#include <cstdlib>

int* copy(int* p, size_t size) {
    if (size == 0) {
        return nullptr;
    }
    int* q = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        q[i] = p[i];
    }
    return q;
}