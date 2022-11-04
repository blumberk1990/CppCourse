#include "Person.h"
#include "PersonBuilder.h"


Person::Person()
{
    std::cout << "Person created by class Person." << std::endl;
}

Person::~Person()
{
    std::cout << "Person destroyed by class Person." << std::endl;
}

Person& Person::operator=(Person&& other)
{
    if(this == &other) {
        return *this;
    }
    firstName = std::move(other.firstName);
    lastName = std::move(other.lastName);
    dateOfBirth = std::move(other.dateOfBirth);
    streetAddress = std::move(other.streetAddress);
    postCode = std::move(other.postCode);
    city = std::move(other.city);
    companyName = std::move(other.companyName);
    position = std::move(other.position); 
    annualIncome = std::move(other.annualIncome);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Person& obj)
{
    return os
            << "First name: "       << obj.firstName        << "\n"
            << "Last name: "        << obj.lastName         << "\n"
            << "Date of birth: "    << obj.dateOfBirth      << "\n"
            << "Street: "           << obj.streetAddress    << "\n"
            << "Postal: "           << obj.postCode         << "\n"
            << "City: "             << obj.city             << "\n"
            << "Company name: "     << obj.companyName      << "\n"
            << "position: "         << obj.position         << "\n"
            << "Annual Income: "    << obj.annualIncome     << std::endl;
}

PersonBuilder Person::build()
{
    return PersonBuilder{};
}