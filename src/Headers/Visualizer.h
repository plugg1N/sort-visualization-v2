#ifndef VISUALIZER_H
#define VISUALIZER_H


/*

@ Handle the creation of bars for plotting to the screen

*/

#include <vector>
#include <SFML/Graphics.hpp>

class Visualizer {
    // alias
    typedef std::vector<double> ValueArray;

    private:
        ValueArray                      _values {};                         // values of elements in array
        std::vector<sf::RectangleShape> _bars {};                           // vector of bars to plot
        size_t                          _num_elements { _values.size() };   // amount of bars/values
    

    public:
        Visualizer(ValueArray& elements);                                   // initialize with starting vector
        void create_value_bars();                                           // create bars using `sf::RectangleShape`
        std::vector<sf::RectangleShape> get_bars() { return _bars; }        // bars getter

};


#endif