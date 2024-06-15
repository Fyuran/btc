#include "armaLogFncs.h"
#include <boost/date_time.hpp>
#include <filesystem>
#include <iostream>

using json = nlohmann::json;
namespace fs = std::filesystem;
namespace arma {

    void manageSession(std::vector<String> args) {
        arma::logEntry entry{ args };
        auto path = entry.getCurrentFilePath();
        json j;
        if (fs::exists(path)) {
            std::ifstream is{ path };
            is >> j;
            is.close();
        }
        else
            fs::create_directories(path.parent_path());

        for (const logData& ld : entry.logs) {
            json obj{
                {"name", ld.name},
                {"uid", ld.uid},
                {"fps", ld.fps},
                {"viewDistance", ld.viewDistance},
                {"timestamp", boost::posix_time::to_iso_extended_string(ld.timestamp)}
            };

            if (ld.name == "Server") {
                obj.emplace("units", entry.countUnits);
                obj.emplace("agents", entry.countAgents);
            }

            j.push_back(obj);
        }

        std::ofstream os{ path };
        if (os) {
            os << std::setw(4) << j;
            os.close();
        }
    }


    std::vector<String> localDateToVec() {
        std::vector<String> date;

        std::ostringstream ss;
        auto date_facet = new boost::gregorian::date_facet("%d %m %Y");
        ss.imbue(std::locale(ss.getloc(), date_facet));

        ss << boost::gregorian::day_clock::local_day();
        boost::algorithm::split(date, ss.str(), boost::algorithm::is_any_of(" "));

        return date;
    }
 }
