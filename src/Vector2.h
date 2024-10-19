#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <type_traits>

template <typename T>  
class Vector2
{
public: 
	Vector2(T x, T y);

	const char* ToString() const;

	template <typename U>
	Vector2<T> operator*(const U& v);

	Vector2<T> operator+(const Vector2<T>& vec);
	Vector2<T> operator-(const Vector2<T>& vec);

	template <typename U>
	Vector2<T> operator+(const U& v);

	template <typename U>
	Vector2<T> operator-(const U& v);

public:
	T x;
	T y;
};

template<typename T>
Vector2<T>::Vector2(T x, T y) :
	x(x),
	y(y)
{
	static_assert(std::is_same<T, int>::value
		|| std::is_same<T, float>::value
		|| std::is_same<T, double>::value);
}

template<typename T>
const char* Vector2<T>::ToString() const
{
	static std::string str;
	std::ostringstream oss;
	oss << "{" << x << ", " << y << "}";
	str = oss.str();  // Store the string
	return str.c_str();  // Return a const char*
}

template<typename T>
template<typename U>
Vector2<T> Vector2<T>::operator*(const U& v)
{
	static_assert(std::is_same<U, int>::value
		|| std::is_same<U, float>::value
		|| std::is_same<U, double>::value);

	return Vector2<T>(x * v, y * v);
}

template<typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T>& vec)
{
	return Vector2<T>(x + vec.x, y + vec.y);
}

template<typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T>& vec)
{
	return Vector2<T>(x - vec.x, y - vec.y);
}

template<typename T>
template<typename U>
Vector2<T> Vector2<T>::operator+(const U& v)
{
	static_assert(std::is_same<U, int>::value
		|| std::is_same<U, float>::value
		|| std::is_same<U, double>::value);
	return Vector2<T>(x + v, y + v);
}

template<typename T>
template<typename U>
Vector2<T> Vector2<T>::operator-(const U& v)
{
	return *this + (v * (U) - 1);
}
