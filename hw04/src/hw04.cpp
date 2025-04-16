#include <hw04.h>
#include <iostream>
#include <cstddef>
using namespace std; 

int hw04(const int* input_array, std::size_t elem_count) {
    int* out_data = new int[1];
    size_t size = 0;
    size_t capacity = 1;

    for (std::size_t i = 0; i < elem_count; ++i) {
        int current = input_array[i];
        if (current <= 0) {
            break;
        }

        if (size == capacity) {
            capacity += 1;
            int* new_array = new int[capacity];
            for (size_t j = 0; j < size; ++j) {
                new_array[j] = out_data[j];
            }
            new_array[size] = current;
            delete[] out_data;
            out_data = new_array;
            size += 1;
        } else {
            out_data[size] = current;
            size += 1;
        }
    }

    int sum = 0;
    for (size_t j = 0; j < size; ++j) {
        sum += out_data[j];
    }

    delete[] out_data;
    return sum;
}

int main() {
    return 0;
}