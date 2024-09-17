#include "dllmain.hpp"
#include <string.h>
#include "armaFileFunctions.hpp"
#include "armaDataFunctions.hpp"
#include <future>

namespace fs = std::filesystem;

constexpr auto CURRENT_VERSION = "1.0.0.0";
enum returnTypes{
	ERROR = -1,
	OK
};
int(*callbackPtr)(char const* name, char const* function, char const* data) = nullptr;

int strncpy_safe(char* output, const String src)
{
	int i = 0;
	for (; src[i] != '\0'; i++) {
		output[i] = src[i];
	}
	output[i] = '\0';
	return i;
}

bool areEqual(const char* _Str1, const char* _Str2) {
	return strcmp(_Str1, _Str2) == 0;
}

//--- Extension version information shown in .rpt file
void RVExtensionVersion(char* output, int outputSize) {
	//--- max outputSize is 32 bytes
	strncpy_safe(output, CURRENT_VERSION);
}

void RVExtension(char* output, int outputSize, const char* function) {
	strncpy_safe(output, arma::writeFile(function));
}

void RVExtensionRegisterCallback(int(*callbackProc)(char const*, char const*, char const*)) {
	callbackPtr = callbackProc;
}
//"extension" callExtension["function", ["arguments"...]]
int RVExtensionArgs(char* output, int outputSize, const char* function, const char** args, int argsCnt) {
	outputSize -= 240; //add some padding
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
			if (!fs::exists(filePath)) throw std::runtime_error(filePath.string() + " not found");
;		}
		catch (const std::exception& e) {
			strncpy_safe(output, e.what());
			return ERROR;
		}
	}

	/*DATA FUNCTIONS*/
	if (areEqual(function, "callbackData")) {
		if (arguments.size() != 1) {
			strncpy_safe(output, "length_error: passed arguments should be two: [filePath].");
			return ERROR;
		}
		try {
			auto whocares = std::async(std::launch::async, callbackPtr, "btc_ArmaToJSON", "parseOutput", arma::getOutput(filePath, outputSize).c_str());
		}
		catch (const std::exception& e) {
			strncpy_safe(output, e.what());
			return ERROR;
		}
		return OK;
	}
	if (areEqual(function, "getData")) {
		if (arguments.size() != 2) {
			strncpy_safe(output, "length_error: passed arguments should be two: [filePath, index].");
			return ERROR;
		}
		try {
			int index = stoi(arguments.at(1));
			strncpy_safe(output, arma::getData(filePath, outputSize, index));
		}
		catch (const std::exception& e) {
			strncpy_safe(output, e.what());
			return ERROR;
		}
		return OK;
	}
	if (areEqual(function, "getPieces")) {
		if (arguments.size() != 1) {
			strncpy_safe(output, "length_error: passed arguments should be one: [filePath].");
			return ERROR;
		}
		try {
			strncpy_safe(output, arma::getPieces(filePath, outputSize));
		}
		catch (const std::exception& e) {
			strncpy_safe(output, e.what());
			return ERROR;
		}
		return OK;
	}
	/*FILESYSTEM FUNCTIONS*/
	if (areEqual(function, "dataExists"))
		if (fs::exists(filePath)) return OK;

	if (areEqual(function, "copyFile")) {
		strncpy_safe(output, arma::copyFile(filePath));
		return OK;
	}
	if (areEqual(function, "deleteFile")) {
		strncpy_safe(output, arma::deleteFile(filePath));
		return OK;
	}
	if (areEqual(function, "renameFile")) {
		if (arguments.size() != 2) {
			strncpy_safe(output, "length_error: passed arguments should be two: [filePath, name].");
			return ERROR;
		}
		try {
			String name{ arguments.at(1) };
			strncpy_safe(output, arma::renameFile(filePath, name));
		}
		catch (const std::exception& e) {
			strncpy_safe(output, e.what());
			return ERROR;
		}
		return OK;
	}
	if (areEqual(function, "retrieveList")) {
		strncpy_safe(output, arma::retrieveList());
		return OK;
	}
	/*---------------------*/
	strncpy_safe(output, "Available Functions: getData, retrieveList, deleteFile, copyFile, renameFile");
	return ERROR;
}

//"btc_ArmaToJSON" callExtension "btc_hm_Altis {}"
//"btc_ArmaToJSON" callExtension ["dataExists", ["D:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (20-20 2023-11-18).JSON"]]
//"btc_ArmaToJSON" callExtension ["getData", ["D:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (14-43 2024-01-04).JSON", "cities", "-1"]]
//"btc_ArmaToJSON" callExtension ["getData", ["D:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (14-43 2024-01-04).JSON", "Altis", "-1"]]
//"btc_ArmaToJSON" callExtension ["retrieveList", []]
//"btc_ArmaToJSON" callExtension ["deleteFile", ["D:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (20-20 2023-11-18).JSON"]]
//"btc_ArmaToJSON" callExtension ["copyFile", ["D:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (20-20 2023-11-18).JSON"]]
//"btc_ArmaToJSON" callExtension ["renameFile", ["D:\SteamLibrary\steamapps\common\Arma 3\btc_hm_Altis (20-20 2023-11-18).JSON", "Test"]]