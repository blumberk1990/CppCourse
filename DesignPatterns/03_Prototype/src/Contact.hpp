#pragma once
#include <string>
#include "Address.hpp"

class Contact
{
    private:
        //std::string name;
        //std::string lastName;
        //Address*    address;
    public:
        std::string name;
        std::string lastName;
        Address*    address;
        Contact(const std::string& name, const std::string lastName, Address* address)
        : name{name},
          lastName{lastName},
          address{address} {}
        Contact(const Contact& other)
        : name{other.name},
          lastName{other.lastName},
          address{new Address{*other.address}} {} // Address class should have copy constructor as well
        Contact& operator=(const Contact& other)
        {
            if(this == &other)
                return *this;
            name = other.name;
            lastName = other.lastName;
            address = other.address;
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Contact& obj) {
            return os 
                    << "name: " 
                    << obj.name 
                    << ", last name: " 
                    << obj.lastName 
                    << ", address: \n"
                    << *obj.address 
                    << std::endl;
        }
};