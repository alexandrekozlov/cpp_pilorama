// This example is a bit archaic, but compiles and works
// perfectly. Unfortunately it has a bug and leaks memory.
//
// Can you explain where it leaks, why and how to fix it?

// EXPLANATION: Impl's destructor is not called, so memory
// allocated in ptr_ member is leaked.
//
// This is because in absence of virtual destructor, deleting
// a polymorphic object by its base class pointer invokes
// a base class destructor.
//
// Defining a virtual destructor in the base class allows
// the object to invoke destructor polymorphically
// (using actual runtime type).

struct Interface
{
	// FIX: a Add virtual destructor.
	virtual ~Interface() {}
	virtual void A() = 0;
};

struct Impl : public Interface
{
	Impl() : ptr_(new int[10]) {}

	~Impl() { delete[] ptr_; }

	void A() override { /* do something */ }

	int *ptr_;
};

int main() 
{
	Interface *object = new Impl();

	object->A();

	delete object;

	return 0;
}
