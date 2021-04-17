#include "prolog.h"

/// $name Exceptions. Specific vs generic. Catch ordering
/// $category exceptions
/// $level beginner

/// $question Why it fails?

/// $output application

/// $code
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
    const char *exception_caught = nullptr;

    try 
    {
        creature->MakeSound();
    }
    catch(Exception &)
    {
        exception_caught = "Exception";
    }
    catch(CannotMakeSoundException &)
    {
        exception_caught = "CannotMakeSoundException";
    }

    EXPECT_EQ(exception_caught, "CannotMakeSoundException");

    return 0;
}
