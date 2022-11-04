#pragma once
#include "PersonEmploymentBuilder.h"

PersonEmploymentBuilder& PersonEmploymentBuilder::at(std::string companyName)
{
    person.companyName = companyName;
    return *this;
}

PersonEmploymentBuilder& PersonEmploymentBuilder::asA(std::string position)
{
    person.position = position;
    return *this;
}

PersonEmploymentBuilder& PersonEmploymentBuilder::earning(float annualIncome)
{
    person.annualIncome = annualIncome;
    return *this;
}
