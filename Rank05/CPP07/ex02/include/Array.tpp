/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 11:58:27 by pdel-olm          #+#    #+#             */
/*   Updated: 2026/07/09 11:13:19 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

// DEFAULT CONSTRUCTOR

template <typename T>
Array<T>::Array(): _size(0), _array(NULL)
{
}

// SIZE CONSTRUCTOR

template <typename T>
Array<T>::Array(unsigned long n): _size(n)
{
	_array = new T[n]();
}

// COPY CONSTRUCTOR

template <typename T>
Array<T>::Array(const Array &other): _array(NULL)
{
	*this = other;
}

// DESTRUCTOR

template <typename T>
Array<T>::~Array()
{
	if (_array)
		delete[] _array;
}

// COPY ASSIGNMENT OPERATOR

template <typename T>
Array<T>	&Array<T>::operator =(const Array &other)
{
	if (this != &other)
	{
		_size = other._size;
		if (_array)
			delete[] _array;
		_array = new T[_size]();
		for (unsigned long i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return (*this);
}

// SUBSCRIPT OPERATOR

template <typename T>
T	&Array<T>::operator [](unsigned long position)
{
	if (position >= _size)
		throw std::exception();
	return (_array[position]);
}

// PUBLIC MEMBER FUNCTIONS

template <typename T>
unsigned long	Array<T>::size(void) const
{
	return (_size);
}
