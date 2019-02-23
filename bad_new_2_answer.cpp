#include <memory>
#include <string>

struct Object
{
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

	// It is possible to leak object when one object already constructed
	// but not yet its unique ptr and another object throws during
	// construction. This is because the construction order
	// is indeterminate.

	Foo( std::make_unique<Object>(), std::make_unique<Object>() );

	return 0;
}
