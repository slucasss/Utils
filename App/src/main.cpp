#pragma once
#include "Utils.h"


int main() {
	std::cout << "---Vector---" << std::endl;
	PROFILER_ADD_TASK("vector");
	Vector3i data{ 1, 1, 1 };

	std::cout << data << std::endl;
	data += data;
	std::cout << data << std::endl;
	
	PROFILER_END_TASK_MILLISECONDS("vector", "");

	std::cout << std::endl << "---Matrix---" << std::endl ;

	PROFILER_ADD_TASK("matrix");

	Matrixf matrix;
	matrix.Init(3, 3);
	std::cout << matrix << std::endl;
	
	matrix[1][0] = 12.0f;

	std::cout << matrix;

	PROFILER_END_TASK_MILLISECONDS("matrix", "");




	return 0;
}