#include "dllmain.h"
#include "pch.h"
#include "armaFileFunctions.h"
#include "armaDataFunctions.h"

constexpr auto CURRENT_VERSION = "1.0.0.0";
using JSON = nlohmann::json;
using String = std::string;
namespace fs = std::filesystem;

int strncpy_safe(char* output, const char* src, int size)
{
	int i;
	size--;
	for (i = 0; i < size && src[i] != '\0'; i++)
	{
		output[i] = src[i];
	}
	output[i] = '\0';
	return i;
}

//--- Extension version information shown in .rpt file
void RVExtensionVersion(char* output, int outputSize) {
	//--- max outputSize is 32 bytes
	strncpy_safe(output, CURRENT_VERSION, outputSize);
}

void RVExtension(char* output, int outputSize, const char* function) {
	strncpy_safe(output, arma::writeFile(function).c_str(), outputSize);
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
			strncpy_safe(output, e.what(), outputSize);
			return -1;
		}
		
	}
	/*DATA FUNCTIONS*/
	if (strcmp(function, "getData") == 0) {
		if (arguments.size() != 3) {
			strncpy_safe(output, "length_error: passed arguments should be three: [filePath, name, index].", outputSize);
			return -1;
		}
		String name{ arguments.at(1) };
		int index = stoi(arguments.at(2));

		//Arma 3 2.14150957 outputSize is currently 20480 bytes
		strncpy_safe(output, arma::getData(filePath, 20480-240, name, index).c_str(), outputSize);
		return 202;
	}
	/*FILESYSTEM FUNCTIONS*/
	if (strcmp(function, "dataExists") == 0)
		if (fs::exists(filePath)) return 200;

	if (strcmp(function, "copyFile") == 0) {
		strncpy_safe(output, arma::copyFile(filePath).c_str(), outputSize);
		return 201;
	}
	if (strcmp(function, "deleteFile") == 0) {
		strncpy_safe(output, arma::deleteFile(filePath).c_str(), outputSize);
		return 203;
	}
	if (strcmp(function, "renameFile") == 0) {
		if (arguments.size() != 2) {
			strncpy_safe(output, "length_error: passed arguments should be two: [filePath, name].", outputSize);
			return -1;
		}

		String name{ arguments.at(1) };
		strncpy_safe(output, arma::renameFile(filePath, name).c_str(), outputSize);
		return 204;
	}
	if (strcmp(function, "retrieveList") == 0) {
		strncpy_safe(output, arma::retrieveList().c_str(), outputSize);
		return 205;
	}
	/*---------------------*/
	strncpy_safe(output, "Available Functions: getData, retrieveList, deleteFile, copyFile, renameFile", outputSize);
	return -1;
}

//"btc_ArmaToJSON" callExtension "btc_hm_Altis {}"
//"btc_ArmaToJSON" callExtension ["dataExists", ["D:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (20-20 2023-11-18).JSON"]]
//"btc_ArmaToJSON" callExtension ["getData", ["D:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (14-43 2024-01-04).JSON", "cities", "-1"]]
//"btc_ArmaToJSON" callExtension ["getData", ["D:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (14-43 2024-01-04).JSON", "Altis", "-1"]]
//"btc_ArmaToJSON" callExtension ["retrieveList", []]
//"btc_ArmaToJSON" callExtension ["deleteFile", ["D:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (20-20 2023-11-18).JSON"]]
//"btc_ArmaToJSON" callExtension ["copyFile", ["D:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (20-20 2023-11-18).JSON"]]
//"btc_ArmaToJSON" callExtension ["renameFile", ["D:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (20-20 2023-11-18).JSON", "Test"]]