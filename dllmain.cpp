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

	fs::path filePath;
	std::vector<String> arguments;
	if (argsCnt > 0) {
		for (int i = 0; i < argsCnt; ++i) {
			String s{ args[i] };
			s.erase(0, 1);
			s.erase(s.size() - 1); //unescaped quotes are present when converting
			arguments.push_back(s);
		}
		try {
			filePath = { arguments.at(0) };
			if (!fs::exists(filePath)) throw std::runtime_error(std::format("{} not found", filePath.string()));
;		}
		catch (const std::exception& e) {
			strncpy_s(output, outputSize, e.what(), _TRUNCATE);
			return -1;
		}
		
	}

	if (strcmp(function, "dataExists") == 0) {

		if (fs::exists(filePath)) return 200;
	}	

	if (strcmp(function, "copyData") == 0) {
		strncpy_s(output, outputSize - 30, ArmA::copyData(filePath).c_str(), _TRUNCATE);
		return 201;
	}

	if (strcmp(function, "getData") == 0) {
		strncpy_s(output, outputSize - 30, ArmA::getData(filePath, outputSize - 30, callbackPtr).c_str(), _TRUNCATE);
		return 202;

	}

	if (strcmp(function, "deleteData") == 0) {
		strncpy_s(output, outputSize - 30, ArmA::deleteData(filePath).c_str(), _TRUNCATE);
		return 203;
		
	}

	if (strcmp(function, "renameData") == 0) {
		if (arguments.size() != 2) {
			strncpy_s(output, outputSize, "length_error: passed arguments should be two: [filePath, name].", _TRUNCATE);
			return -1;
		}

		String name = { arguments.at(1) };
		strncpy_s(output, outputSize, ArmA::renameData(filePath, name).c_str(), _TRUNCATE);
		return 204;
	}

	if (strcmp(function, "retrieveList") == 0) {
		strncpy_s(output, outputSize - 30, ArmA::retrieveList().c_str(), _TRUNCATE);
		return 205;
	}

	strncpy_s(output, outputSize, "Available Functions: getData, retrieveList, deleteData, copyData, renameData", _TRUNCATE);
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
//"btc_ArmaToJSON" callExtension ["dataExists", ["btc_hm_Altis.JSON"]]
//"btc_ArmaToJSON" callExtension ["getData", ["btc_hm_Altis.JSON"]]
//"btc_ArmaToJSON" callExtension ["retrieveList", []]
//"btc_ArmaToJSON" callExtension ["deleteData", ["F:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis.JSON"]]
//"btc_ArmaToJSON" callExtension ["copyData", ["F:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis.JSON"]]
//"btc_ArmaToJSON" callExtension ["renameData", ["F:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis.JSON", "Test"]]