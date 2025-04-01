#include <hw02.h>
#include <iostream>
#include <string>
using namespace std; 

string hw02(std::string input_str)
{
    size_t i = 0;
    while (i < input_str.size()) {
        char current = input_str[i];
        if (input_str.substr(0, i).find(current) != string::npos) {
            input_str.erase(i, 1); 
        } else {
            ++i; 
        }
    }
    return input_str;
}
