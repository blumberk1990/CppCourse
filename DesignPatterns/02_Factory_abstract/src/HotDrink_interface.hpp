#pragma once
//abstract class with pure virtual method
class HotDrink
{
    public:
        virtual void prepare(int volume) = 0;
};