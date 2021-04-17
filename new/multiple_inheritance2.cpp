#include "prolog.h"

/// $name: Diamond inheritance 2
/// $category: polymorphism inheritance diamond
/// $level: intermediate

/// $question: Why it fails?

/// $output: run

/// $code
class Creature
{
private:
    const char *name = "Creature";
    int limbs = 0;

public:
    Creature(const char *name, int limbs)
        : name(name), limbs(limbs)
    {
    }

    const char *Name()
    {
        return name;
    }

    int Limbs()
    {
        return limbs;
    }
};

class Octopus : virtual public Creature
{
public:
    Octopus() : Creature("Octopus", 8) {}
};

class Cat : public Creature
{
public:
    Cat() : Creature("Cat", 4) {}
};

class Octocat : public Octopus, public Cat
{
public:
    Octocat() : Creature("Octocat", 6), Octopus(), Cat() {}
};

int main()
{
    Octocat octocat;

    std::cout << "------------------------" << std::endl;
    std::cout << "Octocat as a cat" << std::endl;
    Cat &cat = octocat;
    EXPECT_EQ(cat.Name(), "Octocat");
    EXPECT_EQ(cat.Limbs(), 6);

    std::cout << "------------------------" << std::endl;
    std::cout << "Octocat as an octopus" << std::endl;
    Octopus &octopus = octocat;
    EXPECT_EQ(octopus.Name(), "Octocat");
    EXPECT_EQ(octopus.Limbs(), 6);

    std::cout << "------------------------" << std::endl;
    std::cout << "Octocat as an octopuslike creature" << std::endl;
    Creature &octopuslike = (Octopus &)octocat;
    EXPECT_EQ(octopuslike.Name(), "Octocat");
    EXPECT_EQ(octopuslike.Limbs(), 6);

    std::cout << "------------------------" << std::endl;
    std::cout << "Octocat as a catlike creature" << std::endl;
    Creature &catlike = (Cat &)octocat;
    EXPECT_EQ(catlike.Name(), "Octocat");
    EXPECT_EQ(catlike.Limbs(), 6);

    return 0;
}