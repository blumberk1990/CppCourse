#include "DrinkFactory.hpp"

DrinkFactory::DrinkFactory()
{
    hotFactories["tea"] = std::make_unique<TeaFactory>();
    hotFactories["coffee"] = std::make_unique<CoffeeFactory>();
}

std::unique_ptr<HotDrink> DrinkFactory::makeDrink(const std::string& name)
{
    auto drink = hotFactories[name]->make();
    drink->prepare(150);
    return drink;
}