#include "Headers/Sorting.h"


void Sorting::insertion_sort(std::vector<double>& array) {
    int i, j;

    for (i = 1; i < array.size(); i++) {
        double key = array[i];
        j = i - 1;

        // Capture the state before the inner loop

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];

            j = j - 1;
        }

        array[j + 1] = key;
        _frames.push_back(array);
    }
}