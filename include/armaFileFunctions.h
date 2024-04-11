#pragma once
#include "pch.h"
using JSON = nlohmann::ordered_json;
using String = std::string;
using String_view = std::string_view;
using armaCallbackPtr = int(*)(char const*, char const*, char const*);
namespace fs = std::filesystem;

namespace arma {
	String copyFile(const fs::path&);
	String writeFile(const char*);
	String to_string(const std::vector<String>&);
	String renameFile(const fs::path&, String);
	String deleteFile(const fs::path&);
	String retrieveList();
}