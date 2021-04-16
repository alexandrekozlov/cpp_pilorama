## Standard prefix
```c++
#include <iostream>
#include <cstring>
#include <exception>

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

```

## Basic concepts to test
* Inheritance
  * Polymorphysm 
  * Multiple base classes

## Basic theory
* Preprocessor
* Compilation
* Linking
* Static polymorphysm vs dynamic
* Interface vs abstract class
* Inheritance vs composition
* Reference vs Aggregation
* Exceptions. How do they work? What's guaranteed?
* nullptr, why is it needed?
* Why nullptr_t is needed?
* Pointers, pointer arithmetic


# Basic practical questions

## Polymorphism

### Bad method override

Category: [polymorphism]

Level: [beginner]

The code: [bad_method_override.cpp]
```c++
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

```

The result:
```
FAIL
        Expected: Meow!
          Actual: <nothing>
```

Why it fails?


### Modifying object copy retrieved from a container
### Method overloading

* Base class method call
* Diamond inheritance
* Virtual method call in base class ctor
* Member variable hiding in the base class
* Duck typing. Multiple inheritance.

### Logical operator short-circuit
Category: [language]

Level: [intermediate]

#### Code: [operator_short_circuit.cpp]
```c++
bool permissions_granted = false;

bool IsLogEnabled()
{
    return false;
}

bool CheckUserPermissions()
{
    std::cout << "Checking permissions..." << std::endl;

    // Very important code that checks permissions...

    permissions_granted = true;

    return true;
}

int main()
{

    if (IsLogEnabled() && CheckUserPermissions())
        std::cout << "ERROR: Permisson check failure." << std::endl;

    // Some other code....

    if (!permissions_granted)
        std::cout << "Error: Access denied" << std::endl;

    return 0;
}

```

#### The result:
```
Error: Access denied
```

#### Question:
Why it fails?

### Logical operator no short-circuit evaluation for overloads

### Exceptions. Specific vs generic. Catch ordering.
Category: [exceptions]

Level: [beginner]

#### Code: [exceptons1.cpp]
```c++

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

```

#### The result:
```
FAIL
        Expected: CannotMakeSoundException
          Actual: Exception
```

### Exceptions. Throw in the destructor. Hidden case (member thowing behind the scenes). Obvious error (throw in dtor)

Category: [exceptions]

Level: [beginner]

#### Code: [excepton_in_destructor.cpp]
```c++
#include <iostream>
#include <cstring>
#include <exception>

class DeviceDriver
{
public:
    DeviceDriver() : connected(false) {}

    ~DeviceDriver()
    {
        Disconnect();
    }

    void Connect()
    {
        if (!connected)
        {
            // Some connect code...
            connected = true;
        }
    }

    void Disconnect()
    {
        if (connected) 
        {
            // Disconnect code...
            connected = false;
        }
        else
        {
            throw std::runtime_error("Not connected");
        }
    }

private:
    bool connected;
};

int main()
{
    try 
    {
        DeviceDriver driver;

        driver.Connect();
        driver.Disconnect();
    }
    catch(...)
    {
        std::cout << "Error!" << std::endl;
    }

    std::cout << "Exiting." << std::endl;

    return 0;
}

```

#### The result:
```
libc++abi.dylib: terminating with uncaught exception of type std::runtime_error: Not connected
Abort trap: 6
```

#### Question:
Why application crashes?

---
* Composition?
* Default arguments values.
* Type promotion. Specific cases of char->int->long etc.
* NULL vs nullptr. Type overload for void *.
* non-virtual destructor
* operator overloading
* missing virtual in method of a base class, but present in the subclass
* unique address of a member guarantee (empty class case)
* sizeof
* sizeof abstract/interface
* casts: static, dynamic, reinterpret, etc
* friends
* const in argument declaration: `const char * const arg` does makes sense?

## C++11+ specific
=default
override
auto
const variable member
const method
mutable
move semantics

## Advanced
Templates
SFINAE

## C++11/Technical/Concurrency
threads
locks
mutexes
conditional variables
atomics

## Understanding stack
Recursive stack allocation (runnding out of stack)

# Understanding linkage
extern vs static vs member vs global variable


