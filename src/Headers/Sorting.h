#ifndef SORTING_H
#define SORTING_H


#include <SFML/Graphics.hpp>


class Sorting {
    private:
        bool _sorted        {false};
        bool _anim          {false};
        int  _slow_pointer  {NULL};
        int  _fast_pointer  {NULL};
        
        std::vector<double> _curr_state {};

        sf::RenderWindow& _window;
        Converter _conv{};

        void _set_curr_state(std::vector<double>& state) { _curr_state = state; }



    public:
        Sorting(sf::RenderWindow& window, Converter conv);

        void draw_bars(std::vector<sf::RectangleShape>& bars);
        void check_sort_animation();

        void set_slow_pointer(int& index) { _slow_pointer = index; }
        void set_fast_pointer(int& index) { _fast_pointer = index; }

        void insertion_sort(std::vector<double>& array);
        void cocktail_sort(std::vector<double>& array);

        void set_sorted() { _sorted = true; }
        bool if_sorted()  { return _sorted; }
        bool if_anim()    { return _anim; }
};


#endif