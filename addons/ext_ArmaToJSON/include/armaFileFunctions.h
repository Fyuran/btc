#pragma once
#include "pch.h"
using JSON = nlohmann::json;
using String = std::string;
using armaCallbackPtr = int(*)(char const*, char const*, char const*);
namespace fs = std::filesystem;

namespace arma {
	extern String getCurrentDateTime();

	String copyFile(const fs::path&);
	String writeFile(const char*);
	String to_string(const std::vector<String>&);
	String renameFile(const fs::path&, String);
	String deleteFile(const fs::path&);
	const String retrieveList();
	String getCurrentDateTime();
}