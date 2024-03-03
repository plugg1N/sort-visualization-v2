#ifndef CONVERTER_H
#define CONVERTER_H


/*

@ Function to create bars (sf::Rectangles) from values provided

*/

#include <SFML/Graphics.hpp>
#include <vector>


class Converter {
    public:
        std::vector<sf::RectangleShape> convert_to_bars(std::vector<double>& values);

};


#endif