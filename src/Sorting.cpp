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

    for (i = 1; i < array.size(); i++) {
        double key = array[i];
        j = i - 1;

        // Capture the state before the inner loop

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];

            j = j - 1;

            auto bars = _conv.convert_to_bars(array);
            draw_bars(bars);
            
        }

        array[j + 1] = key;

        auto bars = _conv.convert_to_bars(array);
        draw_bars(bars);
    }

    set_sorted();
}