#include "armaDataFunctions.hpp"
#include <fstream>

namespace arma {

	int getSplitCount(const String& s, const int outputSize) {
		return (ceil((s.length()) / outputSize)) + 1;
	}

	std::vector<String> splitBySize(const String& s, const int outputSize) {
		size_t pieces = getSplitCount(s, outputSize);
		std::vector<String> vec;
		vec.reserve(pieces);

		for (unsigned int i = 0; i < pieces; ++i) {
			String ss = s.substr((i) * outputSize, outputSize);
			vec.push_back(ss);
		}

		return vec;
	}

	void parseOutput(const JSON& json, String& output) {
		bool isFirst = true; //need this flag as first() and back() have undefined behaviour on empty objects or arrays
		for(const auto& [key, val] : json.items()) {
			if (!isFirst)
				output += ", ";
			else
				isFirst = false;
			
			if (val.is_object()) {
				output +=  "[\"" + key + "\", " + "createHashMapFromArray[";
				if (!val.empty())
					parseOutput(val, output);

				output += "]]";
			}
			else
				if (!val.empty())
					output += "[\"" + key + "\", " + val.dump() + "]";
				else
					output += "[\"" + key + "\", " + "[]]";
		}
	}

	String getData(fs::path filePath, const int outputSize, const int index) {
		String output = getOutput(filePath, outputSize);
		auto split = splitBySize(output, outputSize);
		try {
			return split.at(index);
		}
		catch (const std::exception& e) {
			return e.what();
		}
	}

	String getOutput(const fs::path filePath, const int outputSize) {
		String output = "";

		JSON json;
		try {
			std::ifstream jsonFile(filePath);
			if(jsonFile)
				json = JSON::parse(jsonFile);
			else
				throw std::runtime_error(filePath.string() + " not found");
		}
		catch (const std::exception& e) {
			return e.what();
		}

		output += "createHashMapFromArray[";
		parseOutput(json, output);
		output += "]";
			
		return output;
	}

	String getPieces(const fs::path filePath, const int outputSize) {
		String output = getOutput(filePath, outputSize);
		auto pieces = splitBySize(output, outputSize).size();
		return std::to_string(pieces);
	}

}