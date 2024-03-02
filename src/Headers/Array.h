#ifndef ARRAY_H
#define ARRAY_H

#include <vector>



class Array
{
    typedef std::vector<double> ValueArray;

    private:
        long _num_elements {};          // number of elements to visualize
        ValueArray _values {}; // values themselves


    public:
        Array(long _num_elements);      // initializer

        void inflate();                 // fill the elements in
        void shuffle_values();          // shuffle the _values

        ValueArray get_values() { return _values; }
};


#endif