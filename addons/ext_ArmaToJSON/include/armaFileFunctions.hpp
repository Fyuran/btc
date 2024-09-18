#pragma once
#include <string>
#include <filesystem>
#include <vector>
using String = std::string;
namespace fs = std::filesystem;

namespace arma {
	String getCurrentDateTime();
	String copyFile(const fs::path filePath);
	String writeFile(const char* function);
	const String retrieveList();
	String to_string(const std::vector<String>& vec);
	String deleteFile(const fs::path filePath);
	String renameFile(const fs::path filePath, String name);
}