#include <iostream>
#include <memory>

#include "HotDrink_interface.hpp"
#include "Tea.hpp"
#include "Coffee.hpp"

//Simple client
std::unique_ptr<HotDrink> makeDrink(std::string type)
{
    std::unique_ptr<HotDrink> drink;

    if(type == "tea") {
        drink = std::make_unique<Tea>();
        drink->prepare(250);
    } else if (type == "coffee") {
        drink = std::make_unique<Coffee>();
        drink->prepare(250);
    }
    return drink;
}

int main()
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "First test" << std::endl;
    
    auto makedDrink = makeDrink("tea");

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Second test" << std::endl;
    
    makedDrink = makeDrink("coffee");


}