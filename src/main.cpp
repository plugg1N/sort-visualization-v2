#include <SFML/Graphics.hpp>
#include <iostream>

#include "Headers/Screen.h"
#include "Headers/Array.h"
#include "Headers/Visualizer.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "Sort Visualizer /w SFML");

    long my_size {800};

    Array my_array        {my_size};
    my_array.inflate();
    my_array.shuffle_values();


    auto my_vals = my_array.get_values();

    Visualizer visualizer {my_vals};
    visualizer.create_value_bars();
    auto my_bars = visualizer.get_bars();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color{BG_COLOR});


        for (long i = 0; i < my_size; ++i) {
            window.draw(my_bars[i]);
        }


        window.display();
    }

    return 0;
}