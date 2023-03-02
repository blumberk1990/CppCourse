#pragma once
#include "HotDrink_interface.hpp"

class Tea : public HotDrink
{
    public:
        void prepare(int volume) override;
};