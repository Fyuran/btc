#include "armaLogData.h"
#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm_ext.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <fstream>

/*
    name
    uid
    fps
    viewDistance
*/

namespace arma {

    bool operator== (const logData& d1, const logData& d2) {
        return d1.name == d2.name &&
            d1.uid == d2.uid &&
            d1.fps == d2.fps &&
            d1.viewDistance == d2.viewDistance;
    }

    bool operator!= (const logData& d1, const logData& d2) { return !(operator==(d1, d2)); }

    logEntry::logEntry(std::vector<String>& data_entry) {

        for(String& s : data_entry)
            boost::remove_erase_if(s, boost::is_any_of("[]\""));

        missionName = data_entry.at(0);
        worldName = data_entry.at(1);
        countUnits = stoi(data_entry.at(2));
        countAgents = stoi(data_entry.at(3));

        std::vector<String> data{ data_entry.cbegin() + 4, data_entry.cend() };
        for (const String& s : data) {
            String copy{ s };
            std::vector<String> splits;
            boost::split(splits, copy, boost::is_any_of(","));
            this->logs.push_back(logData{ splits });
        }
    }


    logData logEntry::find(const String s) {
        for (logData& ld : logs) {
            if (ld.name == s) return ld;
        }
        return logData(); //return an empty object to draw empty data from
    }

    extern std::vector<String> localDateToVec();

    const std::filesystem::path logEntry::getCurrentFilePath() const {
        auto vecDate = localDateToVec();

        std::filesystem::path filePath{ std::filesystem::current_path() /
            "serverLogger" / worldName / vecDate.at(2) / vecDate.at(1) / vecDate.at(0) / (missionName + ".JSON") };

        return filePath;
    }

}