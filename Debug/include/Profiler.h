#pragma once
#include <unordered_map>
#include <chrono>
#include "PrimitiveTypes.h"


#define PROFILER_ADD_TASK(taskName) Profiler::AddTask(taskName);
#define PROFILER_CLEAR_TASKS() Profiler::ClearTasks();

#define PROFILER_END_TASK(taskName, message, unit) Profiler::EndTask(taskName, message, unit);
#define PROFILER_END_TASK_SECONDS(taskName, message) Profiler::EndTask(taskName, message, Profiler::Units::Seconds);
#define PROFILER_END_TASK_MILLISECONDS(taskName, message)Profiler::EndTask(taskName, message, Profiler::Units::MilliSeconds);
#define PROFILER_END_TASK_MICROSECONDS(taskName, message)Profiler::EndTask(taskName, message, Profiler::Units::MicroSeconds);
#define PROFILER_END_TASK_NANOSECONDS(taskName, message)Profiler::EndTask(taskName, message, Profiler::Units::NanoSeconds);

class Profiler
{
	struct Task {
		std::string name;
		std::chrono::steady_clock::time_point begin;;
		
		Task();

		~Task() = default;
	};


	inline static std::unordered_map<std::string, Task> m_tasks;

public:

	enum class Units {
		Seconds,
		MilliSeconds,
		MicroSeconds,
		NanoSeconds
	};

	static void AddTask(const std::string& taskName);
	static void EndTask(const std::string& taskName, const std::string& message = "", Units unit = Units::Seconds);
	static void ClearTasks();
};


