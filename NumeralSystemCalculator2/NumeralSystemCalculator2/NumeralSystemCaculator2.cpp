#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <stdlib.h>

int searchDot(std::string inputNumber) {
	for (int i = 0; i < inputNumber.size(); i++) {
		if (inputNumber.c_str()[i] == '.' || inputNumber.c_str()[i] == ',') {
			return i;
		}
	}
	return -1;
}
bool isMinus(std::string inputNumber) {
	if (inputNumber.c_str()[0] == '-') {
		return true;
	}
	return false;
}

void sumOfTheBaseLevel(std::string inputNumber, int numeralSystem) {	
	bool minus = isMinus(inputNumber);
	if (minus) {
		inputNumber.erase(0, 1);
	}
	int indexOfDot = searchDot(inputNumber);

	std::cout << indexOfDot << minus << std::endl << inputNumber;

}

int main() {
	std::string inputNumber;
	int numeralSystem;

	while (true) {
		std::cout << "Enter number: ";
		std::cin >> inputNumber;
		std::cout << "Enter numeral system: ";
		std::cin >> numeralSystem;
		if (inputNumber == "0") {
			break;
		}
		sumOfTheBaseLevel(inputNumber, numeralSystem);
	}
	return 0;
}