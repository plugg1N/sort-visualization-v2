#include <SFML/Graphics.hpp>
#include <iostream>

#include "Headers/Screen.h"
#include "Headers/Array.h"
#include "Headers/Converter.h"
#include "Headers/Sorting.h"


/*

@ Main application

*/

int main()
{
    // Create a window and set amount of elements
    sf::RenderWindow window(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "Sort Visualizer /w SFML",
                            sf::Style::Close);

    long my_size {800};

    // Init objects
    Array my_array {my_size};
    Converter conv;
    Sorting sorting{window, conv};


    // Initial Values
    auto initial_array = my_array.get_values();
    




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


        if (!sorting.if_sorted()) {
            sorting.cocktail_sort(initial_array);
        }
    }

    return 0;
}