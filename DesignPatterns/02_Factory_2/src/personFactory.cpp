#include "personFactory.hpp"

u_int PersonFactory::personCounter = 0;

Person PersonFactory::createPerson(const std::string& name)
{
    Person person;
    person.name = name;
    person.id = personCounter;
    personCounter++;
    return person;
}