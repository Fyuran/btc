#pragma once
#include "pch.h"
using JSON = nlohmann::ordered_json;
using String = std::string;
using String_view = std::string_view;
using armaCallbackPtr = int(*)(char const*, char const*, char const*);
namespace fs = std::filesystem;

namespace arma {
	int getSplitCount(const String&, const int&);

	std::vector<String> splitBySize(const String&, const int&);

	template<typename T> String vecToString(const std::vector<T>&);

	String arrangeOutput(const std::map<String, std::vector<String>>&);

	String getData(const fs::path, const int, String, const int);
}
