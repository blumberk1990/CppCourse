#pragma once
#include "HotDrinkFactory_interface.hpp"
#include "Tea.hpp"

class TeaFactory : public HotDrinkFactory
{
    public:
        std::unique_ptr<HotDrink> make() const override;
};