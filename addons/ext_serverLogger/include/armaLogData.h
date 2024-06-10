#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <boost/date_time/posix_time/posix_time.hpp>

using String = std::string;
using pTime = boost::posix_time::ptime;
/*
    _name
    _uid
    _fps
    _viewDistance
*/
namespace arma {

    struct logData {

        String name;
        String uid;
        int fps = 0;
        int viewDistance = 0;
        boost::posix_time::ptime timestamp = boost::posix_time::second_clock::local_time();

        logData() {};
        logData(std::vector<String> v) : logData{ v.at(0), v.at(1), stoi(v.at(2)), stoi(v.at(3)) } {}
        logData(String n, String u, int f, int v) : name{ n }, uid{ u }, fps{ f }, viewDistance{ v } {}
        logData(logData& other) : name{ other.name }, uid{ other.uid }, fps{ other.fps }, viewDistance{ other.viewDistance } {}
        logData(logData&& other) noexcept : name{ other.name }, uid{ other.uid }, fps{ other.fps }, viewDistance{ other.viewDistance }  {}
        logData& operator=(logData&& other) noexcept {
            if (this == &other) return *this;

            name = other.name;
            uid = other.uid;
            fps = other.fps;
            viewDistance = other.viewDistance;

            return *this;
        }

        friend bool operator== (const logData&, const logData&);
        friend bool operator!= (const logData&, const logData&);
    };

    struct logEntry {

        String missionName;
        String worldName;
        std::vector<logData> logs;

        logEntry() = delete;
        logEntry(std::vector<String>& data_entry);
        logData find(const String);
        const std::filesystem::path getCurrentFilePath() const;
    };

    bool operator== (const logData&, const logData&);
    bool operator!= (const logData&, const logData&);
}