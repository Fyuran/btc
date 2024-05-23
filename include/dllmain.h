#pragma once

using armaCallbackPtr = int(*)(char const*, char const*, char const*);
int strncpy_safe(char*, const char*, int);

extern "C" {
	//--- Called by Engine on extension load 
	void RVExtensionVersion(char* output, int outputSize);
	//--- STRING callExtension STRING
	void RVExtension(char* output, int outputSize, const char* function);
	//--- STRING callExtension ARRAY
	int RVExtensionArgs(char* output, int outputSize, const char* function, const char** argv, int argc);
}
