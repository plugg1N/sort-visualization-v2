#include "Headers/Sorting.h"


Sorting::Sorting(sf::RenderWindow& window, Converter& conv)
    : _window{window}, _conv{conv} {
}


void Sorting::draw_bars(std::vector<sf::RectangleShape>& bars) {
    size_t size = bars.size();

    for (int i=0; i < size; ++i) {
        _window.draw(bars[i]);
    }
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

            _window.clear(sf::Color{BG_COLOR});
            draw_bars(bars);
            _window.display();
            
        }

        array[j + 1] = key;
    }

    set_sorted();
}