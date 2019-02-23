#include <memory>
#include <string>

struct Object
{
	std::string str;
};

void Foo(Object *ptr1, Object *ptr2)
{
	// ...some work...
}

int main()
{
	// What is wrong with this line?
	// Why? How to fix it?

	// In case one object already constructed and
	// the other object throws during construction
	// the first object leaks.
	// Construction order here is indetermined.

	// Correct fix:
	Foo( std::make_unique<Object>().get(), std::make_unique<Object>().get() );

	return 0;
}
