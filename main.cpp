#include <string>
#include <cstring>
#include <sstream>
extern "C"
{
	//--- Called by Engine on extension load 
	__declspec (dllexport) void __stdcall RVExtensionVersion(char* output, int outputSize);
	//--- STRING callExtension STRING
	__declspec (dllexport) void __stdcall RVExtension(char* output, int outputSize, const char* function);
	//--- STRING callExtension ARRAY
	__declspec (dllexport) int __stdcall RVExtensionArgs(char* output, int outputSize, const char* function, const char** argv, int argc);
	//--- Extension Callback
	__declspec (dllexport) void __stdcall RVExtensionRegisterCallback(int(*callbackProc)(char const* name, char const* function, char const* data));
	//--- Engine passed context [steamID, fileSource, missionSourceName, serverName] since Arma 3 v2.11
	__declspec (dllexport) void __stdcall RVExtensionContext(const char** argv, int argc);
}
void __stdcall RVExtension(char* output, int outputSize, const char* function)
{
	std::strncpy(output, function, outputSize - 1);
}

int __stdcall RVExtensionArgs(char* output, int outputSize, const char* function, const char** argv, int argc)
{
	std::stringstream sstream;
	for (int i = 0; i < argc; i++)
	{
		sstream << argv[i];
	}
	std::strncpy(output, sstream.str().c_str(), outputSize - 1);
	return 0;
}

void __stdcall RVExtensionVersion(char* output, int outputSize)
{
	std::strncpy(output, "Test-Extension v1.0", outputSize - 1);
}