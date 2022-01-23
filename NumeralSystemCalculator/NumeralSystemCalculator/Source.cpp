#include <iostream>
#include <string>
#include <cmath>

char characters[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
int findElement(char element) {
	for (int i = 0; i < sizeof(characters); i++) {
		if (characters[i] == element) {
			return i;
		}
	}
}

void revertCalculate(std::string inputnumber, int numeralSystem) {
	int sum = 0;
	for (int i = 0; inputnumber.size() - i > 0; i++) {		
		int index = (findElement(inputnumber.c_str()[inputnumber.size() - (i - 1)]));
		sum += index * pow(numeralSystem, i);
	}
	std::cout << "Result is: " << sum << std::endl;
}

void calculate(int inputnumber, int numeralSystem) {
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
}


int main() {
	int numeralSystem;
	std::string inputNumber;
	std::cout << "Enter input number: ";
	std::cin >> inputNumber;
	std::cout << "Enter numberal system: ";
	std::cin >> numeralSystem;
	//calculate(inputNumber, numeralSystem);

	revertCalculate(inputNumber, numeralSystem);
	//std::cout << inputNumber << numeralSystem;
	return 0;
}