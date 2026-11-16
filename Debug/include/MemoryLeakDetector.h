#pragma once

#ifdef _DEBUG

#define DEBUG_NEW new(BLOCK, FILE, LINE)
#define new DEBUG_NEW


#include <string>

namespace 
{
	
	std::string GetExecPath();


}


class MemoryLeakDetector
{

	static void AddNew(std::string objetName);

};

#endif