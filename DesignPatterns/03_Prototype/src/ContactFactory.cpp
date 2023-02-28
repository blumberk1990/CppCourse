#include "ContactFactory.hpp"
#include <string>

Contact ContactFacotry::headquarters{ "", "", new Address{"Polanki 1", "Gdynia", 0}};
Contact ContactFacotry::poznanHQ{ "", "", new Address{"Hawelansk 6", "Poznan", 0}};

std::unique_ptr<Contact> ContactFacotry::newHqContact(const std::string name, const std::string lastName, int room) 
{
    return newContact(name, lastName, room, headquarters);
}

std::unique_ptr<Contact> ContactFacotry::newPoznanHqContact(const std::string name, const std::string lastName, int room) 
{
    return newContact(name, lastName, room, poznanHQ);
}

std::unique_ptr<Contact> ContactFacotry::newContact(const std::string name, const std::string lastName, int room, const Contact& prototype) 
{
    auto result = std::make_unique<Contact>(prototype);
    result->name = name;
    result->lastName = lastName;
    result->address->room = room; 
    return result;
}

