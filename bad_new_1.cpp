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
	Foo( new Object{}, new Object{} );

	return 0;
}
