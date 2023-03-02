#include "Address.hpp"

std::ostream& operator<<(std::ostream& os, const Address& obj)
{
    return os 
            << "street: " 
            << obj.street 
            << ", city: " 
            << obj.city 
            << ", room: "
            << obj.room 
            << std::endl;
}