#include "pch.h"
#include "armaClasses.h"


void ArmA::armaData::getDataToCallback(){
	try {
		if (!(m_JSON->contains(m_fileName))) throw std::out_of_range(m_fileName + " is not within JSON structure");
		std::unordered_map<String, JSON> allCategories;
		m_JSON->get_to(allCategories);
		if (allCategories.size() < 9) throw std::runtime_error("JSON categories are less than 9");
		for (const auto& main : allCategories) {
			std::unordered_map<String, JSON> m1;
			main.second.get_to(m1);
			for (const auto& secondary : m1) {
				std::unordered_map<String, JSON> m2;
				secondary.second.get_to(m2);
				for (const auto& third : m2) {
					String formattedFunction{ std::format(R"(["{}", "{}"])", main.first, secondary.first) };
					String s{ std::format(R"({{"{}":{}}})", third.first, third.second.dump()) };
					String formattedOutput{ std::regex_replace(s, std::regex(R"(\\")"), R"(")") };

					std::pair<String, String> pair{ formattedFunction, formattedOutput };

					if ((formattedFunction.size() + formattedOutput.size()) > outputMaxSize) throw std::overflow_error{ std::format("output size is over: {}", outputMaxSize) };
					output.push_back(pair);
				}
			}
		}
	}
	catch (const std::exception& e) {
		armaPtr("btc_ArmaToJSON", "EXCEPTION", e.what());
		return;
	}
	concurrency::parallel_for_each(output.begin(), output.end(), [&, this](const std::pair<String, String>& pair) {
		recursiveOutput(pair); 
		}, concurrency::static_partitioner());

	armaPtr("btc_ArmaToJSON", "FinishedLoading", "1");
}

void ArmA::armaData::recursiveOutput(const std::pair<String, String>& pair) {
	int buffer = armaPtr("btc_ArmaToJSON", pair.first.c_str(), pair.second.c_str());
	if (buffer < 0) {
		std::this_thread::sleep_for(std::chrono::milliseconds(33));
		recursiveOutput(pair);
	}
}