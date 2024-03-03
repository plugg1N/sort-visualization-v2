#include "Headers/Bars.h"
#include "Headers/Screen.h"



std::vector<sf::RectangleShape> Bars::get_bars(std::vector<double>& values) {
    size_t size = values.size();
    std::vector<sf::RectangleShape> bars{};

    for (int i = 0; i < size; ++i) {
        sf::RectangleShape block(sf::Vector2f(SCR_WIDTH/size-0.5f, values[i]));
        block.setPosition(i*SCR_WIDTH/size, SCR_HEIGHT-values[i]);
        block.setFillColor(sf::Color::White);
    }

    return bars;
}