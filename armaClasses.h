#pragma once
using JSON = nlohmann::json;
using String = std::string;
using String_view = std::string_view;
using armaCallbackPtr = int(*)(char const*, char const*, char const*);

namespace ArmA {
	struct armaData {

		armaData() = delete;
		armaData(std::unique_ptr<JSON> json, int size, armaCallbackPtr ptr, String fileName) :
			m_JSON{ std::move(json) }, outputMaxSize(size), armaPtr{ ptr }, m_fileName{ fileName } {
		}

		~armaData() {}

		const std::unique_ptr<JSON> m_JSON;
		const size_t outputMaxSize = 0;
		const armaCallbackPtr armaPtr;
		const String m_fileName;
		concurrency::concurrent_vector<std::pair<String, String>> output;

		void getDataToCallback();
		void recursiveOutput(const std::pair<String, String>&);
	};
}