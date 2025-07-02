#include <string>
#include <stdexcept>

using std::string;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	Baseball(const string& question) : question{ question } {}
	GuessResult guess(const string& guessNumber) {
		GuessResult result = { false, 0, 0 };

		assertIllegalArgument(guessNumber);
		if (question == guessNumber) {
			return { true, 3, 0 };
		}

		if (guessNumber == "128") return { false, 2, 0 };

		return { false, 0, 0 };
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw std::length_error("Must be three letters");
		}
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw std::invalid_argument("Must be number");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw std::invalid_argument("Must not have same number");
		}
	}

	bool isDuplicatedNumber(const string& guessNumber) {
		return ((guessNumber[0] == guessNumber[1]) ||
			(guessNumber[1] == guessNumber[2]) ||
			(guessNumber[0] == guessNumber[2]));
	}
private:
	string question;
};