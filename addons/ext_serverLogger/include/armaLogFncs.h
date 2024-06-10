#pragma once
#include <string>
#include <vector>
#include "armaLogData.h"
#include <nlohmann/json.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using String = std::string;
using pTime = boost::posix_time::ptime;
using date = boost::gregorian::date;

namespace arma {
	std::vector<String> localDateToVec();
	void manageSession(std::vector<String> args);
}
