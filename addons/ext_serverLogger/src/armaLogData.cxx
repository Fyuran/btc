#include "armaLogData.h"
#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm_ext.hpp>
#include <fstream>
#include <nlohmann/json.hpp>
/*
    name
    uid
    fps
    viewDistance
*/
using json = nlohmann::json;
namespace fs = std::filesystem;

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

    void manageSession(std::vector<String> args) {

        arma::logEntry entry{ args };

        auto path = getCurrentFilePath(entry);
        json j;
        if (fs::exists(path)) {
            std::ifstream is{ path };
            is >> j;
            is.close();
        }
        else
            fs::create_directories(path.parent_path());

        auto timestamp = currentDateTime("%Y-%m-%dT%H:%M:%S");
        for (const logData& ld : entry.logs) {
            
            json obj{
                {"name", ld.name},
                {"uid", ld.uid},
                {"fps", ld.fps},
                {"viewDistance", ld.viewDistance},
                {"timestamp", timestamp}
            };

            if (ld.name == "Server") {
                obj.push_back({ "units", entry.countUnits });
                obj.push_back({ "agents", entry.countAgents });
            }

            j.push_back(obj);
        }

        std::ofstream os{ path };
        if (os) {
            os << std::setw(4) << j;
            os.close();
        }
    }

    String currentDateTime(const char* fmt) {

        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);

        strftime(buf, sizeof(buf), fmt, &tstruct); //http://en.cppreference.com/w/cpp/chrono/c/strftime
        //YYYY MM DD HH MM  "%Y %m %d %H %M %S"
        //ISO-EXT "YYYY-MM-DDThh:mm:ss" 
        return buf;
    }


    const std::filesystem::path getCurrentFilePath(const logEntry& le) {
        std::filesystem::path filePath{ std::filesystem::current_path() /
            "serverLogger" / le.worldName / currentDateTime("%Y/%m/%d") / (le.missionName + ".JSON") };

        return filePath;
    }

}