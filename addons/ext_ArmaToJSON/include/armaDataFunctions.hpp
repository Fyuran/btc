#pragma once
#include <vector>
#include <string>
#include <filesystem>
#include <nlohmann/json.hpp>

using JSON = nlohmann::json;
using String = std::string;
namespace fs = std::filesystem;

namespace arma {
	int getSplitCount(const String& s, const int outputSize);
	std::vector<String> splitBySize(const String& s, const int outputSize);
	void parseOutput(const JSON& json, String& output);
	String getData(const fs::path filePath, const int outputSize, const int index);
	String getOutput(const fs::path filePath, const int outputSize);
	String getPieces(const fs::path filePath, const int outputSize);
}