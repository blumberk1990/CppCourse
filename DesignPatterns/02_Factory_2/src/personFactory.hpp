#pragma once
#include <iostream>
#include <vector>
#include "person.hpp"

class PersonFactory
{
    private:
        static u_int personCounter;

    public:
        Person createPerson(const std::string& name);
};

