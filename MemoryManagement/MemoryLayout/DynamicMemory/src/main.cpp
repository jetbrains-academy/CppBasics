#include <cstdlib>
#include <iostream>

void leak() {
    char* p = (char*) malloc(8);
}

int main() {

    char* p = (char*) malloc(8);
    for (int i = 0; i < 8; ++i) {
        p[i] = 0;
    }
    std::cout << (void*) p << std::endl;

    int* q = (int*) malloc(8 * sizeof(int));
    std::cout << q << std::endl;

    int* r = (int*) malloc(0);
    std::cout << r << std::endl;

    free(p);
    free(q);

    leak();

    return 0;
}