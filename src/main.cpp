#include "include/functions.h"
#include <iostream>
#include <algorithm>
#include <string>

/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once;
for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier,
and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

int main() {
    std::string digits = "123456789";
    std::string multiplicand = std::to_string(39);
    std::string multiplier = std::to_string(186);
    std::string product = std::to_string(7254);
    bool is_1_to_n_pandigital = true;

    //Checking multiplicand.
    std::cout << "Before multiplicand: " << digits << '\n';
    for (char c : multiplicand) {
        if (digits.find(c) != std::string::npos) {
            digits.erase(digits.find(c), 1);
        } else {
            is_1_to_n_pandigital = false;
        }
    }
    std::cout << "After multiplicand: " << digits << '\n';

    //Checking multiplier.
    std::cout << "Before multiplier: " << digits << '\n';
    for (char c : multiplier) {
        if (digits.find(c) != std::string::npos) {
            digits.erase(digits.find(c), 1);
        } else {
            is_1_to_n_pandigital = false;
        }
    }
    std::cout << "After multiplier: " << digits << '\n';

    //Checking product.
    std::cout << "Before product: " << digits << '\n';
    for (char c : product) {
        if (digits.find(c) != std::string::npos) {
            digits.erase(digits.find(c), 1);
        } else {
            is_1_to_n_pandigital = false;
        }
    }
    std::cout << "After product: " << digits << '\n';
    std::cout << "Is multiplicand/multiplier/product identity 1 to 9 pandigital?: " << std::boolalpha << is_1_to_n_pandigital << '\n';

    return 0;
}