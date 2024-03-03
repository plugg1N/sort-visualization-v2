#include <algorithm>

#include "Headers/Converter.h"
#include "Headers/Sorting.h"
#include "Headers/Screen.h"


Sorting::Sorting(sf::RenderWindow& window, Converter conv)
    : _window{window}, _conv{conv} {
}


void Sorting::draw_bars(std::vector<sf::RectangleShape>& bars) {
    size_t size = bars.size();

    _window.clear(sf::Color{BG_COLOR});

    for (int i=0; i < size; ++i) {
        _window.draw(bars[i]);
    }

    _window.display();
}





void Sorting::insertion_sort(std::vector<double>& array) {
    int i, j;
    std::vector<sf::RectangleShape> bars {};

    for (i = 1; i < array.size(); i++) {
        double key = array[i];
        j = i - 1;

        // Capture the state before the inner loop

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];

            j = j - 1;

            bars = _conv.convert_to_bars(array);
            draw_bars(bars);
            bars.clear();
            
        }

        array[j + 1] = key;

        bars = _conv.convert_to_bars(array);
        draw_bars(bars);
        bars.clear();
    }

    set_sorted();
}





void Sorting::cocktail_sort(std::vector<double>& array) {
    bool swapped = true;
    int start = 0;
    size_t n = array.size();
    int end = n - 1;
    std::vector<sf::RectangleShape> bars {};

    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;

        --end;

        for (int i = end - 1; i >= start; --i) {
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
                swapped = true;
            }
        }

        if (swapped) {
            bars = _conv.convert_to_bars(array);
            draw_bars(bars);
            sf::sleep(sf::milliseconds(70));
        }
        ++start;
    }

    set_sorted();
}