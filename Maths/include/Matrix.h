#pragma once
#include <vector>
#include <iostream>

#include "Core.h"
#include "Vector3.h"
#include "Units.h"

template <typename T>
class Matrix;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& data);


template <typename T>
class Matrix
{
	std::vector<std::vector<T>> m_matrix;
	const int16 m_row;
	const int16 m_col;

public:
	Matrix(int16 row, int16 col);


	std::vector<T>& operator[] (int16 row) noexcept;

	Matrix<T> operator+ (const Matrix<T>& other) const noexcept;
	Matrix<T> operator- (const Matrix<T>& other) const noexcept;
	Matrix<T> operator* (const Matrix<T>& other) const noexcept;
	Matrix<T> operator/ (const Matrix<T>& other) const noexcept;

	Matrix<T> operator+ (const T& other) const noexcept;
	Matrix<T> operator- (const T& other) const noexcept;
	Matrix<T> operator* (const T& other) const noexcept;
	Matrix<T> operator/ (const T& other) const noexcept;

	void operator+= (const Matrix<T>& other) noexcept;
	void operator-= (const Matrix<T>& other) noexcept;

	bool operator==(const Matrix<T>& other) const noexcept;

	bool IsSquare() const noexcept;

	float GetDet() const noexcept;

	Matrix<T> GetInvert() const noexcept;

	friend std::ostream& operator<< <>(std::ostream& os, const Matrix<T>& data);
	friend Matrix<T>;

	static Matrix<float32> TranslationMatrix(const Vector3f& trans) noexcept;

	static Matrix<float32> RotationMatrixX(const radians& theta) noexcept;
	static Matrix<float32> RotationMatrixY(const radians& theta) noexcept;
	static Matrix<float32> RotationMatrixZ(const radians& theta) noexcept;
	
	static Matrix<float32> RescaleMatrix(const Vector3f& rescale) noexcept;
};

using Matrixi = Matrix<int32>;
using Matrixf = Matrix<float32>;
using Matrixd = Matrix<float64>;
using Matrixui = Matrix<uint32>;

#include "Matrix.inl"