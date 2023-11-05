#pragma once

constexpr auto CURRENT_VERSION = "1.0.0.0";
using JSON = nlohmann::json;
using String = std::string;
using String_view = std::string_view;
using armaCallbackPtr = int(*)(char const*, char const*, char const*);
namespace fs = std::filesystem;

extern "C" {
	//--- Called by Engine on extension load 
	__declspec (dllexport) void WINAPI RVExtensionVersion(char* output, int outputSize);
	//--- STRING callExtension STRING
	__declspec (dllexport) void WINAPI RVExtension(char* output, int outputSize, const char* function);
	//--- STRING callExtension ARRAY
	__declspec (dllexport) int WINAPI RVExtensionArgs(char* output, int outputSize, const char* function, const char** argv, int argc);
	//--- Extension Callback
	__declspec (dllexport) void WINAPI RVExtensionRegisterCallback(int(*callbackProc)(char const* name, char const* function, char const* data));
	//--- Engine passed context [steamID, fileSource, missionSourceName, serverName] since Arma 3 v2.11
	__declspec (dllexport) void WINAPI RVExtensionContext(const char** argv, int argc);
}
