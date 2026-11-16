#pragma once
#include "Utils.h"



int main() {
	PROFILER_ADD_TASK("test1");
	Vector3i data{ 1, 1, 1 };

	std::cout << data << std::endl;
	data += data;
	std::cout << data << std::endl;

	PROFILER_END_TASK_NANOSECONDS("test1", "");

	return 0;
}