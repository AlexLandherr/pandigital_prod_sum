#include "include/functions.h"
#include <iostream>

/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once;
for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier,
and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

int main() {
    //std::cout << std::boolalpha << func::is_identity_1_to_n_pandigital(39, 186, 9) << '\n';
    int n = 9;
    std::cout << "The sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital is:" << '\n';
    std::cout << func::product_sum(n) << '\n';

    return 0;
}