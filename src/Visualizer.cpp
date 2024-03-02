#include "Headers/Visualizer.h"
#include "Headers/Screen.h"


/*

@ All sorting algorithms will be implemented here

*/


// Initialize
Visualizer::Visualizer(ValueArray& elements)
    : _values{elements} {
}


// Create bars to plot to the screen
void Visualizer::create_value_bars() {
    for (long i = 0; i < _num_elements; i++) {
        // Create a block with default White color and set its poistion according to SCR_WIDTH
        sf::RectangleShape block(sf::Vector2f(SCR_WIDTH/_num_elements-0.5, _values[i]));
        block.setPosition(i*SCR_WIDTH/_num_elements, SCR_HEIGHT-_values[i]);

        // Add bar to bars vector
        _bars.push_back(block);
    }
}

