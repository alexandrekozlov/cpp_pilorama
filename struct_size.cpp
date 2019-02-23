#include <cassert>

struct A {
};

struct C {
	A a;
	A b;
};

int main() {
	C c;

	// Will this assert or not? Why?
	assert(((void *)&c.a) == ((void *)&c.b));

	return 0;
}
