#include "Headers/Array.h"
#include "Headers/Screen.h"

#include <random>
#include <SFML/Graphics.hpp>


/*

@ All sorting algorithms will be implemented here

*/



// Fill the array with normalized values 
void Array::inflate() {
    double bar_value_diff = (SCR_HEIGHT/2 + SCR_HEIGHT*0.1) / static_cast<double>(_num_elements);   // difference between each neighbouring value

    double i = 1.0;

    // inflate and mupltiply each one to create an equal `staircase` formation
    while (i <= static_cast<double>(_num_elements)) {
        _values.push_back(bar_value_diff * i);
        i += 1.0;
    }
}



// Shuffle the array using Fischer-Yates algorithm
void Array::shuffle_values() {
    long arr_size = _num_elements;

    // get new results after each launch
    srand(static_cast<unsigned int>(time(nullptr)));


    // swap values randomly
    for (int i = arr_size -  1; i > 0; --i) {
        int j = rand() % (i +  1);
        std::swap(_values[i], _values[j]);
    }
}





// Initialize the array
Array::Array(long num_elements)
    : _num_elements {num_elements} {

    inflate();
    shuffle_values();

}


