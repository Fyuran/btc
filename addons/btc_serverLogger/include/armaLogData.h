#pragma once
#include <string>
#include <iostream>
#include <boost/filesystem.hpp>
using String = std::string;
/*
[["0:00:17","=BTC= Cpl.Fyuran","_SERVER_ _SP_PLAYER_",144.144,3800,"tempMissionSP"]]

timestamp
name
uid
fps
viewDistance
missionName
*/
namespace arma {
	class logData {
    private:
        String timestamp;
        String name;
        String uid;
        double fps;
        double viewDistance;
        double timeStamp;
        String missionName;

    public:
        friend std::ostream& operator<<(std::ostream& os, const logData& ld);
    };

    void saveLogData(const std::vector<std::vector<String>>& v);
}