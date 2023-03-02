#include "Contact.hpp"

Contact& Contact::operator=(const Contact& other)
{
    if(this == &other)
        return *this;
    name = other.name;
    lastName = other.lastName;
    address = other.address;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Contact& obj)
{
    return os 
            << "name: " 
            << obj.name 
            << ", last name: " 
            << obj.lastName 
            << ", address: \n"
            << *obj.address 
            << std::endl;
}