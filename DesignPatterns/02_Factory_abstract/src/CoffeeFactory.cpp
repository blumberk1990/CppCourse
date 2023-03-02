#include "CoffeeFactory.hpp"
#include <memory>

std::unique_ptr<HotDrink> CoffeeFactory::make() const
{
    return std::make_unique<Coffee>();
}