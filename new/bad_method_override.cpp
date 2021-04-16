#include <iostream>
#include <cstring>

void ExpectEq(const char *actual, const char *expected)
{
    if(std::strcmp(actual, expected) == 0)
    {
        std::cout << "PASS" << std::endl;
    }
    else
    {
        std::cout << "FAIL" << std::endl;
        std::cout << "        Expected: " << expected << "\n"
                << "          Actual: " << actual << std::endl;
    }    
}

class Animal
{
public:
    const char *Says() const 
    { 
        return "<nothing>";
    }
};

class Cat : public Animal
{
public:
    const char *Says() const
    {
        return "Meow!";
    }
};

int main()
{
    Animal *animal = new Cat();

    ExpectEq(animal->Says(), "Meow!");

    return 0;
}
