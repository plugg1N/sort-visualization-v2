#include "Headers/Array.h"

#include <random>
#include <SFML/Graphics.hpp>


Array::Array(long num_elements)
    : _num_elements {num_elements} {
}


void Array::inflate() {
    double bar_value_diff = 500.0/static_cast<double>(_num_elements);

    double i = 1.0;

    // inflate an array with elements
    while (i <= static_cast<double>(_num_elements)) {
        _values.push_back(bar_value_diff * i);
        i += 1.0;
    }
}


void Array::shuffle_values() {
    long arr_size = _num_elements;

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = arr_size -  1; i > 0; --i) {
        int j = rand() % (i +  1);
        std::swap(_values[i], _values[j]);
    }
}
