#pragma once
#include <vector>
#include <iostream>

#include "Core.h"

template <typename T>
class Matrix;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& data);


template <typename T>
class Matrix
{
	std::vector<std::vector<T>> m_matrix;
	int16 m_row = 0;
	int16 m_col = 0;

public:
	Matrix() = default;
	void Init(int16 row, int16 col, bool identity = true);


	std::vector<T>& operator[] (int16 col) const;
	std::vector<T>& operator[] (int16 col);

	friend std::ostream& operator<< <>(std::ostream& os, const Matrix<T>& data);
	
	Matrix<T> operator+ (const Matrix<T>& other) const;

	friend Matrix<T>
};

#include "Matrix.inl"

using Matrixi = Matrix<int32>;
using Matrixf = Matrix<float32>;
using Matrixd = Matrix<float64>;
using Matrixui = Matrix<uint32>;