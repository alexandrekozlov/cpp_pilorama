// This code contains some compilation error as well
// as some bugs.
//
// Find and fix as many as you can.

#include <iostream>
#include <vector>  // FIX: STL headers do not have .h extension

// Computes result of a set of linear functions.
// data
//   array of triplets as input for f(x) = x * a + b
//     [x1,x2,x3...,a1,a2,a3...,b1,b2,b3...]
//
// size
//   array size. Must be multiple of 3
//
// succeded (optional)
//   returns false on invalid input
//
// FIX: wrong return type
std::vector<int> compute_linear(const int *data, int size, bool *succeeded)
{
	std::vector<int> computed;  // FIX: Missing namespace name

	if (size % 3 != 0) {
		// FIX: Missing null pointer check (succeeded is an optional parameter)
		if (succeeded != nullptr)
			*succeeded = false;

		return computed;  // FIX: Prevents return type optimization
	}

	int n = size / 3;

	computed.resize(n);  // FIX: Will cause buffer overrun. reserve does not change size.

	for (int i = 0; i < n ; i++) {
		int a = data[i];
		int b = data[i + n];
		int c = data[i + n * 2];
		computed[i] = a * b + c;
	}  // FIX: Missing closing brace

	// FIX: Setting result is missing (uninitialized variable)
	if (succeeded != nullptr)
		*succeeded = true;

	return computed;
}

int main(int argc, char **argv) {
	if (argc < 4) {  // FIX: Number of arguments + program name
		std::cout << "usage: compute arguments..." << std::endl;
		return 0;
	}

	int n = argc - 1;   // FIX: Exclude program name argument

	int *input = new int[n];

	for (int i = 0; i < n; i++)
		input[i] = std::atoi(argv[i + 1]); // FIX: Incorrect conversion; Skip program name argument

	bool succeeded;

	// FIX: Missing namespace
	std::vector<int> computed = compute_linear(input, n, &succeeded);

	delete[] input;  // FIX: Arrays must be deleted with an array delete expression

	if (!succeeded) {
		std::cout << "Function failed." << std::endl;
		return 1;
	}

	// Print all results that resuls until f(x) = 0
	// or until end of the vector.
	int index = 0;   // FIX: Uninitialized variable
	int *p = &computed[0];
	int *end = p + computed.size();
	while(*p != 0 && p < end) {
		std::cout << index << ": " << *p++ << std::endl;
		++index;
	}

	if (index < computed.size())
		std::cout << "Null crossing function at " << index << std::endl;

	return 0;
}
