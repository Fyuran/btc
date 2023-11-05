#pragma once
using JSON = nlohmann::json;
using String = std::string;
using String_view = std::string_view;
using armaCallbackPtr = int(*)(char const*, char const*, char const*);
namespace fs = std::filesystem;

namespace ArmA {
	String copyJSONfile(const String&);
	String copyJSONfile(const fs::path);
	String writeData(const char*);
	String getData(const fs::path, const int, armaCallbackPtr);
	String deleteData(const fs::path);
}