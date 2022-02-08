#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <sstream>

char characters[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                       'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int find_element(char element) {
    for (int i = 0; i < sizeof(characters); i++) {
        if (characters[i] == element) {
            return i;
        }
    }

    return -1;
}

int search_dot(std::string inputNumber) {
    for (int i = 0; i < inputNumber.size(); i++) {
        if (inputNumber.c_str()[i] == '.' || inputNumber.c_str()[i] == ',') {
            return i;
        }
    }

    return inputNumber.length();
}

bool has_minus_at_start(std::string inputNumber) {
    if (inputNumber.c_str()[0] == '-') {
        return true;
    }

    return false;
}

int build_left_side(std::string inputNumber, int indexOfDot, int numeralSystem, bool minus) {
    std::string output = "";
    int sum = 0;

    for (int i = 0; i < indexOfDot; i++) {
        char charactersOfInput = inputNumber.c_str()[(indexOfDot - (i)) - 1];
        int index = (find_element(charactersOfInput));
        if (minus) {
            sum -= index * pow(numeralSystem, i);
            output = " - " + std::to_string(index) + " * " + std::to_string(numeralSystem) + " ^ " + std::to_string(i) +
                     output;
        } else {
            sum += index * pow(numeralSystem, i);
            output = " + " + std::to_string(index) + " * " + std::to_string(numeralSystem) + " ^ " + std::to_string(i) +
                     output;
        }
    }
    std::cout << output;

    return sum;
}

double build_right_side(std::string inputNumber, int indexOfDot, int numeralSystem, bool minus) {
    std::string output = "";
    int inputSize = inputNumber.size();
    double sum = 0;

    for (int i = 1; i < (inputSize - indexOfDot); i++) {
        int index = (find_element(inputNumber.c_str()[i + indexOfDot]));
        if (minus) {
            sum -= index * pow(numeralSystem, -i);
            output = output + " - " + std::to_string(index) + " * " + std::to_string(numeralSystem) + " ^ " +
                     std::to_string(-i);
        } else {
            sum += index * pow(numeralSystem, -i);
            output = output + " + " + std::to_string(index) + " * " + std::to_string(numeralSystem) + " ^ " +
                     std::to_string(-i);
        }
    }
    std::cout << output;

    return sum;
}


double build_result(std::string inputNumber, int indexOfDot, int numeralSystem, bool minus) {

    int leftSideInt = build_left_side(inputNumber, indexOfDot, numeralSystem, minus);
    double rightSideDouble = build_right_side(inputNumber, indexOfDot, numeralSystem, minus);
    double output = leftSideInt + rightSideDouble;

    return output;
}

std::string sum_of_the_base_level(std::string inputNumber, int numeralSystem) {
    bool minus = has_minus_at_start(inputNumber);

    if (minus) {
        inputNumber.erase(0, 1);
    }

    int indexOfDot = search_dot(inputNumber);
    std::string output = std::to_string(build_result(inputNumber, indexOfDot, numeralSystem, minus));
    std::cout << " = " << output << std::endl;

    return output;
}

std::string calculate_from_10_to_n(int inputNumber, int numeralSystem) {
    std::string newCharacter = "";
    std::string oldCharacter = "";
    std::string temp;

    for (; (inputNumber + numeralSystem) > numeralSystem; inputNumber /= numeralSystem) {
        temp = oldCharacter;
        newCharacter = characters[inputNumber % numeralSystem];
        oldCharacter = newCharacter + temp;
        std::cout << inputNumber << " div " << numeralSystem << " = " << inputNumber / numeralSystem << std::endl;
        std::cout << inputNumber << " mod " << numeralSystem << " = " << newCharacter << std::endl;
        std::cout << "\n";
    }

    std::cout << "Result is: " << oldCharacter;

    return oldCharacter;
}

std::string build_left_side_4_calculation(std::string inputNumber, int numeralSystem, int placeOfDot) {
    std::string output = "";
    for (int i = 0; i < placeOfDot; i++) {
        output = output + inputNumber.c_str()[i];
    }

    return output;
}

std::string build_right_side_4_calculator(std::string inputNumber, int numeralSystem, int placeOfDot) {
    std::string output = "";
    for (int i = placeOfDot + 1; i < inputNumber.size(); i++) {
        output = output + inputNumber.c_str()[i];
    }

    return output;
}

std::string calculate_right_side(std::string inputNumber, int numeralSystem) {
    std::cout << "\n";
    std::stringstream doubleValue("0." + inputNumber);
    double inputDouble;
    double newCharacterDouble;
    doubleValue >> inputDouble;
    std::string output = "";
    int newCharacterInt;

    while (inputDouble != 0) {
        std::cout << inputDouble << " * " << numeralSystem << " = ";
        inputDouble = inputDouble * numeralSystem;
        std::cout << inputDouble << std::endl;
        inputDouble = modf(inputDouble, &newCharacterDouble);
        newCharacterInt = newCharacterDouble;
        output = output + characters[newCharacterInt];
    }

    std::cout << "Result is: " << output << std::endl;

    return output;
}

std::string calculate_from_10_to_n_double(std::string inputNumber, int numeralSystem) {
    bool minus = has_minus_at_start(inputNumber);

    if (minus) {
        inputNumber.erase(0, 1);
    }

    int indexOfDot = search_dot(inputNumber);
    std::string output = "";
    int leftSide;

    std::stringstream intValue(build_left_side_4_calculation(inputNumber, numeralSystem, indexOfDot));
    intValue >> leftSide;

        std::string leftSideAfterCalculation = calculate_from_10_to_n(leftSide, numeralSystem);

        std::string rightSide = build_right_side_4_calculator(inputNumber, numeralSystem, indexOfDot);

        std::string rightSideAfterCalculation = calculate_right_side(rightSide, numeralSystem);

        output = leftSideAfterCalculation + "." + rightSideAfterCalculation;

        if (minus) {
            output = "-" + output;
        }

    std::cout << "\nResult is: " << output << std::endl;

    return output;
}

void calculate_from_n_to_p(std::string inputNumber, int firstNumeralSystem, int secondNumeralSystem) {
    std::string inputNumberAfterConvertIn10Radix = sum_of_the_base_level(inputNumber, firstNumeralSystem);
    calculate_from_10_to_n_double(inputNumberAfterConvertIn10Radix, secondNumeralSystem);
}

int main() {
    int firstNumeralSystem;
    int secondNumeralSystem;
    std::string inputNumber;

    while (true) {
        std::cout << "Enter first number: ";
        std::cin >> inputNumber;

        if (inputNumber == "0") {
            break;
        }
        std::cout << "Enter numeral system for first number: ";
        std::cin >> firstNumeralSystem;

        std::cout << "Enter numeral system for output: ";
        std::cin >> secondNumeralSystem;

        calculate_from_n_to_p(inputNumber, firstNumeralSystem, secondNumeralSystem);
    }

    return 0;
}