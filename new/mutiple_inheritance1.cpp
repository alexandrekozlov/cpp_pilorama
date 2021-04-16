#include <iostream>
#include <string>

class Octopus
{
    std::string name = "Octopus";

public:
    void PrintName()
    {
        std::cout << "Octopus" << std::endl;
    }
};

class Cat
{
    std::string name = "Cat";

public:
    void PrintName()
    {
        std::cout << "Cat" << std::endl;
    }
};

class Octocat : public Octopus, public Cat
{
};

int main()
{
    Octocat octocat;

    octocat.name;

    return 0;
}