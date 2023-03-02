#pragma once
#include <memory>
#include <string>
#include "Contact.hpp"

class ContactFacotry
{
    private:
        static Contact headquarters;
        static Contact poznanHQ;
    public:
        static std::unique_ptr<Contact> newHqContact(const std::string name, const std::string lastName, int room);
        static std::unique_ptr<Contact> newPoznanHqContact(const std::string name, const std::string lastName, int room);
        static std::unique_ptr<Contact> newContact(const std::string name, const std::string lastName, int room, const Contact& prototype);
};