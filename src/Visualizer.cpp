#include "Headers/Visualizer.h"
#include "Headers/Screen.h"

Visualizer::Visualizer(ValueArray& elements)
    : _values{elements} {
}

void Visualizer::create_value_bars() {
    for (long i = 0; i < _num_elements; i++) {
        sf::RectangleShape block(sf::Vector2f(SCR_WIDTH/_num_elements-0.5f, _values[i]));
        block.setOutlineColor(sf::Color::Black);
        block.setOutlineThickness(1.0f);
        block.setPosition(i*SCR_WIDTH/_num_elements, SCR_HEIGHT-_values[i]);

        _bars.push_back(block);
    }
}

