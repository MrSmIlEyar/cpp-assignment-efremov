#include <hw03.h>
#include <cstring>
#include <iostream>
#include <ostream>
using namespace std;

void hw03(char* str, const char* pattern) {
    if (str == nullptr || pattern == nullptr) {
        return;
    }
    
    if (*str == '\0') {
        return;
    }
    
    size_t len_str = strlen(str);
    size_t len_p = strlen(pattern);
    
    if (len_p == 0 || len_p > len_str) {
        return;
    }
    
    for (size_t i = 0; i <= len_str - len_p; ++i) {
        bool match = true;
        for (size_t j = 0; j < len_p; ++j) {
            if (str[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            size_t tail_length = len_str - i - len_p + 1;
            memmove(str + i, str + i + len_p, tail_length);
            return;
        }
    }
}
