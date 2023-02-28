#pragma once
#include <string>

class Address
{
    private:
        //std::string street;
        //std::string city;
        //int room;
    public:
        std::string street;
        std::string city;
        int room;
        Address(const std::string& street, const std::string& city, const int room)
        : street{street},
          city{city},
          room{room} {}

        friend std::ostream& operator<<(std::ostream& os, const Address& obj) {
            return os 
                    << "street: " 
                    << obj.street 
                    << ", city: " 
                    << obj.city 
                    << ", room: "
                    << obj.room 
                    << std::endl;
        }
};