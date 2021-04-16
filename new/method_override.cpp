#include <cassert>
#include <iostream>

class Animal {
public:
    const char *Says() const { return "<nothing>"; }
};

class Cat : public Animal {
public:
    const char *Says() const { return "Meow!"; }
};

int main() {
    Animal *animal = new Cat();

    std::cout << "Cat says: " << animal->Says();

    return 0;
}
