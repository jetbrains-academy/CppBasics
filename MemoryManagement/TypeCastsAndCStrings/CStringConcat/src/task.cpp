#include <cstdlib>
#include <cstring>

char* concat(const char* fst, const char* snd) {
    size_t fst_len = strlen(fst);
    size_t len = fst_len + strlen(snd);
    char* res = (char*) malloc(len + 1);
    strcpy(res, fst);
    strcpy(res + fst_len, snd);
    res[len] = '\0';
    return res;
}