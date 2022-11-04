#pragma once
#include "PersonBuilder.h"

//Inheritance after PersonBuilderBase to avoid building to many real object, 
//insted work with reference to the real object!!!
class PersonEmploymentBuilder : public PersonBuilderBase
{
private:
    typedef PersonEmploymentBuilder self;
public:
    explicit PersonEmploymentBuilder(Person& person) : PersonBuilderBase{ person } {}
    self& at(std::string companyName);
    self& asA(std::string position);
    self& earning(float annualIncome);
};
