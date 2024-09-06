#pragma once

#include <cstddef>

template <typename T>
class Array
{
 private:
	T *_arr;
	std::size_t _size;

 public:
	Array();
	template <typename S>
	Array(S size);
	Array(unsigned int size);
	~Array();
	Array(const Array &src);
	Array &operator=(const Array &src);

	T &operator[](std::size_t index);
	const T &operator[](std::size_t index) const;

	std::size_t size() const;
};

#include "./Array.tpp"
