#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

class PersonBuilder;

class Person
{
    private:
        //Personal data
        std::string firstName;
        std::string lastName;
        std::string dateOfBirth;
        //Address
        std::string streetAddress;
        std::string postCode;
        std::string city;
        //Employment information
        std::string companyName;
        std::string position;
        float annualIncome = 0;

        Person();

    public:
        //move constructor
        ~Person();
        Person(Person&& other) : firstName{std::move(other.firstName)},
                                 lastName{std::move(other.lastName)},
                                 dateOfBirth{std::move(other.dateOfBirth)},
                                 streetAddress{std::move(other.streetAddress)},
                                 postCode{std::move(other.postCode)},
                                 city{std::move(other.city)},
                                 companyName{std::move(other.companyName)},
                                 position{std::move(other.position)}, 
                                 annualIncome{std::move(other.annualIncome)} {}

        Person& operator=(Person&& other);
        static PersonBuilder build();

        friend std::ostream& operator<<(std::ostream& os, const Person& obj);
        friend class PersonBuilder;
        friend class PersonPersonalBuilder;
        friend class PersonAddressBuilder;
        friend class PersonEmploymentBuilder;
};