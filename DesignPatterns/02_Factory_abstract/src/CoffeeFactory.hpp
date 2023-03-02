#pragma once
#include "HotDrinkFactory_interface.hpp"
#include "Coffee.hpp"

class CoffeeFactory : public HotDrinkFactory
{
    public:
        std::unique_ptr<HotDrink> make() const override;
};