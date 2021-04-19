#include "prolog.h"

/// $name: Virtual destructor
/// $keywords: polymorphism
/// $level: beginner

/// $question: Why verse is broken?

/// $output: run
/// $code
class Creature
{
public:
    Creature() { std::cout << "I am creature" << std::endl; }
};

class Duck : public Creature
{
public:
    Duck() { std::cout << "I am Duck" << std::endl; }
    ~Duck() { std::cout << "When I'm sqeezed\nI do quack" << std::endl; }
};

int main()
{
    Creature *creature = new Duck();
    delete creature;

    return 0;
}
