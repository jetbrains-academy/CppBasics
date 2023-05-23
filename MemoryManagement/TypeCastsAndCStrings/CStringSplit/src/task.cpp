#include <cstdlib>
#include <cstring>

size_t split(const char* str, const char* seps, char**& res) {
    // firstly we calculate the number of substrings
    size_t size = 0;
    const char* p = str;
    const char* end = str + strlen(str);
    while (p) {
        p += strspn(p, seps);
        if (p == end)
            break;
        p = strpbrk(p, seps);
        size++;
    }
    // handle the case when there are no substrings
    if (size == 0) {
        res = nullptr;
        return 0;
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
        q = q ? q : end;
        size_t len = q - p;
        res[i] = (char*) malloc(len + 1);
        strncpy(res[i], p, len);
        res[i][len] = '\0';
        p = q;
    }
    return size;
}