#ifndef ARRAY_H
#define ARRAY_H

#include <vector>


/*

@ Handle creation and shuffling of initial array

*/

class Array
{
    // Alias
    typedef std::vector<double> ValueArray;

    private:
        long _num_elements {};          // number of elements to visualize
        ValueArray _values {};          // values themselves


    public:
        Array(long _num_elements);      // initializer

        void inflate();                 // fill the elements in
        void shuffle_values();          // shuffle the _values

        ValueArray get_values() { return _values; }     // return values of array. getter
};


#endif