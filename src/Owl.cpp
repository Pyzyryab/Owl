/**
 * @brief The implementations for the declared code on the header file
 *
 * @file WexTest.cpp
 * @author Alex Vergara (pyzyryab@tutanota.com)
 * @version 0.1.3
 * @date 2022-01-15
 * @copyright Copyright (c) 2022
 */
#include "../include/Owl/Owl.hpp"

using namespace std;

bool is_power_of_two(int n)
{
    if (n < 0)
        return false;

    return (n & (n - 1)) == 0;
}

int multiply_by_two(int n)
{
    return n << 1;
}

int divide_by_two(int n)
{
    return n >> 1;
}