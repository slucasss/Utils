#include "Profiler.h"
#include <iostream>
#include <vector>

void Profiler::AddTask(const std::string& taskName)
{
	if (m_tasks.find(taskName) != m_tasks.end()) {
#ifdef _DEBUG
		std::cerr << " Task : " << taskName << " already exists" << std::endl;
#endif	
		return;
	}
	Task task;
	task.name = taskName;
	m_tasks[taskName] = task;
	std::cout << taskName << std::endl;
}

void Profiler::EndTask(const std::string& taskName, const std::string& message, Units unit)
{
	auto it = m_tasks.find(taskName);
	if (it == m_tasks.end()) {

#ifdef _DEBUG
		std::cerr << " Task : " << taskName << " doesn't exists" << std::endl;
#endif
		return;
	}

	std::chrono::steady_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::steady_clock::time_point& begin = m_tasks[taskName].begin;
	float64 duration = 0.0f;
	std::string unitMsg = "";

	switch (unit) {
	case Units::Seconds:
		duration = std::chrono::duration<double>(end - begin).count();
		unitMsg = "seconds";
		break;
	case Units::MilliSeconds:
		duration = std::chrono::duration<double, std::milli>(end - begin).count();
		unitMsg = "milliseconds";
		break;
	case Units::MicroSeconds:
		duration = std::chrono::duration<double, std::micro>(end - begin).count();
		unitMsg = "micrseconds";
		break;
	case Units::NanoSeconds:
		duration = std::chrono::duration<double, std::nano>(end - begin).count();
		unitMsg = "nanoseconds";
		break;
	}
	m_tasks.erase(taskName);

	std::string msg;
	if (message == "") {
		std::cout << "Task " << taskName << " : " << std::to_string(duration) << " " << unitMsg << std::endl;
	}
	else
		std::cout << message <<" : " << std::to_string(duration) << " " << unitMsg << std::endl;
	
	return;
}

void Profiler::ClearTasks()
{
	m_tasks.clear();
}

Profiler::Task::Task()
{
	begin = std::chrono::high_resolution_clock::now();
}
