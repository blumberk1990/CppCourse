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

DrinkWithVolumeFactory::DrinkWithVolumeFactory()
{
    // lambda function body invoked lambda function
    hotDrinkFactories["tea"] = [] {
        auto drink = std::make_unique<Tea>();
        drink->prepare(275);
        return drink;
    };
    // lambda function body invoked lambda function
    hotDrinkFactories["coffee"] = [] {
        auto drink = std::make_unique<Coffee>();
        drink->prepare(275);
        return drink;
    };
}

std::unique_ptr<HotDrink> DrinkWithVolumeFactory::makeDrink(const std::string& name)
{
    return hotDrinkFactories[name]();
}