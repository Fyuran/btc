#pragma once
#include "pch.h"
using JSON = nlohmann::json;
using String = std::string;
using String_view = std::string_view;
using armaCallbackPtr = int(*)(char const*, char const*, char const*);

namespace ArmA {
	struct armaData {

		armaData() = delete;
		armaData(std::unique_ptr<JSON> json, int size, armaCallbackPtr ptr) :
			m_JSON{ std::move(json) }, outputMaxSize{ size }, armaPtr{ ptr } {
		}

		~armaData() {}

		const std::unique_ptr<JSON> m_JSON;
		const int outputMaxSize = 0;
		const armaCallbackPtr armaPtr;
		std::vector<std::pair<String, String>> output;

		void getDataToCallback();
		void recursiveOutput(const std::pair<String, String>&);
	};
}