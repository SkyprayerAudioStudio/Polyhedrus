#include "PlatformSpecific.h"

// Windows-specific Code here
#include <Windows.h>

namespace Polyhedrus
{
	HINSTANCE GetMyModuleHandle()
	{
		MEMORY_BASIC_INFORMATION mbi;
		VirtualQuery(GetMyModuleHandle, &mbi, sizeof(mbi));
		return (HINSTANCE)(mbi.AllocationBase);
	}

	std::string PlatformSpecific::GetDllDir()
	{
		char dllName[512];
		HINSTANCE thismodule = GetMyModuleHandle();
		GetModuleFileName(thismodule, dllName, 512);
			
		std::string filename(dllName);
		std::string directory;
		const size_t last_slash_idx = filename.rfind('\\');
		if (std::string::npos != last_slash_idx)
		{
			directory = filename.substr(0, last_slash_idx);
		}

		return directory;
	}

	void PlatformSpecific::StartEditor(int port)
	{

	}

	long long PlatformSpecific::PerformanceFrequency()
	{
		LARGE_INTEGER li;
		QueryPerformanceFrequency(&li);
		return li.QuadPart;
	}

	long long PlatformSpecific::PerformanceCounter()
	{
		LARGE_INTEGER li;
		QueryPerformanceCounter(&li);
		return li.QuadPart;
	}
}
