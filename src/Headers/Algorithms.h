#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>


/*

@ All sorting algorithms will be implemented here

*/

class SortingAlgorithms {
    // Alias for `std::vector<double>`
    typedef std::vector<double> ValueArray;

    public:
        // Bubble sort
        void bubble_sort(ValueArray& array);
};


#endif