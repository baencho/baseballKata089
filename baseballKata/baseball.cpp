#include <string>
#include <stdexcept>

using std::string;

class Baseball {
public:
	void guess(const string& str) {
		if (str.length() != 3) {
			throw std::length_error("Must be there letters");
		}
	}
};