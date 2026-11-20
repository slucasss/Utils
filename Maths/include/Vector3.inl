#include <iostream>


template <typename T>
inline Vector3<T> Vector3<T>::operator+ (const T& _right) const noexcept {
	return{ x + _right, y + _right, z + _right };
}

template <typename T>
inline Vector3<T> Vector3<T>::operator- (const T& _right) const noexcept {
	return{ x - _right, y - _right, z - _right };
}

template <typename T>
inline Vector3<T> Vector3<T>::operator* (const T& _right) const noexcept {
	return{ x * _right, y * _right, z * _right };
}

template <typename T>
inline Vector3<T> Vector3<T>::operator/ (const T& _right) const noexcept {
	if (_right == 0) {
		"invalid division by 0";
		return{ x, y, z };
	}
	return{ x / _right, y / _right, z + _right };
}



template<typename T>
inline Vector3<T> Vector3<T>::operator+(const Vector3<T>& _right) const noexcept
{
	return Vector3<T>{x + _right.x, y + _right.y, z + _right.z};
}

template<typename T>
inline Vector3<T> Vector3<T>::operator-(const Vector3<T>& _right) const noexcept
{
	return Vector3<T>{x - _right.x, y - _right.y, z - _right.z};
}

template<typename T>
inline Vector3<T> Vector3<T>::operator*(const Vector3<T>& _right) const noexcept
{
	return Vector3<T>{x * _right.x, y * _right.y, z * _right.z};
}

template<typename T>
inline Vector3<T> Vector3<T>::operator/(const Vector3<T>& _right) const noexcept
{
	if (_right.x == 0 && _right.y == 0 || _right.z == 0) {
		std::cerr << "invalid division by 0" << std::endl;
		return{ x, y, z };
	}
	return Vector3<T>();
}



template<typename T>
inline void Vector3<T>::operator+=(const T& _right) noexcept
{
	x += _right; 
	y += _right; 
	z += _right;
}

template<typename T>
inline void Vector3<T>::operator-=(const T& _right) noexcept
{
	x -= _right;
	y -= _right;
	z -= _right;
}

template<typename T>
inline void Vector3<T>::operator*=(const T& _right) noexcept
{
	x *= _right;
	y *= _right;
	z *= _right;
}

template<typename T>
inline void Vector3<T>::operator/=(const T& _right) noexcept
{
	if (_right == 0) {
		"invalid division by 0";
	}
	x /= _right;
	y /= _right;
	z /= _right;
}



template<typename T>
inline void Vector3<T>::operator+=(const Vector3<T>& _right)  noexcept
{
	x += _right.x;
	y += _right.y;
	z += _right.z;
}

template<typename T>
inline void Vector3<T>::operator-=(const Vector3<T>& _right) noexcept
{
	x -= _right.x;
	y -= _right.y;
	z -= _right.z;
}

template<typename T>
inline void Vector3<T>::operator*=(const Vector3<T>& _right) noexcept
{
	x *= _right.x;
	y *= _right.y;
	z *= _right.z;
}

template<typename T>
inline void Vector3<T>::operator/=(const Vector3<T>& _right) noexcept
{
	if (_right.x == 0 && _right.y == 0 || _right.z == 0) {
		std::cerr << "invalid division by 0" << std::endl;
	}

	x /= _right.x;
	y /= _right.y;
	z /= _right.z;
}

template<typename T>
inline bool Vector3<T>::operator==(const Vector3<T>& _right) const noexcept
{
	return x == _right.x && y == _right.y && z == _right.z;
}

template<typename T>
inline T Vector3<T>::operator[](const int8& it) const noexcept
{
	return it == 0 ? x : it == 1 ? y : z;
}

template<typename T>
inline float32 Vector3<T>::Lenght() const noexcept
{
	return std::sqrt(LenghtSqrt());
}

template<typename T>
inline float32 Vector3<T>::LenghtSqrt() const noexcept
{
	return { static_cast<float32>(x*x + y*y + z*z)};
}

template<typename T>
inline Vector3f Vector3<T>::Normalize() const noexcept
{
	const float32 lenght = Lenght();
	const float32 fracLenght = 1.0f / lenght;
	return(Vector3<float32>{static_cast<float32>(x),static_cast<float32>(y), static_cast<float32>(z)} * fracLenght);
}

template<typename T>
inline float Vector3<T>::Dot(const Vector3<T>& second) const noexcept
{
	return (x * second.x) + (y * second.y) + (z * second.z);
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Vector3<T>& data)
{
	os << "(x : " << data.x << "; y : " << data.y << "; z : " << data.z << ")";
	return os;
}	