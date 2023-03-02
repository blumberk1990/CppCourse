#pragma once
#include <string>
#include <iostream>

#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

class Address
{
    private:
        //std::string street;
        //std::string city;
        //int room;
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive& ar, const unsigned version) 
        {
            ar & street;
            ar & city;
            ar & room;
        }
    public:
        std::string street;
        std::string city;
        int room;
        Address() {}
        Address(const std::string& street, const std::string& city, const int room)
        : street{street},
          city{city},
          room{room} {}

        friend std::ostream& operator<<(std::ostream& os, const Address& obj);
};