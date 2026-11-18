#pragma once

#include <iostream>

#include "Core.h"

template <typename T>
class Vector3;

template <typename T> 
std::ostream& operator<<(std::ostream& os, const Vector3<T>& data);



// Templated vector2 struct
template <typename T>
class Vector3
{
public:

	T x, y, z;


	//Basic operations
	Vector3<T> operator+ (const T& _right) const noexcept;
	Vector3<T> operator- (const T& _right) const noexcept;
	Vector3<T> operator* (const T& _right) const noexcept;
	Vector3<T> operator/ (const T& _right) const noexcept;

	Vector3<T> operator+ (const Vector3<T>& _right) const noexcept;
	Vector3<T> operator- (const Vector3<T>& _right) const noexcept;
	Vector3<T> operator* (const Vector3<T>& _right) const noexcept;
	Vector3<T> operator/ (const Vector3<T>& _right) const noexcept;

	void operator+= (const T& _right) noexcept;
	void operator-= (const T& _right) noexcept;
	void operator*= (const T& _right) noexcept;
	void operator/= (const T& _right) noexcept;

	void operator+= (const Vector3<T>& _right) noexcept;
	void operator-= (const Vector3<T>& _right) noexcept;
	void operator*= (const Vector3<T>& _right) noexcept;
	void operator/= (const Vector3<T>& _right) noexcept;

	bool operator==  (const Vector3<T>& _right) const noexcept;

	float Lenght() const noexcept;
	float LenghtSqrt() const noexcept;
	Vector3<float32> Normalize() const noexcept;
	float Dot(const Vector3<T>& second)const noexcept;


	friend std::ostream& operator<< <>(std::ostream& os, const Vector3<T>& data);
};



using Vector3f	= Vector3<float32>;
using Vector3d	= Vector3<float64>;
using Vector3i	= Vector3<int32>;
using Vector3ui = Vector3<uint32>;

#include "Vector3.inl"