#include <SFML/Graphics.hpp>
#include <iostream>

#include "Headers/Screen.h"
#include "Headers/Array.h"
#include "Headers/Visualizer.h"


/*

@ Main application

*/

int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "Sort Visualizer /w SFML");

    // I will plot 70 elements for now
    long my_size {70};


    // Create an initial array
    Array my_array {my_size};
    my_array.inflate();         // inflate it with values according to amount provided
    my_array.shuffle_values();  // randomly shuffle the values


    // Get shuffled values of the array
    auto my_vals = my_array.get_values();


    // Create a `Visualizer` object with certain values
    Visualizer visualizer {my_vals};        // initiate it
    visualizer.create_value_bars();         // create bars according to info provided
    auto my_bars = visualizer.get_bars();   // receive the vector of bars





    // ---- MAIN LOOP ---- ///
    while (window.isOpen())
    {
        // Handle closing
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }



        // Color the background with color given in "Header/Screen.h"
        window.clear(sf::Color{BG_COLOR});

        // Visualize the initial values
        for (long i = 0; i < my_size; ++i) {
            window.draw(my_bars[i]);
        }

        // Display
        window.display();
    }

    return 0;
}