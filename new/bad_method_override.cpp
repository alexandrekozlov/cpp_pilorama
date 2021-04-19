#include "prolog.h"

/// $name: Bad method override
/// $description: Check understanding of virtual methods.
/// $keywords: polymorphism inheritance
/// $level: beginner

/// $question: Why it fails?

/// $output: run

/// $code
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

    EXPECT_EQ(animal->Says(), "Meow!");

    return 0;
}
