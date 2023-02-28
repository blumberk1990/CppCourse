#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../../src/Contact.hpp"

class ContactFixture : public testing::Test {

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

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
