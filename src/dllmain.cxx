#include "dllmain.h"
#include "pch.h"
#include "armaClasses.h"
#include "armaFunctions.h"

constexpr auto CURRENT_VERSION = "1.0.0.0";
using JSON = nlohmann::json;
using String = std::string;
namespace fs = std::filesystem;

armaCallbackPtr callbackPtr = nullptr;
std::vector<String> extensionContext;

void RVExtensionRegisterCallback(armaCallbackPtr callbackProc) {
	callbackPtr = callbackProc;
}

//--- Extension version information shown in .rpt file
void RVExtensionVersion(char* output, int outputSize) {
	//--- max outputSize is 32 bytes
	strncpy(output, CURRENT_VERSION, outputSize);
}

void RVExtension(char* output, int outputSize, const char* function) {
	strncpy(output, ArmA::writeData(function).c_str(), outputSize);
}

//"extension" callExtension["function", ["arguments"...]]
int RVExtensionArgs(char* output, int outputSize, const char* function, const char** args, int argsCnt) {

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
			filePath = arguments.at(0);
			if (!fs::exists(filePath)) throw std::runtime_error(std::format("{} not found", filePath.string()));
;		}
		catch (const std::exception& e) {
			strncpy(output, e.what(), outputSize);
			return -1;
		}
		
	}

	if (strcmp(function, "dataExists") == 0) {

		if (fs::exists(filePath)) return 200;
	}	

	if (strcmp(function, "copyData") == 0) {
		strncpy(output, ArmA::copyData(filePath).c_str(), outputSize);
		return 201;
	}

	if (strcmp(function, "getData") == 0) {
		strncpy(output, ArmA::getData(filePath, outputSize - 30, callbackPtr).c_str(), outputSize);
		return 202;

	}

	if (strcmp(function, "deleteData") == 0) {
		strncpy(output, ArmA::deleteData(filePath).c_str(), outputSize);
		return 203;
		
	}

	if (strcmp(function, "renameData") == 0) {
		if (arguments.size() != 2) {
			strncpy(output, "length_error: passed arguments should be two: [filePath, name].", outputSize);
			return -1;
		}

		String name{ arguments.at(1) };
		strncpy(output, ArmA::renameData(filePath, name).c_str(), outputSize);
		return 204;
	}

	if (strcmp(function, "retrieveList") == 0) {
		strncpy(output, ArmA::retrieveList().c_str(), outputSize);
		return 205;
	}

	strncpy(output, "Available Functions: getData, retrieveList, deleteData, copyData, renameData", outputSize);
	return -1;
}


//steamID of the client calling extension getPlayerUID or "0"
//fileSource from which the extension was executed or "" if done on the fly
//missionName missionNameSource
//serverName serverName

void RVExtensionContext(const char** argv, int argc) {
	extensionContext.assign(argv, std::next(argv, argc));
}

//"btc_ArmaToJSON" callExtension "btc_hm_Altis {}"
//"btc_ArmaToJSON" callExtension ["dataExists", ["F:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (20-20 2023-11-18).JSON"]]
//"btc_ArmaToJSON" callExtension ["getData", ["F:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (20-20 2023-11-18).JSON"]]
//"btc_ArmaToJSON" callExtension ["retrieveList", []]
//"btc_ArmaToJSON" callExtension ["deleteData", ["F:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (20-20 2023-11-18).JSON"]]
//"btc_ArmaToJSON" callExtension ["copyData", ["F:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (20-20 2023-11-18).JSON"]]
//"btc_ArmaToJSON" callExtension ["renameData", ["F:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (20-20 2023-11-18).JSON", "Test"]]