#pragma once
#include "Utils.h"


int main() {
	std::cout << "---Vector---" << std::endl;
	PROFILER_ADD_TASK("vector");
	Vector3i data{ 1, 1, 1 };

	std::cout << data << std::endl;
	data += data;
	std::cout << data << std::endl;

	float32 size = data.Lenght();
	std::cout << size << std::endl;

	std::cout << data.Normalize() << std::endl;
	
	PROFILER_END_TASK_MILLISECONDS("vector", "");

	std::cout << std::endl << "---Matrix---" << std::endl ;

	PROFILER_ADD_TASK("matrix");

	Matrixf matrix1(2, 2);
	Matrixf matrix2(2, 2);
	
	matrix1[1][0] = 12.0f;
	matrix1[0][1] = 8.0f;
	matrix1[0][0] = 123.0f;
	matrix1[1][1] = 14.0f;

	Matrixf identityMatrix = matrix1 / matrix1;

	std::cout << matrix1 << std::endl;
	//std::cout << matrix2 << std::endl;
	std::cout << identityMatrix << std::endl;



	PROFILER_END_TASK_MILLISECONDS("matrix", "");




	return 0;
}