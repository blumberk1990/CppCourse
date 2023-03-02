#include <iostream>
#include "../../src/DrinkFactory.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>


class MockDrinkFactory : public DrinkFactory {

	public:
		MOCK_METHOD(std::unique_ptr<HotDrink>, makeDrink, (std::string));
};

TEST(TestDrinkFactory, TestMakeDrinkCall) {
	MockDrinkFactory mockDrinkFactory;
	EXPECT_CALL(mockDrinkFactory, makeDrink("tea"));
	EXPECT_EQ(nullptr, mockDrinkFactory.makeDrink("tea"));
}

TEST(TestDrinkFactory, TestMakeTea) {
	MockDrinkFactory mockDrinkFactory;
	EXPECT_CALL(mockDrinkFactory, makeDrink("tea")).Times(1).WillOnce(testing::Return(testing::ByMove(std::make_unique<Tea>())));
	std::unique_ptr<HotDrink> drink;
	drink = mockDrinkFactory.makeDrink("tea");
	drink->prepare(150);
}

TEST(TestDrinkFactory, TestMakeCoffee) {
	MockDrinkFactory mockDrinkFactory;
	EXPECT_CALL(mockDrinkFactory, makeDrink("coffee")).Times(1).WillOnce(testing::Return(testing::ByMove(std::make_unique<Coffee>())));
	std::unique_ptr<HotDrink> drink;
	drink = mockDrinkFactory.makeDrink("coffee");
	drink->prepare(150);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
