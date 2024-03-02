#include "Headers/Visualizer.h"
#include "Headers/Screen.h"

Visualizer::Visualizer(ValueArray& elements)
    : _values{elements} {
}

void Visualizer::create_value_bars() {
    for (long i = 0; i < _num_elements; i++) {
        sf::RectangleShape block(sf::Vector2f(SCR_WIDTH/_num_elements-0.5, _values[i]));
        block.setPosition(i*SCR_WIDTH/_num_elements, SCR_HEIGHT-_values[i]);

        _bars.push_back(block);
    }
}

