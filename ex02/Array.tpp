#pragma once

#include <stdexcept>

#include "./Array.hpp"

template <typename T>
Array<T>::Array(
) : _arr(new T[0]),
		_size(0)
{
}

template <typename T>
template <typename S>
Array<T>::Array(
	S size
) : _arr(new T[size]),
		_size(size)
{
}

template <typename T>
Array<T>::Array(
	unsigned int size
) : _arr(new T[size]),
		_size(size)
{
}

template <typename T>
Array<T>::~Array(
)
{
	delete[] this->_arr;
	this->_arr = NULL;
}

template <typename T>
Array<T>::Array(
	const Array &src
) : _arr(new T[src._size]),
		_size(src._size)
{
	for (std::size_t i = 0; i < _size; ++i) {
		this->_arr[i] = src._arr[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(
	const Array &src
)
{
	if (this == &src) {
		return *this;
	}

	delete[] this->_arr;
	this->_arr = NULL;
	this->_size = 0;

	this->_arr = new T[src._size];
	this->_size = src._size;

	for (std::size_t i = 0; i < _size; ++i) {
		this->_arr[i] = src._arr[i];
	}

	return *this;
}

template <typename T>
T &Array<T>::operator[](
	std::size_t index
)
{
	if (this->_size <= index) {
		// index out of range
		throw std::exception();
	}

	return this->_arr[index];
}

template <typename T>
const T &Array<T>::operator[](
	std::size_t index
) const
{
	if (this->_size <= index) {
		// index out of range
		throw std::exception();
	}

	return this->_arr[index];
}

template <typename T>
std::size_t Array<T>::size(
) const
{
	return this->_size;
}
