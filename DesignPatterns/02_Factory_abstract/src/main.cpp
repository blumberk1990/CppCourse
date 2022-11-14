#include <iostream>
#include <memory>

#include "HotDrink_interface.hpp"
#include "Tea.hpp"
#include "Coffee.hpp"
#include "CoffeeFactory.hpp"
#include "TeaFactory.hpp"
#include "DrinkFactory.hpp"

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
    std::cout << "1 test" << std::endl;
    
    auto makedDrink = makeDrink("tea");

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "2 test" << std::endl;
    
    makedDrink = makeDrink("coffee");

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "3 test" << std::endl;
    CoffeeFactory coffeeFactory;

    makedDrink = coffeeFactory.make();
    makedDrink->prepare(200);

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "4 test" << std::endl;
    TeaFactory teaFactory;

    makedDrink = teaFactory.make();
    makedDrink->prepare(200);

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "5 test" << std::endl;
    DrinkFactory drinkFactory;

    makedDrink = drinkFactory.makeDrink("tea");

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "6 test" << std::endl;

    makedDrink = drinkFactory.makeDrink("coffee");
    makedDrink->prepare(455);

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "7 test" << std::endl;
    DrinkWithVolumeFactory lambdaDrinkFactory;

    makedDrink = lambdaDrinkFactory.makeDrink("tea");

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "8 test" << std::endl;

    makedDrink = lambdaDrinkFactory.makeDrink("coffee");
    


}