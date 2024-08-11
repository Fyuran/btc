#pragma once
#include <string>
#include <vector>
#include <filesystem>

using String = std::string;
namespace chrono = std::chrono;

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

        logData() {}
        logData(std::vector<String> v) : logData{ v.at(0), v.at(1), stoi(v.at(2)), stoi(v.at(3)) } {}
        logData(String n, String u, int f, int v) : name{ n }, uid{ u }, fps{ f }, viewDistance{ v } {}
        logData(logData& other) :
            name{ other.name },
            uid{ other.uid },
            fps{ other.fps },
            viewDistance{ other.viewDistance } {}

            logData(logData&& other) noexcept :
            name{ other.name },
            uid{ other.uid },
            fps{ other.fps },
            viewDistance{ other.viewDistance } {}

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
        int countUnits = 0;
        int countAgents = 0;
        std::vector<logData> logs;

        logEntry() {}
        logEntry(std::vector<String>& data_entry);
    };

    bool operator== (const logData&, const logData&);
    bool operator!= (const logData&, const logData&);

    String currentDateTime(const char*);
    void manageSession(std::vector<String> args);
    const std::filesystem::path getCurrentFilePath(const logEntry&);
}