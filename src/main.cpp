#include <SFML/Graphics.hpp>
#include <iostream>

#include "Headers/Screen.h"
#include "Headers/Array.h"
#include "Headers/Sorting.h"
#include "Headers/Bars.h"


/*

@ Main application

*/

int main()
{
    // Create a window and set amount of elements
    sf::RenderWindow window(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "Sort Visualizer /w SFML");
    long my_size {20};

    // Init objects
    Array my_array {my_size};
    Sorting algo;
    Bars visualizer;


    auto initial_array = my_array.get_values();   // initial values
    algo.bubble_sort(initial_array);              // sort the initial array

    auto captured_frames = algo.get_frames();     // get each frame of sorting algorithm

    // for (int i = 0; i < captured_frames.size(); ++i) {
    //     for (int j = 0; j < my_size; ++j) {
    //         std::cout << captured_frames[i][j] << " ";
    //     }

    //     std::cout << "\n";
    // }

    



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

    
        // Display
        window.display();
    }

    return 0;
}