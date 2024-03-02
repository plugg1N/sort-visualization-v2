#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <iostream>

class Helper {
    typedef std::vector<double> ValueArray;

    private:
        ValueArray _state {};

    public:
        Helper(ValueArray& state);
        ValueArray get_state() { return _state; }
        void set_state(ValueArray& state) { _state = state; }

        void print_iterations(ValueArray& array);
};


#endif