#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "../../src/Contact.hpp"
#include "../../src/ContactFactory.hpp"

class ContactFixture : public testing::Test {

};

class ContactFactoryFixture : public testing::Test {

};

class ContactSerializationFixture : public testing::Test {

};

TEST_F(ContactFixture, SimpleObjectCreateTest) {
	Contact janek{"Janek", "Zdunek", new Address{"Polanki 1", "Gdynia", 12}};
	ASSERT_EQ("Janek", janek.name);
	ASSERT_EQ("Zdunek", janek.lastName);
	ASSERT_EQ("Polanki 1", janek.address->street);
	ASSERT_EQ("Gdynia", janek.address->city);
	ASSERT_EQ(12, janek.address->room);
	std::cout << "Created Contact object, is fine." << std::endl;
}

TEST_F(ContactFixture, SimplePrototypeAssignmentOperatorTest) {
	Contact janek{"Janek", "Zdunek", new Address{"Polanki 1", "Gdynia", 12}};
	ASSERT_EQ(12, janek.address->room);
	std::cout << "Room of created Contact object, is fine. " << janek.address->room << std::endl;
	Contact zenek = janek;
	zenek.name = "Zenek";
	zenek.address->room = 55;
	ASSERT_EQ(55, zenek.address->room);
	std::cout << "Contact object created via assignment operator, is fine." << zenek.address->room << std::endl;
}

TEST_F(ContactFixture, SimplePrototypeCopyConstructorTest) {
	Contact janek{"Janek", "Zdunek", new Address{"Polanki 1", "Gdynia", 12}};
	ASSERT_EQ(12, janek.address->room);
	std::cout << "Room of created Contact object, is fine. " << janek.address->room << std::endl;
	Contact mietek{janek};
	mietek.name = "Mietek";
	mietek.address->room = 77;
	ASSERT_EQ(77, mietek.address->room);
	std::cout << "Contact object created via copy constructor, is fine." << mietek.address->room << std::endl;
}

TEST_F(ContactFactoryFixture, SimplePrototypeHqFactoryTest) {
	auto wiktor = ContactFacotry::newHqContact("Wiktor", "Janiak", 111);
	ASSERT_EQ("Polanki 1", wiktor->address->street);
	ASSERT_EQ("Gdynia", wiktor->address->city);
	std::cout << "Contact object created via ContactFactory, is fine.\n" << *wiktor << std::endl;
}

TEST_F(ContactFactoryFixture, SimplePrototypePoznanHqFactoryTest) {
	auto robert = ContactFacotry::newPoznanHqContact("Robert", "Janiak", 112);
	ASSERT_EQ("Hawelansk 6", robert->address->street);
	ASSERT_EQ("Poznan", robert->address->city);
	std::cout << "Contact object created via ContactFactory, is fine.\n" << *robert << std::endl;
}

TEST_F(ContactSerializationFixture, SimpleSerializationTest) {
	//lambda could be change to save in file!!
	auto clone = [](const Contact& contact)
	{
		//Serialization
		std::ostringstream oss;
		boost::archive::text_oarchive oa(oss);
		oa << contact;
		std::string s = oss.str();
		std::cout << s <<std::endl;

		//Deserialization
		std::istringstream iss(s);
		boost::archive::text_iarchive ia(iss);
		Contact deserializeContact;
		ia >> deserializeContact;
		return deserializeContact;
	};
	auto marian     = ContactFacotry::newPoznanHqContact("Marian", "Nowak", 753);
	auto marianna   = clone(*marian);
	marianna.name = "Marianna";
	ASSERT_EQ("Hawelansk 6", marianna.address->street);
	ASSERT_EQ("Poznan", marianna.address->city);
	ASSERT_EQ("Marianna", marianna.name);
	ASSERT_EQ("Nowak", marianna.lastName);
	
	std::cout << "Contact object created via Serialization, is fine.\n" << marianna << std::endl;
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
