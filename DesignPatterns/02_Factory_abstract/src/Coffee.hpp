#pragma once
#include "HotDrink_interface.hpp"

class Coffee : public HotDrink
{
    public:
        void prepare(int volume) override;
};