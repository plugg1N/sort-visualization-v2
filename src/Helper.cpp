#include "Headers/Helper.h"
#include <SFML/Graphics.hpp>


Helper::Helper(ValueArray& state)
    : _state{state} {
}

void Helper::print_iterations(ValueArray& array) {
    for (auto& boom : array ) std::cout << boom << " ";
    std::cout << "\n";
}