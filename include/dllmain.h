#pragma once

using armaCallbackPtr = int(*)(char const*, char const*, char const*);

extern "C" {
	//--- Called by Engine on extension load 
	void RVExtensionVersion(char* output, int outputSize);
	//--- STRING callExtension STRING
	void RVExtension(char* output, int outputSize, const char* function);
	//--- STRING callExtension ARRAY
	int RVExtensionArgs(char* output, int outputSize, const char* function, const char** argv, int argc);
	//--- Extension Callback
	void RVExtensionRegisterCallback(armaCallbackPtr);
	//--- Engine passed context [steamID, fileSource, missionSourceName, serverName] since Arma 3 v2.11
	void RVExtensionContext(const char** argv, int argc);
}
