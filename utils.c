#include "utils.h"

char* strndup(const char* str, size_t n)
{
    if (str) {
        size_t len = strlen(str);
        size_t nn = len > n? n : len;
        char *s = (char*)malloc(sizeof(char) * (nn + 1));
        
        if (s) {
            memcpy(s, str, nn);
            s[nn] = '\0';
        }
        return s;
    }
    return NULL;
}

extern
char **keyvalue(const char *kv)
{
    char *delim = "=";
    char *key;
    char *value;
    char **keyval = (char **)malloc(sizeof(char*) * 2);
    int i = strstr(kv, delim) - kv;
    keyval[0] = strndup(kv, i);
    keyval[1] = (char *)(kv + i + 1);
    return keyval;
}
