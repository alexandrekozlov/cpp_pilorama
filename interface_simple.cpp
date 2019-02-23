// This example is a bit archaic, but compiles and works
// perfectly. Unfortunately it has a bug and leaks memory.
//
// Can you explain where it leaks, why and how to fix it?

struct Interface
{
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
