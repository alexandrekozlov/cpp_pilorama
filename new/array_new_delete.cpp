#include "prolog.h"

/// $name: Array new/delete
/// $categories: memory
/// $level: beginner
/// $output: both

/// $code

class ComplexClass
{
public:
    std::string value;
};

int main()
{
    char *items = new char[1000];
    auto *s = new ComplexClass[2];
    s[1].value = "test";

    delete s;
    delete items;

    return 0;
}
