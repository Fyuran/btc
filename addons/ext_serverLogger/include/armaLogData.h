#pragma once
#include <string>
#include <vector>
#include <filesystem>
using String = std::string;
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
        String fps;
        String viewDistance;

        logData() {};
        logData(std::vector<String> v) : logData{ v.at(0), v.at(1), v.at(2), v.at(3)} {}
        logData(String n, String u, String f, String v) : uid{ u }, fps{ f }, viewDistance{ v } {
            if(n.at(0) == '=')
                n.insert(0, " "); //if name starts with an equal sign such as =BTC= Cpt.Ramius most excel-like programs will throw a fit
            name = n;
        }
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

    bool operator== (const logData&, const logData&);
    bool operator!= (const logData&, const logData&);

    struct logEntry {

        String missionName;
        String worldName;
        String timeStamp;
        std::vector<logData> logs;

        logEntry() = delete;
        logEntry(std::vector<String>& data_entry);
        void saveLogData();
        logData find(const String);
    };

    std::filesystem::path getCurrentPath(const logEntry& entry);
    std::vector<String> getCurrentDate();
    void manageSession(std::vector<String> args);
    void manageNewSession(std::vector<String> args);
}