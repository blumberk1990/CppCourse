#pragma once
#include "PersonAddressBuilder.h"

PersonAddressBuilder& PersonAddressBuilder::at(std::string streetAddress)
{
    person.streetAddress = streetAddress;
    return *this;
}

PersonAddressBuilder& PersonAddressBuilder::withPostCode(std::string postCode)
{
    person.postCode = postCode;
    return *this;
}

PersonAddressBuilder& PersonAddressBuilder::in(std::string city)
{
    person.city = city;
    return *this;
}
