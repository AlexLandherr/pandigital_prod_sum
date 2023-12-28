#include "include/functions.h"
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

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

    int64_t product_sum(int n) {
        std::vector<int64_t> valid_products;
        
        //1 <= x <= 9 and 1000 <= y <= 9999.
        for (int64_t x = 1; x <= 9; x++) {
            for (int64_t y = 1000; y <= 9999; y++) {
                //Checking if identity is pandigital and whether the resulting product has been encountered before.
                if (is_identity_1_to_n_pandigital(x, y, n) && !(std::find(valid_products.begin(), valid_products.end(), (x * y)) != valid_products.end())) {
                    valid_products.push_back(x * y);
                }
            }
        }

        //10 <= x <= 99 and 100 <= y <= 999.
        for (int64_t x = 10; x <= 99; x++) {
            for (int64_t y = 100; y <= 999; y++) {
                //Checking if identity is pandigital and whether the resulting product has been encountered before.
                if (is_identity_1_to_n_pandigital(x, y, n) && !(std::find(valid_products.begin(), valid_products.end(), (x * y)) != valid_products.end())) {
                    valid_products.push_back(x * y);
                }
            }
        }

        //Calculating the sum of all valid products.
        return std::accumulate(valid_products.begin(), valid_products.end(), 0);
    }
}