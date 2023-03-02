#include "Coffee.hpp"
#include <iostream>
#include <string>

void Coffee::prepare(int volume) 
{
    std::cout << "Get a coffee grain and put it in the cup, and fill in with a "
              << volume << " of water."
              << std::endl;
}

