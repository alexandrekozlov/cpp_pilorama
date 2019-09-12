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

void Foo(std::unique_ptr<Object> ptr1, std::unique_ptr<Object> ptr2)
{
	// ...some work...
}

int main()
{
	// What is wrong with this line?
	// Why? How to fix it?
	Foo( std::unique_ptr<Object>{new Object{}}, std::unique_ptr<Object>{new Object{}} );

	return 0;
}
