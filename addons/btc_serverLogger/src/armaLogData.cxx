#include "armaLogData.h"
/*
    timestamp
    name
    uid
    fps
    viewDistance
    missionName
*/
namespace arma {
    boost::filesystem::path current_path;
    std::vector<logData> loggedData;

    std::ostream& operator<<(std::ostream& os, const arma::logData& ld) {
        return os;
    }
    void saveLogData(const std::vector<std::vector<String>>& v) {

    }
}