#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <sstream>
#include <math.h>

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

    return -1;
}

bool has_minus_at_start(std::string inputNumber) {
    if (inputNumber.c_str()[0] == '-') {
        return true;
    }

    return false;
}

std::string build_right_side(std::string inputNumber, int indexOfDot, int numeralSystem) {
    std::string output = "";
    int inputSize = inputNumber.size();
    double sum = 0;

    for (int i = 1; i < (inputSize - indexOfDot); i++) {
        int index = (find_element(inputNumber.c_str()[i + indexOfDot]));
        sum += index * pow(numeralSystem, -i);
        output = output + std::to_string(index) + " * " + std::to_string(numeralSystem) + " ^ " + std::to_string(-i) +
                 " + ";
    }

    std::cout << sum << std::endl;

    return output;
}

std::string build_left_side(std::string inputNumber, int indexOfDot, int numeralSystem) {
    std::string output = "";
    int sum = 0;

    for (int i = 0; i < indexOfDot; i++) {
        char charactersOfInput = inputNumber.c_str()[(indexOfDot - (i)) - 1];
        int index = (find_element(charactersOfInput));
        sum += index * pow(numeralSystem, i);
        output = std::to_string(index) + " * " + std::to_string(numeralSystem) + " ^ " + std::to_string(i) + " + " +
                 output;
    }

    std::cout << sum << std::endl;

    return output;
}

int revert_calculate_from_n_to_10(std::string inputNumber, int numeralSystem) {
    int sum = 0;
    std::string finalString;

    for (int i = 0; inputNumber.size() - i > 0; i++) {
        char charactersOfInput = inputNumber.c_str()[inputNumber.size() - (i + 1)];
        int index = find_element(charactersOfInput);
        sum += index * pow(numeralSystem, i);
        finalString =
                std::to_string(index) + " * " + std::to_string(numeralSystem) + " ^ " + std::to_string(i) + " + " +
                finalString;
    }

    std::cout << finalString << " = " << sum << std::endl;
    std::cout << "Result is: " << sum << std::endl;

    return sum;
}

std::string build_result(std::string inputNumber, int indexOfDot, int numeralSystem, bool minus) {
    std::string leftSide = build_left_side(inputNumber, indexOfDot, numeralSystem);
    std::string rightSide = build_right_side(inputNumber, indexOfDot, numeralSystem);
    std::string output;

    if (indexOfDot != -1) {
        output = leftSide + rightSide;
    } else {
        output = revert_calculate_from_n_to_10(inputNumber, numeralSystem);
    }

    if (minus) {
        output = "-(" + output + ")";
    }

    return output;
}

void sum_of_the_base_level(std::string inputNumber, int numeralSystem) {
    bool minus = has_minus_at_start(inputNumber);

    if (minus) {
        inputNumber.erase(0, 1);
    }

    int indexOfDot = search_dot(inputNumber);
    std::string output = build_result(inputNumber, indexOfDot, numeralSystem, minus);
    std::cout << output << std::endl;
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
    std::string output = "";
    int indexOfDot = search_dot(inputNumber);
    std::stringstream intValue(build_left_side_4_calculation(inputNumber, numeralSystem, indexOfDot));
    int leftSide;
    intValue >> leftSide;

    std::string leftSideAfterCalculation = calculate_from_10_to_n(leftSide, numeralSystem);

    std::string rightSide = build_right_side_4_calculator(inputNumber, numeralSystem, indexOfDot);

    std::string rightSideAfterCalculation = calculate_right_side(rightSide, numeralSystem);

    output = leftSideAfterCalculation + "." + rightSideAfterCalculation;

    std::cout << "\nResult is: " << output << std::endl;

    return output;
}

std::string calculate_sum(std::string number1, std::string number2, int numeralSystem) {
    int number1in10 = revert_calculate_from_n_to_10(number1, numeralSystem);
    int number2in10 = revert_calculate_from_n_to_10(number2, numeralSystem);

    int sumIn10 = number1in10 + number2in10;

    std::string sumInN = calculate_from_10_to_n(sumIn10, numeralSystem);
    std::cout << "\n" << number1 << " + " << number2 << " (" << numeralSystem << ") = " << number1in10 << " + "
              << number2in10
              << " (10) = " << sumIn10 << " (10) = " << sumInN << " (" << numeralSystem << ")" << std::endl;

    return sumInN;
}

std::string calculate_multiplication(std::string number1, std::string number2, int numeralSystem) {
    int number1in10 = revert_calculate_from_n_to_10(number1, numeralSystem);
    int number2in10 = revert_calculate_from_n_to_10(number2, numeralSystem);

    int multiplicationIn10 = number1in10 * number2in10;

    std::string multiplicationInN = calculate_from_10_to_n(multiplicationIn10, numeralSystem);
    std::cout << "\n" << number1 << " * " << number2 << " (" << numeralSystem << ") = " << number1in10 << " * "
              << number2in10
              << " (10) = " << multiplicationIn10 << " (10) = " << multiplicationInN << " (" << numeralSystem << ")"
              << std::endl;

    return multiplicationInN;
}

int main() {
    int numeralSystem;
    int functionPick;
    std::string inputNumber;

    while (true) {
        std::cout << "Enter input number: ";
        std::cin >> inputNumber;

        if (inputNumber == "0") {
            break;
        }
        std::cout << "Enter numeral system: ";
        std::cin >> numeralSystem;

        std::cout << "Enter 0/1 (0 - for default calculation | 1 - for revert calculation | 2 - for tasks 1 and 2): ";
        std::cin >> functionPick;

        if (functionPick == 1) {
            revert_calculate_from_n_to_10(inputNumber, numeralSystem);
        } else if (functionPick == 0) {
            calculate_from_10_to_n(atoi(inputNumber.c_str()), numeralSystem);
        } else if (functionPick == 2) {
            sum_of_the_base_level(inputNumber, numeralSystem);
        } else if (functionPick == 3) {
            calculate_from_10_to_n_double(inputNumber, numeralSystem);
        } else if (functionPick == 4) {
            std::string secondInputNumber;
            std::cout << "Enter second number: ";
            std::cin >> secondInputNumber;
            calculate_sum(inputNumber, secondInputNumber, numeralSystem);
        } else if (functionPick == 5) {
            std::string secondInputNumber;
            std::cout << "Enter second number: ";
            std::cin >> secondInputNumber;
            calculate_multiplication(inputNumber, secondInputNumber, numeralSystem);
        } else if (functionPick == 108) {
            int newNumeralSystem;
            std::cout << "Enter second numeral system: ";
            std::cin >> newNumeralSystem;
            int temp = revert_calculate_from_n_to_10(inputNumber, numeralSystem);
            calculate_from_10_to_n(temp, newNumeralSystem);
        } else {
            std::cout << "Fucking idiot please enter only 0, 1, 2 !!!!!!";
        }
    }

    return 0;
}