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
	Foo( new Object{}, new Object{} );

	return 0;
}
