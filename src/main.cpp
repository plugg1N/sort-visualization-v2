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

    long my_size {300};

    // Init objects
    Array my_array {my_size};
    Sorting algo;
    Bars visualizer;


    // Initial Values
    auto initial_array = my_array.get_values();
    auto initial_bars = visualizer.get_bars(initial_array);


    algo.insertion_sort(initial_array);              // sort the initial array
    auto captured_frames = algo.get_frames();     // get each frame of sorting algorithm
    size_t frames_size = captured_frames.size();

    std::vector<std::vector<sf::RectangleShape>> captured_bars {};

    for (int i = 0; i < frames_size; i++) {
        captured_bars.push_back(visualizer.get_bars(captured_frames[i]));
    }



    



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
        

        if (!algo.if_sorted()) {
            for (int i = 0; i < captured_bars.size(); ++i) {
                window.clear(sf::Color{BG_COLOR});



                for (int j = 0; j < captured_bars[i].size(); ++j) {
                    window.draw(captured_bars[i][j]);
                }

                sf::sleep(sf::milliseconds(1));
                window.display();
            }
        }

        algo.set_sorted();

        


        // for (int i = 0; i < initial_bars.size(); ++i) {
        //     window.draw(initial_bars[i]);
        // }


        
    }

    return 0;
}