#pragma once
#include <iostream>
#include <vector>
#include "person.hpp"

class PersonFactory
{
    private:
        u_int personCounter;

    public:
        Person createPerson(const std::string& name);
};

