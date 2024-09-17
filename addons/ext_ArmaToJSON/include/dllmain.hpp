#pragma once
#include <string>
using String = std::string;

	int strncpy_safe(char* output, const String src);
	bool areEqual(const char* _Str1, const char* _Str2);

extern "C" {
	void RVExtensionVersion(char* output, int outputSize);
	void RVExtension(char* output, int outputSize, const char* function);
	void RVExtensionRegisterCallback(int(*callbackProc)(char const*, char const*, char const*));
	int RVExtensionArgs(char* output, int outputSize, const char* function, const char** args, int argsCnt);
}


