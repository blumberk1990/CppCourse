#include <memory>
#include "Contact.hpp"
#include "ContactFactory.hpp"
#include <iostream>

#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

int main()
{
    // in case of a = b cause problem due to share address!!
    // to avoid the problem we have to create copy constructor 
    // or just copy all the elements manualy
    Contact janek{"Janek", "Zdunek", new Address{"Polanki 1", "Gdynia", 12}};
    Contact zenek = janek;
    zenek.name = "Zenek";
    zenek.address->room = 55;
    Contact mietek{zenek};
    mietek.name = "Mietek";
    mietek.address->room = 77; 
    std::cout<< "Janek: \n" << janek <<std::endl;
    std::cout<< "Zenek: \n" << zenek <<std::endl;
    std::cout<< "Mietek: \n" << mietek <<std::endl;

    // Contact factory, cause of static members could be called without object instance
    auto wiktor = ContactFacotry::newHqContact("Wiktor", "Janiak", 111);
    auto robert = ContactFacotry::newPoznanHqContact("Robert", "Janiak", 112);
    std::cout<< *wiktor << std::endl;
    std::cout<< *robert << std::endl;


    auto clone = [](const Contact& contact)
    {
        std::ostringstream oss;
        boost::archive::text_oarchive oa(oss);
        oa << contact;
        std::string s = oss.str();
        std::cout << s <<std::endl;

        std::istringstream iss(s);
        boost::archive::text_iarchive ia(iss);
        Contact deserializeContact;
        ia >> deserializeContact;
        return deserializeContact;
    };
    auto marian     = ContactFacotry::newPoznanHqContact("Marian", "Nowak", 753);
    auto marianna   = clone(*marian);
    marianna.name = "Marianna";
    std::cout << *marian << std::endl;
    std::cout << marianna << std::endl;
    
}