#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>

char characters[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int findElement(char element)
{
    for (int i = 0; i < sizeof(characters); i++) {
        if (characters[i] == element) {
            return i;
        }
    }

    return -1;
}

int search_dot(std::string inputNumber)
{
    for (int i = 0; i < inputNumber.size(); i++) {
        if (inputNumber.c_str()[i] == '.' || inputNumber.c_str()[i] == ',') {
            return i;
        }
    }

    return -1;
}

bool has_minus_at_start(std::string inputNumber)
{
    if (inputNumber.c_str()[0] == '-') {
        return true;
    }

    return false;
}

std::string build_right_side(std::string inputNumber, int indexOfDot, int numeralSystem)
{
    std::string output = "";
    int inputSize = inputNumber.size();
    for (int i = 1; i < (inputSize - indexOfDot); i++) {
        int index = (findElement(inputNumber.c_str()[i + indexOfDot]));
        output = output + std::to_string(index) + " * " + std::to_string(numeralSystem) + " ^ " + std::to_string(-i) +
                 " + ";
    }

    return output;
}

std::string build_left_side(std::string inputNumber, int indexOfDot, int numeralSystem)
{
    std::string output = "";

    for (int i = 0; i < indexOfDot; i++) {
        char charactersOfInput = inputNumber.c_str()[(indexOfDot - (i)) - 1];
        int index = (findElement(charactersOfInput));
        output = std::to_string(index) + " * " + std::to_string(numeralSystem) + " ^ " + std::to_string(i) + " + " +
                 output;
    }

    return output;
}

int revert_calculate_from_n_to_10(std::string inputnumber, int numeralSystem)
{
    int sum = 0;
    std::string finalString;

    for (int i = 0; inputnumber.size() - i > 0; i++) {
        char charactersOfInput = inputnumber.c_str()[inputnumber.size() - (i + 1)];
        int index = findElement(charactersOfInput);
        sum += index * pow(numeralSystem, i);
        finalString =
                std::to_string(index) + " * " + std::to_string(numeralSystem) + " ^ " + std::to_string(i) + " + " +
                finalString;
    }

    std::cout << finalString << " = " << sum << std::endl;
    std::cout << "Result is: " << sum << std::endl;

    return sum;
}

std::string build_result(std::string inputNumber, int indexOfDot, int numeralSystem, bool minus)
{
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

void sum_of_the_base_level(std::string inputNumber, int numeralSystem)
{
    bool minus = has_minus_at_start(inputNumber);

    if (minus) {
        inputNumber.erase(0, 1);
    }

    int indexOfDot = search_dot(inputNumber);
    std::string output = build_result(inputNumber, indexOfDot, numeralSystem, minus);
    std::cout << output << std::endl;
}

int calculate_from_10_to_n(int inputNumber, int numeralSystem)
{
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

    return atoi(oldCharacter.c_str());
}

int main()
{
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