#pragma once

#include <iostream>
#include <iomanip>
#include <cstring>
#include <exception>

#define EXPECT_TRUE(actual) \
    ExpectEqImpl(actual, true, #actual)

#define EXPECT_FALSE(actual) \
    ExpectEqImpl(actual, false, #actual)

#define EXPECT_EQ(actual, expected) \
    ExpectEqImpl(actual, expected, #actual)


void ExpectEqImpl(const char *actual, const char *expected, const char *context = nullptr)
{
    if (context)
        std::cout << context << " : ";

    if(std::strcmp(actual, expected) == 0)
    {
        std::cout << "PASS" << std::endl;
    }
    else
    {
        std::cout << "FAIL\n"
                  << "        Expected: " << expected << "\n"
                  << "          Actual: " << actual << std::endl;
    }    
}

template<typename T>
void SetOutputFormat(T) {}

template<>
void SetOutputFormat(bool)
{
    std::cout.setf(std::ios_base::boolalpha);
}

template<typename T>
void ExpectEqImpl(T actual, T expected, const char *context = nullptr)
{
    if (context)
        std::cout << context << " : ";

    if(actual == expected)
    {
        std::cout << "PASS" << std::endl;
    }
    else
    {
        SetOutputFormat(actual);
        std::cout << "FAIL\n"
                  << "        Expected: " << expected << "\n"
                  << "          Actual: " << actual << std::endl;
    }    
}

