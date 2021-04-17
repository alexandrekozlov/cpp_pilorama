#include "prolog.h"

/// $name: Diamond inheritance 1
/// $keywords: polymorphism inheritance diamond
/// $level: intermediate

/// $question: Why compilation fails? How to fix it?

/// $output: compile

/// $code
class Creature
{
protected:
    const char *name = "Creature";

public:
    void PrintName()
    {
        std::cout << name << std::endl;
    }
};

class Octopus : public Creature
{
public:
    Octopus() { name = "Octopus"; }
};

class Cat : public Creature
{
public:
    Cat() { name = "Cat"; }
};

class Octocat : public Octopus, public Cat
{
public:
    Octocat() { name = "Octocat"; }
};

int main()
{
    Octocat octocat;

    octocat.PrintName();

    Cat &cat = octocat;
    cat.PrintName();

    Octopus &octopus = octocat;
    octopus.PrintName();

    Creature &creature = octocat;
    creature.PrintName();

    return 0;
}