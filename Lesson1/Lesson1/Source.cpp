#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <string>

void goul() {
	for (int i = 1000; i > 0; i = i - 7) {
		std::cout << i << " - 7 = " << i - 7 << std::endl;
	}
}

double calculator() {
	int x1;
	int x2;
	std::string input;
	double output = 0;
	std::cout << "Enter x1: \n";
	std::cin >> x1;
	std::cout << "Enter sign: \n";
	std::cin >> input;
	std::cout << "Enter x2: \n";
	std::cin >> x2;
	std::cout << x1 << input << x2 << std::endl;

	return output;
}
int main(){
	calculator();
	return 1;
}