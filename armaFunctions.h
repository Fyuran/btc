#pragma once
using JSON = nlohmann::json;
using String = std::string;
using String_view = std::string_view;
using armaCallbackPtr = int(*)(char const*, char const*, char const*);
namespace fs = std::filesystem;

namespace ArmA {
	String copyData(const fs::path&);
	String writeData(const char*);
	String getData(const fs::path&, const int, armaCallbackPtr);
	String to_string(const std::vector<String>&);
	String renameData(const fs::path&, const String&);
	String deleteData(const fs::path&);
	String retrieveList();

}