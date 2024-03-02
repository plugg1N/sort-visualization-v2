#ifndef ARRAY_H
#define ARRAY_H

#include <vector>


class Array
{

    private:
        long _num_elements {};          // number of elements to visualize
        std::vector<double> _values {}; // values themselves


    public:
        Array(long _num_elements);      // initializer

        void inflate();                 // fill the elements in
        void shuffle_values();          // shuffle the _values

        std::vector<double> get_values() { return _values; }

};


#endif