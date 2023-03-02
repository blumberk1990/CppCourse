#pragma once
#include <memory>
#include "HotDrink_interface.hpp"

class HotDrinkFactory
{
    public:
        virtual std::unique_ptr<HotDrink> make() const = 0;
};