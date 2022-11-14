#include "TeaFactory.hpp"
#include <memory>

std::unique_ptr<HotDrink> TeaFactory::make() const
{
    return std::make_unique<Tea>();
}