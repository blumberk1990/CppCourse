#include <iostream>
#include "../../src/personFactory.hpp"
#include <gtest/gtest.h>

class PersonFactoryFixture : public testing::Test {

};

TEST_F(PersonFactoryFixture, SimplePersonNameFieldTest) {
	PersonFactory personFactory;
	auto person = personFactory.createPerson("Thomas");
	ASSERT_EQ("Thomas", person.name);
	std::cout << "Name field of created Person object, is fine." << std::endl;
}

TEST_F(PersonFactoryFixture, SimplePersonIdFieldTest) {
	PersonFactory personFactory;
	auto person1 = personFactory.createPerson("Thomas");
	ASSERT_EQ(1, person1.id);
	std::cout << "Id field of created Person object, is fine." << person1.id << std::endl;
	auto person2 = personFactory.createPerson("Justin");
	ASSERT_EQ(2, person2.id);
	std::cout << "Id field of created Person object, is fine." << person2.id << std::endl;
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
