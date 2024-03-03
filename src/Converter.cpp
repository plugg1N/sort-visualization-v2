#include "Headers/Converter.h"
#include "Headers/Screen.h"


/*

@ Make bars (sf::RectangleShapes from values)

*/

// Convert
std::vector<sf::RectangleShape> Converter::convert_to_bars(std::vector<double>& values) {
    std::vector<sf::RectangleShape> bars{};
    size_t size = values.size();

    // for each value set its position. Height is set according to its value 
    for(int i=0; i < size; i++){
        sf::RectangleShape block(sf::Vector2f(SCR_WIDTH/size-0.5f, values[i]));
        block.setPosition(i*SCR_WIDTH/size, SCR_HEIGHT-values[i]);
        block.setFillColor(sf::Color::White);
        bars.push_back(block);
    }

    return bars;
}