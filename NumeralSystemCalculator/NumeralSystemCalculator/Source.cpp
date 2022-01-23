#include <iostream>
#include <string>

void calculateLess10(int inputnumber, int numeralSystem) {
	std::string newCharacter = "";
	std::string oldCharacter = "";
	std::string temp;
	for (inputnumber; (inputnumber + numeralSystem) > numeralSystem; inputnumber = inputnumber / numeralSystem) {
		temp = oldCharacter;
		newCharacter = std::to_string(inputnumber % numeralSystem);
		oldCharacter = newCharacter + temp;
		std::cout << inputnumber << " div " << numeralSystem << " = " << inputnumber / numeralSystem << std::endl;
		std::cout << inputnumber << " mod " << numeralSystem << " = " << newCharacter << std::endl;
		std::cout << "\n";
	}
	std::cout << "Result is: " << oldCharacter;
}


int main() {
	int numeralSystem;
	int inputNumber;
	std::cout << "Enter input number: ";
	std::cin >> inputNumber;
	std::cout << "Enter numberl system: ";
	std::cin >> numeralSystem;
	calculateLess10(inputNumber, numeralSystem);

	//std::cout << inputNumber << numeralSystem;
	return 0;
}