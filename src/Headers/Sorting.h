#ifndef SORTING_H
#define SORTING_H


#include <SFML/Graphics.hpp>


class Sorting {
    private:
        bool _sorted {false};

        sf::RenderWindow& _window;
        Converter _conv{};


    public:
        Sorting(sf::RenderWindow& window, Converter conv);

        void draw_bars(std::vector<sf::RectangleShape>& bars);

        void insertion_sort(std::vector<double>& array);

        void set_sorted() { _sorted = true; }
        bool if_sorted()  { return _sorted; }
};


#endif