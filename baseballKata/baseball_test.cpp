#include "gmock/gmock.h"
#include "baseball.cpp"

TEST(BaseballGame, ThrowExcpetionWhenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), std::length_error);
}

TEST(BaseballGame, ThrowExceptionWhenInvalidChar) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), std::invalid_argument);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}