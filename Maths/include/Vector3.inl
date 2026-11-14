#include "Vector3.h"
#include <iostream>

template <typename T>
Vector3<T> Vector3<T>::operator+ (const T& _right) {
	return{ x + _right, y + _right, z + _right }
}

template <typename T>
Vector3<T> Vector3<T>::operator- (const T& _right) {
	return{ x - _right, y - _right, z - _right }
}

template <typename T>
Vector3<T> Vector3<T>::operator* (const T& _right) {
	return{ x * _right, y * _right, z * _right }
}

template <typename T>
Vector3<T> Vector3<T>::operator/ (const T& _right) {
	if (_right == 0) {
		"invalid division by 0";
		return{ x, y, z };
	}
	return{ x / _right, y / _right, z + _right }
}


template<typename T>
inline Vector3<T> Vector3<T>::operator+(const Vector3<T>& _right)
{
	return Vector3<T>{x + _right.x, y + _right.y, z + _right.z};
}

template<typename T>
inline Vector3<T> Vector3<T>::operator-(const Vector3<T>& _right)
{
	return Vector3<T>{x - _right.x, y - _right.y, z - _right.z};
}

template<typename T>
inline Vector3<T> Vector3<T>::operator*(const Vector3<T>& _right)
{
	return Vector3<T>{x * _right.x, y * _right.y, z * _right.z};
}


template<typename T>
inline Vector3<T> Vector3<T>::operator/(const Vector3<T>& _right)
{
	if (_right.x == 0 && _right.y == 0 || _right.z == 0) {
		std::cerr << "invalid division by 0" << std::endl;
		return{ x, y, z };
	}
	return Vector3<T>();
}

template<typename T>
inline bool Vector3<T>::operator==(const Vector3<T>& _right)
{
	return x == _right.x && y == _right.y && z == _right.z;
}
