#pragma once
#include "Core.h"

// Templated vector2 struct
template <typename T>
struct Vector3
{
	T x;
	T y;
	T z;


	//Basic operations
	Vector3<T> operator+ (const T& _right) const;
	Vector3<T> operator- (const T& _right) const;
	Vector3<T> operator* (const T& _right) const;
	Vector3<T> operator/ (const T& _right) const;

	Vector3<T> operator+ (const Vector3<T>& _right) const;
	Vector3<T> operator- (const Vector3<T>& _right) const;
	Vector3<T> operator* (const Vector3<T>& _right) const;
	Vector3<T> operator/ (const Vector3<T>& _right) const;

	void operator+= (const T& _right);
	void operator-= (const T& _right);
	void operator*= (const T& _right);
	void operator/= (const T& _right);
				  
	void operator+= (const Vector3<T>& _right);
	void operator-= (const Vector3<T>& _right);
	void operator*= (const Vector3<T>& _right);
	void operator/= (const Vector3<T>& _right);

	bool operator==  (const Vector3<T>& _right) const;


	float Lenght() const;
	float LenghtSqrt() const;
	Vector3<T> Normalize() const;
	
};

#include "Vector3.inl"

using Vector3f	= Vector3<float32>;
using Vector3d	= Vector3<float64>;
using Vector3i	= Vector3<int32>;
using Vector3ui = Vector3<uint32>;


