#pragma once
#include <models/src/Person.h> 

class PersonPersonalBuilder;
class PersonAddressBuilder;
class PersonEmploymentBuilder;

class PersonBuilderBase
{
    protected:
        Person& person; //Reference to the builded object
        explicit PersonBuilderBase(Person& person) : person(person) {}
    public:
        operator Person();
        // builder facets
        PersonPersonalBuilder is() const;
        PersonAddressBuilder lives() const;
        PersonEmploymentBuilder works() const;
};

//class dedicated to use as initializer of builder config process
class PersonBuilder : public PersonBuilderBase
{
    private:
        Person p;   //Real builded object
    public:
        PersonBuilder() : PersonBuilderBase{p} {}
};