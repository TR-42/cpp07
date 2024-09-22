#include <iostream>
#include <string>

#include "./iter.hpp"

#define LEN 5

template <typename T>
static void print(const T &i)
{
	std::cout << i << std::endl;
}
template <typename T>
static void x2(T &i)
{
	i *= 2;
}

int main(void)
{
	int arr[LEN];

	for (int i = 0; i < LEN; ++i) {
		arr[i] = i;
	}

	std::cout << "Original array:" << std::endl;
	::iter(arr, LEN, print);

	::iter(arr, LEN, x2);
	std::cout << "Array after x2:" << std::endl;
	::iter(arr, LEN, print);

	return 0;
}
