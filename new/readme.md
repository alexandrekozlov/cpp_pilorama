## TODOs
  * Use https://hackmd.io/ to present?
  * Guideline: test must fit one screen, including output.
  * Copy source before compilation so that the compilation log and markdown
    file name do not give away the intention or provide hint.
  * Check out `Cracking the Coding Interview` for general programming questions

## Basic concepts to test
* Inheritance
  * Polymorphysm 
  * Multiple base classes

## Basic theory
* Preprocessor
* Compilation
* Linking
* Static polymorphysm vs dynamic as applicable to c++
* Interface vs abstract class
* Inheritance vs composition
* Reference vs Aggregation
* Exceptions. How do they work? What's guaranteed?
* NULL vs nullptr. nullptr, why is it needed? Why nullptr_t is needed? [nullptr_t.cpp]
* Pointers, pointer arithmetic
* Reference. Reference vs pointeer.


# Basic practical questions
---
* Composition?
* Default arguments values.
* Type promotion. Specific cases of char->int->long etc.
* non-virtual destructor
* operator overloading
* missing virtual in method of a base class, but present in the subclass
* unique address of a member guarantee (empty class case)
* sizeof
* sizeof abstract/interface
* casts: static, dynamic, reinterpret, etc
* friends
* const in argument declaration: `const char * const arg` does makes sense?


### Modifying object copy retrieved from a container
### Method overloading

### Base class method call
### Diamond inheritance
### Virtual method call in base class ctor
### Member variable hiding in the base class
### Duck typing. Multiple inheritance.

### Logical operator no short-circuit evaluation for overloads



## C++11+ specific
=default
override
auto
const variable member
const method
mutable
move semantics
constexpr

## Advanced
Templates
SFINAE
Undefined behavior. What it means. Why it exists in the first place?


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


## Polymorphism

## Practical

```
What will be the output of the following C++ program:

#include<iostream>
using namespace std;
int main(){
int a=1;
cout<<(a++)*(++a)<<endl;
return 0;
}
```

```
What will be the value of x in the following C++ program

#include<iostream>
using namespace std;
int main(){
int a=1;
int x=(a++)++;
cout<<x<<endl;
return 0;
}
```
```
There are two ways to use lower_bound in std::map:
std::map<int, int> m; 
// .. add elements .. 
int k = 30; 
auto it1 = std::lower_bound(m.begin(), m.end(), k); 
auto it2 = m.lower_bound(k); 
```