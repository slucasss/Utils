#include <iostream>
#include <string>

#include "Matrix.h"

template<typename T>
inline void Matrix<T>::Init(int16 row, int16 col, bool identity)
{
	m_row = row;
	m_col = col;
	for (int iCol = 0; iCol < col; iCol++) {
		std::vector<T> rowVector;
		for (int iRow = 0; iRow < row; iRow++) {
			int zero = static_cast<T>(0);
			int un = static_cast<T>(1);
			rowVector.push_back(identity ? iRow == iCol ? un : zero : zero);
		}
		m_matrix.push_back(rowVector);
	}
}

template <typename T>
std::vector<T>& Matrix<T>::operator[] (int16 col) const {
	return m_matrix[col];
}

template <typename T>
std::vector<T>& Matrix<T>::operator[] (int16 col) {
	return m_matrix[col];
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Matrix<T>& data)
{
	for (int16 col = 0; col < data.m_col; col++) {
		for (int16 row = 0; row < data.m_row; row++) {
			os << std::to_string(data.m_matrix[col][row]) << " ";
		}
		os << std::endl;
	}
	return os;
}

template <typename T>
Matrix<T> Matrix<T>::operator+ (const Matrix<T>& other) const {

}
