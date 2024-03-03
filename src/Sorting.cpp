#include <algorithm>

#include "Headers/Converter.h"
#include "Headers/Sorting.h"
#include "Headers/Screen.h"


/*

@ All sorting algorithms will be implemented here

*/


// Initialize Sorting obj. Provide it with window and Converter 
Sorting::Sorting(sf::RenderWindow& window, Converter conv)
    : _window{window}, _conv{conv} {
}


// Draw bars to the screen
void Sorting::draw_bars(std::vector<sf::RectangleShape>& bars) {
    size_t size = bars.size();

    _window.clear(sf::Color{BG_COLOR});

    bars[_slow_pointer].setFillColor(sf::Color::Green);     // show where slow pointer is
    bars[_fast_pointer].setFillColor(sf::Color::Red);       // show where fast pointer is

    for (int i=0; i < size; ++i) {
        _window.draw(bars[i]);
    }

    _window.display();
}



// --- SORTING ALGORITHMS --- //


// Insertion sort
void Sorting::insertion_sort(std::vector<double>& array) {
    int i, j;
    std::vector<sf::RectangleShape> bars {};

    for (i = 1; i < array.size(); i++) {
        double key = array[i];
        set_slow_pointer(i);
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            set_fast_pointer(j);
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
    _set_curr_state(array);
}



// Cocktail sort
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
                set_slow_pointer(i);
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
                set_fast_pointer(i+1);
                std::swap(array[i], array[i + 1]);
                swapped = true;
            }
        }

        if (swapped) {
            bars = _conv.convert_to_bars(array);
            draw_bars(bars);
            sf::sleep(sf::milliseconds(50));
        }
        ++start;
    }

    bars = _conv.convert_to_bars(array);
    draw_bars(bars);


    set_sorted();
    _set_curr_state(array);
}

////////////////////



// Animate the process of sort check

// TODO: recreate this animation
void Sorting::check_sort_animation() {
    std::vector<double> state = _curr_state;
    std::vector<sf::RectangleShape> bars = _conv.convert_to_bars(state);

    _window.clear(sf::Color{BG_COLOR});
    for (int i=0; i < bars.size(); ++i) {
        bars[i].setFillColor(sf::Color::Green);
        _window.draw(bars[i]);   

    }

    _window.display();
    

    _anim = true;
}