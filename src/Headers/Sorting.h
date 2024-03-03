#ifndef SORTING_H
#define SORTING_H

#include <vector>


class Sorting {
    private:
        std::vector<std::vector<double>> _frames {};
        bool _sorted {false};


    public:
        void insertion_sort(std::vector<double>& array);

        void set_sorted() { _sorted = true; }
        bool if_sorted()  { return _sorted; }
        std::vector<std::vector<double>> get_frames() { return _frames; }
};


#endif