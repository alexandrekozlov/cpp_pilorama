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
	//
	// ANSWER: This assertion DOES NOT hold.
	//
	// C++ standard 4.5 [intro.object] Paragraph 7 reads:
	// "... a most derived object shall have a nonzero size 
	// and shall occupy one or more bytes of storage."
	//
	// Also:
	// 13.1 [class.derived] Paragraph 7 reads:
	// "... A base class subobject may be of zero size
	// (Clause 12); however, two subobjects that have the same
	// class type and that belong to the same most derived
	// object must not be allocated at the same address (8.10)."
	assert(((void *)&c.a) == ((void *)&c.b));

	return 0;
}
