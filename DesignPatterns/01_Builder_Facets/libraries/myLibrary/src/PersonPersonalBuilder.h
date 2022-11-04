#pragma once
#include "PersonBuilder.h"

class PersonPersonalBuilder : public PersonBuilderBase
{
private:
    typedef PersonPersonalBuilder self;
public:
    explicit PersonPersonalBuilder(Person& person) : PersonBuilderBase{ person } {}
    self& withName(std::string firstName);
    self& withSurname(std::string lastName);
    self& withDateOfbirth(std::string dateOfBirth);
};