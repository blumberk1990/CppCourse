#pragma once
#include <map>
#include <string>
#include <memory>
#include <functional>
#include "HotDrinkFactory_interface.hpp"
#include "TeaFactory.hpp"
#include "CoffeeFactory.hpp"
#include "Tea.hpp"



class DrinkFactory
{
    private:
        std::map<std::string, std::unique_ptr<HotDrinkFactory>> hotFactories;
    public:
        DrinkFactory();
        std::unique_ptr<HotDrink> makeDrink(const std::string& name);
};

class DrinkWithVolumeFactory
{
    private:
        std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> hotDrinkFactories;
    public:
        DrinkWithVolumeFactory();
        std::unique_ptr<HotDrink> makeDrink(const std::string& name);
};