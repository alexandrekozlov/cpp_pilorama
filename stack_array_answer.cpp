// Implement simple stack given the interface below.
// You can use vector, but extra points for not using STL.

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

template<typename T>
class Stack final {
public:
	Stack() :
		size_(0),
		capacity_(0),
		ptr_(nullptr) {
	}

	~Stack() {
		delete[] ptr_;
	}

	size_t size() const {
		return size_;
	}

	bool is_empty() const {
		return size() == 0;
	}

	void push(const T &t) {
		ensure_size();
		ptr_[size_++] = t;
	}

	void push(T &&t) {
		ensure_size();
		ptr_[size_++] = std::move(t);
	}

	void pop() {
		ptr_[size_--] = T{};
	}

	T &top() {
		return ptr_[size_ - 1];
	}

private:
	void ensure_size() {
		if (size_ < capacity_)
			return;

		if (capacity_ == 0)
			capacity_ = 4;

		capacity_ *= 2;
		T *newptr = new T[capacity_];
		for (auto i = 0; i < size_; ++i)
			newptr[i] = std::move(ptr_[i]);

		delete[] ptr_;
		ptr_ = newptr;
	}

	size_t size_;
	size_t capacity_;
	T *ptr_;
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
