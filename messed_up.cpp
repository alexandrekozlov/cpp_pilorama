// This code contains some compilation error as well
// as some bugs.
//
// Find and fix as many as you can.

#include <iostream>
#include <vector.h>

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
void compute_linear(const int *data, int size, bool *succeeded)
{
	vector<int> computed;

	if (size % 3 != 0)
	{
		*succeeded = false;
		return std::vector<int>{};
	}

	int n = size / 3;

	computed.reserve(n);

	for (int i = 0; i < n ; i++) {
		int a = data[i];
		int b = data[i + n];
		int c = data[i + n * 2];
		computed[i] = a * b + c;

	return computed;
}

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cout << "usage: compute arguments..." << std::endl;
		return 0;
	}

	int n = argc;

	int *input = new int[n];

	for (int i = 0; i < n; i++)
		input[i] = argv[i];

	bool succeeded;

	vector<int> computed = compute_linear(input, n, &succeeded);

	delete input;

	if (!succeeded)
	{
		std::cout << "Function failed." << std::endl;
		return 1;
	}

	// Print all results that resuls until f(x) = 0
	// or until end of the vector.
	int index;
	int *p = &computed[0];
	int *end = p + computed.size();
	while(*p != 0 && p < end)
	{
		std::cout << index << ": " << *p++ << std::endl;
		++index;
	}

	if (index < computed.size())
		std::cout << "Null crossing function at " << index << std::endl;

	return 0;
}
