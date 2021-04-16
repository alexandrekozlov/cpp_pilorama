## Standard prefix
```c++
#include <iostream>
```

## Basic concepts to test
* Inheritance
  * Polymorphysm 
  * Multiple base classes

## Basics theory
* Preprocessor
* Compilation
* Linking
* Static polymorphysm vs dynamic
* Interface vs abstract class
Inheritance vs composition
Reference vs Aggregation
Exceptions. How do they work? What's guaranteed?
nullptr, why is it needed?
Why nullptr_t is needed?
Pointers, pointer arithmetic

## Basic practical questions
* Method overloading
* Bad method override

The code:
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

    std::cout << "Cat says: " << animal->Says();

    return 0;
}

```

The result:
```
Cat says: <nothing>
```

Why it fails?


* Modifying object copy retrieved from a container
* Base class method call
* Diamond inheritance
* Virtual method call in base class ctor
* Member variable hiding in the base class
* Duck typing. Multiple inheritance.
* Exceptions. Specific vs generic. Catch ordering.
* Exceptions. Throw in the destructor. Hidden case (member thowing * behind he scenes). Obvious error (throw in dtor)
* Composition?
* Default arguments values.
* Type promotion. Specific cases of char->int->long etc.
* NULL vs nullptr. Type overload for void *.
* non-virtual destructor
* operator overloading
* missing virtual in method of a base class, but present in the * subclass
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

## Advanced
Templates

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


