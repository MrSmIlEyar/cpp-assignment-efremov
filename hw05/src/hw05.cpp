#include <hw05.h>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

vector<string> hw05(const vector<string>& strings) {
    auto is_palindrome = [](const string& s) -> bool {
        string cleaned;
        for (char c : s) {
            if (isalnum(c)) {
                cleaned.push_back(tolower(c));
            }
        }
        size_t len = cleaned.size();
        for (size_t i = 0; i < len / 2; ++i) {
            if (cleaned[i] != cleaned[len - i - 1]) {
                return false;
            }
        }
        return true;
    };

    vector<string> result;
    for (const auto& str : strings) {
        if (is_palindrome(str)) {
            result.push_back(str);
        }
    }
    return result;
}

int main() {
    return 0;
}