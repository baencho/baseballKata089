#include <string>
#include <stdexcept>

using std::string;

class Baseball {
public:
	void guess(const string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw std::length_error("Must be three letters");
		}
		for (char ch : guessNumber) {
			if (ch < '0' || ch > '9') {
				throw std::invalid_argument("Must be number");
			}
		}
		if ((guessNumber[0] == guessNumber[1]) ||
			(guessNumber[1] == guessNumber[2]) ||
			(guessNumber[0] == guessNumber[2])) {
			throw std::invalid_argument("Must not have same number");
		}
	}
};