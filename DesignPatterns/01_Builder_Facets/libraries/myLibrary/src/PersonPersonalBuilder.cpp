#pragma once
#include "PersonPersonalBuilder.h"

PersonPersonalBuilder& PersonPersonalBuilder::withName(std::string firstName)
{
    person.firstName = firstName;
    return *this;
}

PersonPersonalBuilder& PersonPersonalBuilder::withSurname(std::string lastName)
{
    person.lastName = lastName;
    return *this;
}

PersonPersonalBuilder& PersonPersonalBuilder::withDateOfbirth(std::string dateOfBirth)
{
    person.dateOfBirth = dateOfBirth;
    return *this;
}
