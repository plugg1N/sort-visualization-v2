#include "Headers/Converter.h"
#include "Headers/Screen.h"



std::vector<sf::RectangleShape> Converter::convert_to_bars(std::vector<double>& values) {
    std::vector<sf::RectangleShape> bars{};
    size_t size = values.size();

    for(int i=0; i < size; i++){
        sf::RectangleShape block(sf::Vector2f(SCR_WIDTH/size-0.5f, values[i]));
        block.setPosition(i*SCR_WIDTH/size, SCR_HEIGHT-values[i]);
        block.setFillColor(sf::Color::White);
        bars.push_back(block);
    }

    return bars;
}