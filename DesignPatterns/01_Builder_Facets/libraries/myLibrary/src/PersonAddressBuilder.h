#pragma once
#include "PersonBuilder.h"

//Inheritance after PersonBuilderBase to avoid building to many real object, 
//insted work with reference to the real object!!!
class PersonAddressBuilder : public PersonBuilderBase
{
private:
    typedef PersonAddressBuilder self;
public:
    explicit PersonAddressBuilder(Person& person) : PersonBuilderBase{ person } {}
    self& at(std::string streetAddress);
    self& withPostCode(std::string postCode);
    self& in(std::string city);
};