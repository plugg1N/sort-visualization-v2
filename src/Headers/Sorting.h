#ifndef SORTING_H
#define SORTING_H

#include <vector>


class Sorting {
    private:
        std::vector<std::vector<double>> _frames {};


    public:
        void bubble_sort(std::vector<double> array);

        void capture_frame(std::vector<double> array) { _frames.push_back(array); }
        std::vector<std::vector<double>> get_frames() { return _frames; }
};


#endif