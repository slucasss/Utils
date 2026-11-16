#include "MemoryLeakDetector.h"

#ifdef _DEBUG

#include <cstring>
#include <codecvt>
#include <locale>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

std::string GetExecPath()
{
#ifdef _WIN32
	std::wstring path(1024, L'\0');
	const DWORD len = GetModuleFileNameW(NULL, &path[0], (DWORD)path.size());
	if (!len)
		return std::string();

	path.resize(len);
	std::wstring_convert<std::codecvt_utf8<wchar_t>> convU16ToU8;
#endif
}


void MemoryLeakDetector::AddNew(std::string objetName)
{
}

#endif

