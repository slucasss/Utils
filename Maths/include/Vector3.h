#pragma once


// Templated vector2 struct
template <typename T>
struct Vector3
{
	T x;
	T y;
	T z;


	//Basic operations
	Vector3<T> operator+ (const T& _right);
	Vector3<T> operator- (const T& _right);
	Vector3<T> operator* (const T& _right);
	Vector3<T> operator/ (const T& _right);

	Vector3<T> operator+ (const Vector3<T>& _right);
	Vector3<T> operator- (const Vector3<T>& _right);
	Vector3<T> operator* (const Vector3<T>& _right);
	Vector3<T> operator/ (const Vector3<T>& _right);

	bool operator== (const Vector3<T>& _right);


};



#include "Vector3.inl"



