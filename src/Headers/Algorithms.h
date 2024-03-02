#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include "Helper.h"


/*

@ All sorting algorithms will be implemented here

*/

class SortingAlgorithms {
    // Alias for `std::vector<double>`
    typedef std::vector<double> ValueArray;

    public:
        // Bubble sort
        void bubble_sort(ValueArray& array, Helper& helper);
};


#endif