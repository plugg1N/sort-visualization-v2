#include "Headers/Algorithms.h"


/*
TODO:
    - Create a function or smth that will send new state of array after
    each sorting iteration.

    - Add more algorithms.
END

@ All sorting algorithms will be implemented here

*/


// Bubble sort
void SortingAlgorithms::bubble_sort(ValueArray& array) {
    long i, j, t;
    size_t num_elements = array.size();

    for (i = 0; i < num_elements-1; ++i) {
        for (j = 0; j < num_elements-1-i; ++j) {
            if (array[j] > array[j+1]) {
                t = array[j];
                array[j] = array[j+1];
                array[j+1] = t;
            }
        } 
    }
}