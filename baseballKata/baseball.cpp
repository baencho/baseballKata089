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

		for (int guessIndex = 0; guessIndex < QUESTION_LENGTH; guessIndex++) {
			for (int questionIndex = 0; questionIndex < QUESTION_LENGTH; questionIndex++) {
				if (guessNumber[guessIndex] == question[questionIndex]) {
					if (guessIndex == questionIndex) result.strikes++;
					else result.balls++;
				}
			}
		}
		if (result.strikes == QUESTION_LENGTH) result.solved = true;
		return result;
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != QUESTION_LENGTH) {
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
	const int QUESTION_LENGTH = 3;
	string question;
};