#include <iostream>
#include <string>

#include "Matrix.h"

template<typename T>
inline Matrix<T>::Matrix(int16 row, int16 col) : m_matrix(row, std::vector<T>(col, 0)), m_row(row), m_col(col)
{
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
inline Matrix<T> Matrix<T>::operator/(const Matrix<T>& other) const noexcept
{
	return (*this) * other.GetInvert();
}


template<typename T>
inline Matrix<T> Matrix<T>::operator+ (const T& other) const noexcept {
	Matrix<T> matrix(m_row, m_col);
	for (int16 row = 0; row < m_row; row++) {
		for (int16 col = 0; col < m_col; col++) {
			matrix[row][col] = m_matrix[row][col] + other;
		}
	}
	return matrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator- (const T& other) const noexcept {
	Matrix<T> matrix(m_row, m_col);
	for (int16 row = 0; row < m_row; row++) {
		for (int16 col = 0; col < m_col; col++) {
			matrix[row][col] = m_matrix[row][col] - other;
		}
	}
	return matrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator* (const T& other) const noexcept {
	Matrix<T> matrix(m_row, m_col);
	for (int16 row = 0; row < m_row; row++) {
		for (int16 col = 0; col < m_col; col++) {
			matrix[row][col] = m_matrix[row][col] * other;
		}
	}
	return matrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator/(const T& other) const noexcept
{
	if (other == 0) {
#ifdef _DEBUG
		std::cerr << "can't divide by 0" << std::endl;
#endif
		return (*this);
	}
	
	Matrix<T> matrix(m_row, m_col);
	for (int16 row = 0; row < m_row; row++) {
		for (int16 col = 0; col < m_col; col++) {
			matrix[row][col] = m_matrix[row][col] / other;
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
inline bool Matrix<T>::operator==(const Matrix<T>& other) const noexcept
{
	if (m_col != other.m_col || m_row != other.m_row) {
#ifdef _DEBUG
		std::cerr << "can't compare two different sized matrix" << std::endl;
#endif
		return false;
	}
	for (int16 row = 0; row < m_row; row++) {
		for (int16 col = 0; col < m_col; col++) {
			if (m_matrix[row][col] != other.m_matrix[row][col])
				return false;
		}
	}
	return true;
}

template<typename T>
inline bool Matrix<T>::IsSquare() const noexcept
{
	return m_row == m_col;
}

template<typename T>
inline float Matrix<T>::GetDet() const noexcept
{
	if (IsSquare() == false) {
#ifdef _DEBUG
		std::cerr << "can't get the determinant of a non squared matrix" << std::endl;
#endif
		return -1.0f;
	}

	if (m_row == 2) {
		return m_matrix[0][0] * m_matrix[1][1] - m_matrix[1][0] * m_matrix[0][1];
	}
	else {
#ifdef _DEBUG
		std::cerr << "can't calcul det for the moment for this matrix's size" << std::endl;
#endif
		return -1.0f;
	}
}

template<typename T>
inline Matrix<T> Matrix<T>::GetInvert() const noexcept
{
	const float32 det = GetDet();
	if (det <= 0.0f) {
#ifdef _DEBUG
		std::cerr << "can't invert this matrix" << std::endl;
#endif
		return (*this);
	}

	if (m_row == 2) {
		Matrix<T> matrixWithCofactor(2, 2);

		matrixWithCofactor[0][0] = m_matrix[1][1];
		matrixWithCofactor[1][0] = -m_matrix[1][0];
		matrixWithCofactor[0][1] = -m_matrix[0][1];
		matrixWithCofactor[1][1] = m_matrix[0][0];

		Matrix<T> matrix = matrixWithCofactor * (1.0f / det);

		return matrix;
	}
	else {
#ifdef _DEBUG
		std::cerr << "can't invert this matrix's size for the moment" << std::endl;
#endif
		return (*this);
	}
}


template<typename T>
inline Matrixf Matrix<T>::TranslationMatrix(const Vector3f& trans) noexcept
{
	Matrixf matrix(4, 4);
	for (int8 row = 0; row < 4; row++) {
		matrix[row][3] = trans[row];
		
		matrix[row][row] = 1.0f;
	}
	return matrix;
}

template<typename T>
inline Matrixf Matrix<T>::RotationMatrixX(const float32& theta) noexcept
{
	const float32 sin = std::sin(theta);
	const float32 cos = std::cos(theta);

	Matrixf matrix(4, 4);
	matrix[1][1] = cos;
	matrix[1][2] = -sin;
	matrix[2][1] = sin;
	matrix[2][2] = cos;

	for (int8 row = 0; row < 4; row++) {
		if (matrix[row][row] == 0.0f) {
			matrix[row][row] = 1.0f;
		}
	}

	return matrix;
}

template<typename T>
inline Matrixf Matrix<T>::RotationMatrixY(const float32& theta) noexcept
{
	const float32 sin = std::sin(theta);
	const float32 cos = std::cos(theta);

	Matrixf matrix(4, 4);
	matrix[0][0] = cos;
	matrix[0][2] = sin;
	matrix[2][0] = -sin;
	matrix[2][2] = cos;

	for (int8 row = 0; row < 4; row++) {
		if (matrix[row][row] == 0.0f) {
			matrix[row][row] = 1.0f;
		}
	}
	return matrix;
}

template<typename T>
inline Matrixf Matrix<T>::RotationMatrixZ(const float32& theta) noexcept
{
	const float32 sin = std::sin(theta);
	const float32 cos = std::cos(theta);

	Matrixf matrix(4, 4);
	matrix[0][0] = cos;
	matrix[0][1] = -sin;
	matrix[1][0] = sin;
	matrix[1][1] = cos;

	for (int8 row = 0; row < 4; row++) {
		if (matrix[row][row] == 0.0f) {
			matrix[row][row] = 1.0f;
		}
	}
	return matrix;
}

template<typename T>
inline Matrixf Matrix<T>::RescaleMatrix(const Vector3f& rescale) noexcept
{
	Matrixf matrix(4, 4);
	for (int8 row = 0; row < 4; row++) {
		if (row != 3) {
			matrix[row][row] = rescale[row];
		}
		else
			matrix[row][row] = 1.0f;
	}
	return matrix;
}