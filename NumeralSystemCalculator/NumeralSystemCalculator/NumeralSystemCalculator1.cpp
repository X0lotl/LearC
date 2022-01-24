#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <stdlib.h>

char characters[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

int findElement(char element) {
	for (int i = 0; i < sizeof(characters); i++) {
		if (characters[i] == element) {
			return i;
		}
	}
}

int revertCalculate(std::string inputnumber, int numeralSystem) {
	int sum = 0;
	std::string finalString;
	for (int i = 0; inputnumber.size() - i > 0; i++) {
	int index = (findElement(inputnumber.c_str()[inputnumber.size() - (i + 1)]));
		sum += index * pow(numeralSystem, i);
		finalString = std::to_string(index) + " * " + std::to_string(numeralSystem) + " ^ " + std::to_string(i) + " + " + finalString;
	}
	std::cout << finalString << " = " << sum << std::endl;
	std::cout << "Result is: " << sum << std::endl;
	return sum;
}

int calculate(int inputnumber, int numeralSystem) {
	std::string newCharacter = "";
	std::string oldCharacter = "";
	std::string temp;
	for (; (inputnumber + numeralSystem) > numeralSystem; inputnumber /= numeralSystem) {
		temp = oldCharacter;
		newCharacter = characters[inputnumber % numeralSystem];
		oldCharacter = newCharacter + temp;
		std::cout << inputnumber << " div " << numeralSystem << " = " << inputnumber / numeralSystem << std::endl;
		std::cout << inputnumber << " mod " << numeralSystem << " = " << newCharacter << std::endl;
		std::cout << "\n";
	}
	std::cout << "Result is: " << oldCharacter;
	return atoi(oldCharacter.c_str());
}

int main() {
	int numeralSystem;
	int functionPick;
	std::string inputNumber;
	while (true)
	 {
		std::cout << "Enter input number: ";
		std::cin >> inputNumber;
		if (inputNumber == "0") {
			break;
		}

		std::cout << "Enter numberal system: ";
		std::cin >> numeralSystem;
		std::cout << "Enter 0/1 (0 - for deafult calculation | 1 - for revert calculation): ";
		std::cin >> functionPick;

		if (functionPick == 1) {
			revertCalculate(inputNumber, numeralSystem);
		}
		else if (functionPick == 0) {
			calculate(atoi(inputNumber.c_str()), numeralSystem);
		}
		else if (functionPick == 108) {
			int newNumeralSystem;
			std::cout << "Enter second numeral system: ";
			std::cin >> newNumeralSystem;
			int temp = revertCalculate(inputNumber, numeralSystem);
			calculate(temp, newNumeralSystem);
		}
		else {
			std::cout << "Fucking idiot plese enter 0 or 1 !!!!!!";
		}		
	}
	return 0;
}