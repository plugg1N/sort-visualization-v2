#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <vector>
#include <SFML/Graphics.hpp>

class Visualizer {
    typedef std::vector<double> ValueArray;

    private:
        ValueArray   _values {};
        std::vector<sf::RectangleShape> _bars {};
        size_t _num_elements { _values.size() };
    

    public:
        Visualizer(ValueArray& elements);
        void create_value_bars();
        std::vector<sf::RectangleShape> get_bars() { return _bars; }

};


#endif