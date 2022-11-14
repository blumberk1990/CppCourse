#pragma once
#include <map>
#include <string>
#include <memory>
#include "HotDrinkFactory_interface.hpp"
#include "CoffeeFactory.hpp"
#include "TeaFactory.hpp"
#include "Tea.hpp"
#include "Coffee.hpp"
#include "Tea.hpp"


class DrinkFactory
{
    private:
        std::map<std::string, std::unique_ptr<HotDrinkFactory>> hotFactories;
    public:
        DrinkFactory();
        std::unique_ptr<HotDrink> makeDrink(const std::string& name);
};
