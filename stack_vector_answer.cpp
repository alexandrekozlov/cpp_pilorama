//
//
#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

template<typename T>
class Stack {
public:
	size_t size() const {
		return items.size();
	}

	bool is_empty() const {
		return items.empty();
	}

	void push(const T &t) {
		items.push_back(t);
	}

	void push(T &&t) {
		items.push_back(t);
	}

	void pop() {
		items.pop_back();
	}

	T &top() {
		return items[items.size() - 1];
	}

private:
	std::vector<T> items;
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
