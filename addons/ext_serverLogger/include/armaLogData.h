#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <boost/filesystem.hpp>
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
        int fps = 0;
        int viewDistance = 0;

        logData() = delete;
        logData(std::vector<String> v) : logData{ v.at(0), v.at(1), std::stoi(v.at(2)), std::stoi(v.at(3)) } {}
        logData(String n, String u, int f, int v) : name{ n }, uid{ u }, fps{ f }, viewDistance{ v } {}
        friend bool operator== (const logData&, const logData&);
        friend bool operator!= (const logData&, const logData&);
    };

    bool operator== (const logData&, const logData&);

    bool operator!= (const logData&, const logData&);

    struct logEntry {

        String& missionName;
        String& timeStamp;   
        std::vector<logData> logs;

        logEntry() = delete;
        logEntry(std::vector<String>& data_entry);
        void static saveLogData(std::vector<String>);
    };

    
}