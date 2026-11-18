#include <iostream>
#include <string>

#include "Matrix.h"

template<typename T>
inline Matrix<T>::Matrix(int16 row, int16 col) : m_matrix(row, std::vector<T>(col, 0)), m_row(row), m_col(col)
{
}

template <typename T>
inline std::vector<T>& Matrix<T>::operator[] (int16 row) const noexcept{
	return m_matrix[row];
}

template <typename T>
inline std::vector<T>& Matrix<T>::operator[] (int16 row) noexcept {
	return m_matrix[row];
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Matrix<T>& data)
{
	for (int16 row = 0; row < data.m_row; row++) {
		for (int16 col = 0; col < data.m_col; col++) {
			os << std::to_string(data.m_matrix[row][col]) << " ";
		}
		os << std::endl;
	}
	return os;
}


template <typename T>
Matrix<T> Matrix<T>::operator+ (const Matrix<T>& other) const noexcept{
	if (m_row != other.m_row || m_col != other.m_col)
		return (*this);

	Matrix<T> matrix(m_row, m_col);
	for (int16 row = 0; row < m_row; row++) {
		for (int16 col = 0; col < m_col; col++) {
			matrix[row][col] = m_matrix[row][col] + other.m_matrix[row][col];
		}
	}
	return matrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const noexcept
{
	if (m_row != other.m_row || m_col != other.m_col)
		return (*this);

	Matrix<T> matrix(m_row, m_col);
	for (int16 row = 0; row < m_row; row++) {
		for (int16 col = 0; col < m_col; col++) {
			matrix[row][col] = m_matrix[row][col] - other.m_matrix[row][col];
		}
	}
	return matrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const noexcept
{
	if (m_col != other.m_row) {
#ifdef _DEBUG
		std::cerr << "invalid matrix sizes for multiplication" << std::endl;
#endif
		return (*this);
	}

	Matrix<T> matrix(m_row, other.m_col);
	for (int16 row = 0; row < m_row; row++) {
		for (int16 col = 0; col < other.m_col; col++) {
			T value = static_cast<T>(0);
			for (int16 i = 0; i < m_col; i++) {
				value += m_matrix[row][i] * other.m_matrix[i][col];
			}
			matrix[row][col] = value;
		}
	}
	return matrix;
}

template<typename T>
inline void Matrix<T>::operator+=(const Matrix<T>& other) noexcept
{
	if (m_row != other.m_row || m_col != other.m_col)
		return;

	for (int16 row = 0; row < m_row; row++) {
		for (int16 col = 0; col < m_col; col++) {
			m_matrix[row][col] += other.m_matrix[row][col];
		}
	}
}

template<typename T>
inline void Matrix<T>::operator-=(const Matrix<T>& other) noexcept
{
	if (m_row != other.m_row || m_col != other.m_col)
		return;

	for (int16 row = 0; row < m_row; row++) {
		for (int16 col = 0; col < m_col; col++) {
			m_matrix[row][col] -= other.m_matrix[row][col];
		}
	}
}


template<typename T>
inline bool Matrix<T>::IsSquare() const noexcept
{
	return m_row == m_col;
}
