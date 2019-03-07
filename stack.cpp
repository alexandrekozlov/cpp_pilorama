// Implement simple stack given the interface below.
// You can use std::vector.
// Extra points for not using STL.
// Extra points for bounds checking and exception safety.

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

template<typename T>
class Stack {
public:
	Stack() {





	}

	~Stack() {





	}

	size_t size() const {





	}

	bool is_empty() const {





	}

	void push(const T &t) {





	}

	void push(T &&t) {





	}

	void pop() {





	}

	T &top() {






	}





};

int main() {
	Stack<std::string> stack;
	assert(stack.is_empty() == true);
	assert(stack.size() == 0);

	stack.push("foo");
	assert(stack.is_empty() == false);
	assert(stack.size() == 1);

	stack.push("bar");
	assert(stack.size() == 2);
	assert(stack.top() == "bar");

	stack.pop();
	assert(stack.size() == 1);
	assert(stack.top() == "foo");

	stack.pop();
	assert(stack.is_empty());
	assert(stack.size() == 0);

	std::cout << "OK!" << std::endl;

	return 0;
}
