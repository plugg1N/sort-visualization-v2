#ifndef BARS_H
#define BARS_H

#include <SFML/Graphics.hpp>

class Bars {
    public:
        std::vector<sf::RectangleShape> get_bars(std::vector<double>& values);
};


#endif