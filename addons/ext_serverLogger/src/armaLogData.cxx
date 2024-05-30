#include "armaLogData.h"
#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm_ext.hpp>
#include "rapidcsv.h"
#include <boost/date_time.hpp>
#include <fstream>

/*
    name
    uid
    fps
    viewDistance
*/
namespace arma {

    void manageSession(std::vector<String> args) {
        arma::logEntry entry{ args };
        entry.saveLogData();
    }

    void manageNewSession(std::vector<String> args) {
        arma::logEntry entry{ args };
        auto filePath = getCurrentPath(entry);

        if (!std::filesystem::exists(filePath.parent_path()))
            std::filesystem::create_directories(filePath.parent_path());
        std::ofstream of{ filePath, std::ios::trunc };
        of << "timestamp," << entry.timeStamp << "\n";
        for (const logData& ld : entry.logs) {
            of << ld.name << "," << ld.fps;
            if (ld != entry.logs.back())
                of << "\n";
        }
        of.close();
    }

    std::filesystem::path getCurrentPath(const logEntry& entry) {
        auto date = getCurrentDate();

        std::filesystem::path filePath{ std::filesystem::current_path() /
            "serverLogger_csv" / entry.worldName / date.at(2) / date.at(1) / date.at(0) / (entry.missionName + ".csv") };

        return filePath;
    }

    std::vector<String> getCurrentDate() {
        std::vector<String> date;

        std::ostringstream ss;
        boost::posix_time::ptime system_time{ boost::posix_time::second_clock::local_time() };
        boost::gregorian::date sDate{ system_time.date() };

        auto date_facet = new boost::gregorian::date_facet("%d %m %Y");
        ss.imbue(std::locale(ss.getloc(), date_facet));

        ss << sDate;
        boost::algorithm::split(date, ss.str(), boost::algorithm::is_any_of(" "));

        return date;
    }

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
        timeStamp = data_entry.at(2);

        std::vector<String> data{ data_entry.cbegin() + 3, data_entry.cend() };
        for (const String& s : data) {
            String copy{ s };
            std::vector<String> splits;
            boost::split(splits, copy, boost::is_any_of(","));
            this->logs.push_back(logData{ splits });
        }
    }

    void logEntry::saveLogData() {

        std::filesystem::path filePath = getCurrentPath(*this);

        if (std::filesystem::exists(filePath)) {

            rapidcsv::Document doc(filePath.generic_string(), rapidcsv::LabelParams(0, 0),
                rapidcsv::SeparatorParams(),
                rapidcsv::ConverterParams(true, 0, 0));

            for (const logData& ld : logs) {
                if (doc.GetRowIdx(ld.name) == -1) {
                    std::vector<String> rowFPS(doc.GetColumnCount()-1, "");
                    rowFPS.push_back(ld.fps);

                    doc.InsertRow(doc.GetRowCount(), rowFPS, ld.name);
                }       
            }

            std::vector<String> fpsColumn(doc.GetRowCount(), "");
            for (unsigned int i = 0; i < doc.GetRowCount(); i++) {
                String label = doc.GetRowName(i);
                logData ld = find(label);
                fpsColumn.at(i) = ld.fps;
            }

            bool isNewColumn = true;
            for (String label : doc.GetColumnNames()) {
                if (timeStamp == label) {
                    doc.SetColumn(label, fpsColumn);
                    isNewColumn = false;
                }
            }
            if(isNewColumn)
                doc.InsertColumn(doc.GetColumnCount(), fpsColumn, timeStamp);

            doc.Save(filePath.generic_string());
        }
    }

    logData logEntry::find(const String s) {
        for (logData& ld : logs) {
            if (ld.name == s) return ld;
        }
        return logData(); //return an empty object to draw empty data from
    }

}