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

class Exception 
{
};

class CannotMakeSoundException : public Exception
{
};

class Creature
{
public:
    virtual void MakeSound() = 0;
};

class Fish : public Creature 
{
public:
    void MakeSound()
    {
        throw CannotMakeSoundException{};
    }
};

int main()
{
    Creature *creature = new Fish{};
    char *result = nullptr;

    try 
    {
        creature->MakeSound();
    }
    catch(Exception &)
    {
        result = "Exception";
    }
    catch(CannotMakeSoundException &)
    {
        result = "CannotMakeSoundException";
    }

    ExpectEq(result, "CannotMakeSoundException");

    return 0;
}
