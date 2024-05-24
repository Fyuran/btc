#include "armaLogData.h"
#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm_ext.hpp>
#include <fstream>
#include "rapidcsv.h"
/*
    name
    uid
    fps
    viewDistance
*/
namespace arma {
    std::vector<logData> loggedData;

    bool operator== (const logData& d1, const logData& d2) {
        return d1.name == d2.name &&
            d1.uid == d2.uid &&
            d1.fps == d2.fps &&
            d1.viewDistance == d2.viewDistance;
    }

    bool operator!= (const logData& d1, const logData& d2) { return !(operator==(d1, d2)); }

    logEntry::logEntry(std::vector<String>& data_entry) : timeStamp{ data_entry.at(0) }, missionName{ data_entry.at(1) } {

        for(String& s : data_entry)
            boost::remove_erase_if(s, boost::is_any_of("[]\""));

        std::vector<String> data{ data_entry.cbegin() + 2, data_entry.cend() };
        for (const String& s : data) {
            String copy{ s };
            std::vector<String> splits;
            boost::split(splits, copy, boost::is_any_of(","));
            this->logs.push_back(logData{ splits });
        }
    }

    void logEntry::saveLogData(std::vector<String> data_entry) {
        logEntry entry{ data_entry };

        std::fstream fs{ entry.missionName + ".csv"};
        rapidcsv::Document doc(fs, rapidcsv::LabelParams(0,0), 
            rapidcsv::SeparatorParams(),
            rapidcsv::ConverterParams(true, 0, 0));

        if (fs.is_open()) {
            std::vector<int> columnFPS;
            for (logData ld : entry.logs) {
                columnFPS.push_back(ld.fps);

                //insert missing row
                if (doc.GetRowIdx(ld.name) == -1) { //init missing cells with 0s
                    auto firstRowDataCount = doc.GetRow<int>(0).size();
                    std::vector<int> rowData(firstRowDataCount-1, 0); //size is a size_t allow narrowing conversion
                    rowData.push_back(ld.fps);
                    doc.InsertRow(doc.GetRowCount(), rowData, ld.name);
                }
            }

            if (entry.timeStamp != "timestamp") {
                int columnCount = doc.GetColumnCount();

                int columnIdx = doc.GetColumnIdx(entry.timeStamp);
                if (columnIdx == -1) //insert new column
                    doc.InsertColumn(columnCount, columnFPS, entry.timeStamp);
                else //edit column
                    doc.SetColumn(columnIdx, columnFPS);               
            }

            doc.Save(entry.missionName + ".csv");
        }
        else {
            std::ofstream of{ entry.missionName + ".csv", std::ios::out};
            of << "timestamp," << entry.timeStamp << "\n";
            for (const logData& ld : entry.logs) {
                of << ld.name << "," << ld.fps;
                if (ld != entry.logs.back())
                    of << "\n";
            }
            of.close();
        }
    }
}