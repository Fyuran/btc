#include "pch.h"
#include "armaClasses.h"

void ArmA::armaData::getDataToCallback()
{
	try {
		if (!(m_JSON->contains(m_fileName))) throw std::out_of_range(m_fileName + " is not within JSON structure");

	}
	catch (const std::exception& e) {
		armaPtr("btc_ArmaToJSON", "EXCEPTION", e.what());
		return;
	}

	std::unordered_map<String, JSON> allCategories;
	m_JSON->get_to(allCategories);

	try {
		if (allCategories.size() < 9) throw std::runtime_error("JSON categories are less than 9");
	}
	catch (const std::runtime_error& e) {
		armaPtr("btc_ArmaToJSON", "EXCEPTION", e.what());
		return;
	}
	auto future = std::async(std::launch::async, [&]() {
		try {
			for (auto& main : allCategories) {
				std::unordered_map<String, JSON> m1;
				main.second.get_to(m1);
				for (auto& secondary : m1) {
					std::unordered_map<String, JSON> m2;
					secondary.second.get_to(m2);
					for (auto& third : m2) {
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
			return -1;
		}
		return 0;
		});

	//auto future = std::async(std::launch::async, [&]() {
	//	for (auto& main : allCategories) {
	//		std::unordered_map<String, JSON> m;
	//		main.second.get_to(m);
	//		for (auto& secondary : m) {
	//			std::unordered_map<String, JSON> m;
	//			secondary.second.get_to(m);
	//			for (auto& third : m) {
	//				String formattedFunction{ std::format(R"(["{}", "{}", "{}"])", main.first, secondary.first, third.first) };
	//				String s{ std::format(R"([{}])", third.second.dump()) };
	//				String formattedOutput{ std::regex_replace(s, std::regex(R"(\\")"), R"(")") };

	//				std::pair<String, String> pair{ formattedFunction, formattedOutput };

	//				assert(s.length() < outputMaxSize);
	//				try {
	//					if (s.length() > outputMaxSize) throw std::overflow_error{ std::format("data size is over: {}", outputMaxSize) };
	//				}
	//				catch (const std::overflow_error& e) {
	//					armaPtr("btc_ArmaToJSON", "EXCEPTION", e.what());
	//					return -1;
	//				}

	//				output.push_back(pair);
	//			}
	//		}
	//	}
	//	return 0;
	//	});

	if (future.get() != 0) return;

	int buffer = 99;
	for_each(std::execution::par, output.begin(), output.end(), [this, &buffer](std::pair<String, String> pair) {
		std::lock_guard<std::mutex> lock(mutex);
		buffer = { armaPtr("btc_ArmaToJSON", pair.first.c_str(), pair.second.c_str()) };
		if (buffer <= 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(33));
			buffer = armaPtr("btc_ArmaToJSON", pair.first.c_str(), pair.second.c_str());
		}
		});

	armaPtr("btc_ArmaToJSON", "FinishedLoading", "");
}

