#include <cstdlib>
#include <iostream>

#include "Array.hpp"

template <typename T>
static void printArr(const T &arr, std::size_t size)
{
	for (std::size_t i = 0; i < size; ++i) {
		std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
	}
}
template <typename T>
static void printArr(const Array<T> &arr)
{
	printArr(arr, arr.size());
}

#define MAX_VAL 10
int main(int, char **)
{
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	std::srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = std::rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try {
		numbers[-2] = 0;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "# current numbers" << std::endl;
	printArr(numbers);

	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = std::rand();
	}

	std::cout << "# new numbers" << std::endl;
	printArr(numbers);

	std::cout << "# mirror numbers" << std::endl;
	printArr(mirror, MAX_VAL);

	delete[] mirror;	//
	return 0;
}
