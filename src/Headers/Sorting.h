#ifndef SORTING_H
#define SORTING_H


/*

@ Sorting algorithms themselves. And some functions:
    - Drawing of the values
    - Visualize idx of comparison members
    - End sorting animation
    - Check for end of sort

*/

#include <SFML/Graphics.hpp>


class Sorting {
    private:
        bool _sorted        {false};    // sorted state
        bool _anim          {false};    // if animation is done
        int  _slow_pointer  {NULL};     // slow pointer index (NULL = no pointer)
        int  _fast_pointer  {NULL};     // fast pointer index (NULL = no pointer)
        
        std::vector<double> _curr_state {};     // last state of values 

        sf::RenderWindow& _window;      // get window
        Converter _conv{};              // get Converter object

        void _set_curr_state(std::vector<double>& state) { _curr_state = state; }   // setter for state



    public:
        // Initialize
        Sorting(sf::RenderWindow& window, Converter conv);

        // Draw bars to the screen
        void draw_bars(std::vector<sf::RectangleShape>& bars);
        void check_sort_animation();    // check if sorted (animation of checking)

        void set_slow_pointer(int index) { _slow_pointer = index; }    // set index of a slow pointer
        void set_fast_pointer(int index) { _fast_pointer = index; }    // set index of a fast pointer


        // --- SORTING ALGORITHMS --- // 
        void insertion_sort(std::vector<double>& array);
        void cocktail_sort(std::vector<double>& array);


        // Setters and getters
        void set_sorted() { _sorted = true; }   // set if sorting process has ended successfully
        bool if_sorted()  { return _sorted; }   // check if sorted
        bool if_anim()    { return _anim; }     // check if animation has been done
};


#endif