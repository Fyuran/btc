#include "pch.h"
#include "dllmain.h"
#include "armaClasses.h"
#include "armaFunctions.h"

armaCallbackPtr callbackPtr = nullptr;
std::vector<String> extensionContext;

void WINAPI RVExtensionRegisterCallback(armaCallbackPtr callbackProc) {
	callbackPtr = callbackProc;
}

//--- Extension version information shown in .rpt file
void WINAPI RVExtensionVersion(char* output, int outputSize) {
	//--- max outputSize is 32 bytes
	strncpy_s(output, outputSize, CURRENT_VERSION, _TRUNCATE);
}

void __stdcall RVExtension(char* output, int outputSize, const char* function) {
	strncpy_s(output, outputSize, ArmA::writeData(function).c_str(), _TRUNCATE);
}

//"extension" callExtension["function", ["arguments"...]]
int WINAPI RVExtensionArgs(char* output, int outputSize, const char* function, const char** args, int argsCnt) {

	std::vector<String> arguments;
	if (argsCnt > 0)
		for (uint16_t i = 0; i < argsCnt; ++i) {
			String s{ args[i] };
			s.erase(0, 1);
			s.erase(s.size() - 1); //unescaped quotes are present when converting
			arguments.push_back(s);
		}
	else
	{
		strncpy_s(output, outputSize, "No arguments passed.", _TRUNCATE);
		return -1;
	}
	const fs::path filePath{ arguments.at(0) + ".JSON" };
	const bool fileExists = fs::exists(filePath);
	if (!fileExists) {
		strncpy_s(output, outputSize, std::format("{} not found", fs::absolute(filePath).generic_string()).c_str(), _TRUNCATE);
		return -1;
	}

	if (strcmp(function, "dataExists") == 0) {
		if (fileExists) return 200;
	}

	if (strcmp(function, "getData") == 0)
	{
		if (arguments.size() != 1) {
			strncpy_s(output, outputSize, "length_error: passed arguments should be one.", _TRUNCATE);
			return -1;
		}

		strncpy_s(output, outputSize-30, ArmA::getData(filePath, outputSize-30, callbackPtr).c_str(), _TRUNCATE);//["",200,0] size is 20 bytes
		return 201;
	}

	if (strcmp(function, "deleteData") == 0)
	{
		if (arguments.size() != 1) {
			strncpy_s(output, outputSize, "length_error: passed arguments should be one.", _TRUNCATE);
			return -1;
		}

		strncpy_s(output, outputSize, ArmA::deleteData(filePath).c_str(), _TRUNCATE);
		return 202;
	}

	strncpy_s(output, outputSize, "Available Functions: getData", _TRUNCATE);
	return -1;
}


//steamID of the client calling extension getPlayerUID or "0"
//fileSource from which the extension was executed or "" if done on the fly
//missionName missionNameSource
//serverName serverName

void WINAPI RVExtensionContext(const char** argv, int argc) {
	extensionContext.assign(argv, std::next(argv, argc));
}

//"btc_ArmaToJSON" callExtension "btc_hm_Altis {}"
//"btc_ArmaToJSON" callExtension ["dataExists", ["btc_hm_Altis"]]
//"btc_ArmaToJSON" callExtension ["getData", ["btc_hm_Altis"]]
//"btc_ArmaToJSON" callExtension ["deleteData", ["btc_hm_Altis"]]