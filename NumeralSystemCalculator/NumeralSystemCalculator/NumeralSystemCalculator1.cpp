#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <stdlib.h>

char characters[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

std::string deleteLastPlus(std::string input) {
	input.erase(input.size() - 1, 1);
	std::string output = input;
	return output;
}

int findElement(char element) {
	for (int i = 0; i < sizeof(characters); i++) {
		if (characters[i] == element) {
			return i;
		}
	}
}

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

std::string buildRightSide(std::string inputNumber, int indexOfDot, int numeralSystem) {
	std::string output = "";
	int power = -1;
	for (int i = 1; i < (inputNumber.size() - indexOfDot); i++) {
		int index = (findElement(inputNumber.c_str()[i + indexOfDot]));
		output = output + std::to_string(index) + " * " + std::to_string(numeralSystem) + " ^ " + std::to_string(-i) + " + ";
		power--;
	}
	return output;
}

std::string buildLeftSide(std::string inputNumber, int indexOfDot, int numeralSystem) {
	std::string output = "";
	for (int i = 0; i < indexOfDot; i++) {
		int index = (findElement(inputNumber.c_str()[(indexOfDot - (i))-1]));

		output = std::to_string(index) + " * " + std::to_string(numeralSystem) + " ^ " + std::to_string(i) + " + " + output;
	}
	return output;
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

std::string buildResult(std::string inputNumber, int indexOfDot, int numeralSystem, bool minus) {
	std::string leftSide = buildLeftSide(inputNumber, indexOfDot, numeralSystem);
	std::string rightSide = buildRightSide(inputNumber, indexOfDot, numeralSystem);
	std::string output;
	if (indexOfDot != -1) {
		output = leftSide + rightSide;
	}
	else {
		output = revertCalculate(inputNumber, numeralSystem);
	}
	output = deleteLastPlus(output);
	if (minus) {
		output = "-(" + output + ")";
	}
	return output;
}

void sumOfTheBaseLevel(std::string inputNumber, int numeralSystem) {
	bool minus = isMinus(inputNumber);
	if (minus) {
		inputNumber.erase(0, 1);
	}
	int indexOfDot = searchDot(inputNumber);
	std::string output = buildResult(inputNumber, indexOfDot, numeralSystem, minus);
	std::cout << output << std::endl;
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
		std::cout << "Enter 0/1 (0 - for deafult calculation | 1 - for revert calculation | 2 - for tasks 1 and 2): ";
		std::cin >> functionPick;

		if (functionPick == 1) {
			revertCalculate(inputNumber, numeralSystem);
		}
		else if (functionPick == 0) {
			calculate(atoi(inputNumber.c_str()), numeralSystem);
		}
		else if (functionPick == 2) {
			sumOfTheBaseLevel(inputNumber, numeralSystem);
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