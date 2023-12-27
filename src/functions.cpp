#include "include/functions.h"
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

namespace func {
    bool is_identity_1_to_n_pandigital(int multiplicand, int multiplier, int n) {
        std::string digits;
        for (int i = 1; i <= n; i++) {
            digits = digits + std::to_string(i);
        }

        std::string multiplicand_str = std::to_string(multiplicand);
        std::string multiplier_str = std::to_string(multiplier);
        std::string product_str = std::to_string(multiplicand * multiplier);
        bool is_1_to_n_pandigital = true;
        int total_digit_count = static_cast<int>(multiplicand_str.length() + multiplier_str.length() + product_str.length());

        if (total_digit_count != n) {
            is_1_to_n_pandigital = false;
        } else {
            //Checking multiplicand.
            for (char c : multiplicand_str) {
                if (digits.find(c) != std::string::npos) {
                    digits.erase(digits.find(c), 1);
                } else {
                    is_1_to_n_pandigital = false;
                }
            }

            //Checking multiplier.
            for (char c : multiplier_str) {
                if (digits.find(c) != std::string::npos) {
                    digits.erase(digits.find(c), 1);
                } else {
                    is_1_to_n_pandigital = false;
                }
            }

            //Checking product.
            for (char c : product_str) {
                if (digits.find(c) != std::string::npos) {
                    digits.erase(digits.find(c), 1);
                } else {
                    is_1_to_n_pandigital = false;
                }
            }
        }

        return is_1_to_n_pandigital;
    }
}