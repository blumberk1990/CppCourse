#pragma once
#include <string>
#include "Address.hpp"

#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

class Contact
{
    private:
        //std::string name;
        //std::string lastName;
        //Address*    address;
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive& ar, const unsigned version) 
        {
            ar & name;
            ar & lastName;
            ar & address;
        }
    public:
        std::string name;
        std::string lastName;
        Address*    address;
        Contact() {}
        Contact(const std::string& name, const std::string lastName, Address* address)
        : name{name},
          lastName{lastName},
          address{address} {}
        Contact(const Contact& other)
        : name{other.name},
          lastName{other.lastName},
          address{new Address{*other.address}} {} // Address class should have copy constructor as well
        Contact& operator=(const Contact& other);
        friend std::ostream& operator<<(std::ostream& os, const Contact& obj);
};