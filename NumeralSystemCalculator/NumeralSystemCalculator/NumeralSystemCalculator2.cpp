#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <stdlib.h>

int searchDot(std::string inputNumber) {
	for (int i = 0; i < inputNumber.size(); i++) {
		if (inputNumber.c_str()[i] == '.') {
			return i;
		}
	}
	return -1;
}

void sumOfTheBaseLevel(std::string inputNumber, int numeralSystem) {
	int indexOfDot = searchDot(inputNumber);
	std::cout << indexOfDot;
}

int main2(){
	std::string inputNumber;
	int numeralSystem;

	while(true) {
		std::cout << "Enter number: ";
		std::cin >> inputNumber;
		std::cout << "Enter number: ";
		std::cin >> numeralSystem;
		if (inputNumber == "0") {
			break;
		}
		sumOfTheBaseLevel(inputNumber, numeralSystem);
	}
return 0;
}