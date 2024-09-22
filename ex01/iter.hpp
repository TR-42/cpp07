#pragma once

#include <cstddef>

template <typename T>
void iter(T *ptr, std::size_t length, void (*f)(T &))
{
	if (ptr == NULL || f == NULL) {
		return;
	}
	for (std::size_t i = 0; i < length; ++i) {
		f(ptr[i]);
	}
}

template <typename T>
void iter(const T *ptr, std::size_t length, void (*f)(const T &))
{
	if (ptr == NULL || f == NULL) {
		return;
	}
	for (std::size_t i = 0; i < length; ++i) {
		f(ptr[i]);
	}
}
