#ifndef ARRAY_H
#define ARRAY_H

#include <vector>


/*

@ Handle creation and shuffling of initial array

*/

class Array
{
    private:
        long _num_elements {};                   // number of elements to visualize
        std::vector<double> _values {};          // values themselves

        void inflate();                          // fill array with values (staircase formation)
        void shuffle_values();                   // shuffle values using Fischer-Yates algorithm


    public:
        Array(long _num_elements);  // initializer

        std::vector<double> get_values() { return _values; }     // return values of array. getter
};


#endif