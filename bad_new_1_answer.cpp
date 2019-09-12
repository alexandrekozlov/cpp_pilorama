#include <memory>
#include <string>

struct Object
{
	Object()
	{
		// Here is code that might throw...
	}

	std::string str;
};

void Foo(Object *ptr1, Object *ptr2)
{
	// ...some work...

	delete ptr1;
	delete ptr2;
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

	// The other option is to create objects first and then pass them
	// as variables.
	Object *arg1 = nullptr;
	Object *arg2 = nullptr;
	try {
		arg1 = new Object{};
		arg2 = new Object{};
		Foo(arg1, arg2);
	}
	catch (...) {
		delete arg1;
		delete arg2;
	}

	return 0;
}
