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

    bool operator== (const logData& d1, const logData& d2) {
        return d1.name == d2.name &&
            d1.uid == d2.uid &&
            d1.fps == d2.fps &&
            d1.viewDistance == d2.viewDistance;
    }

    bool operator!= (const logData& d1, const logData& d2) { return !(operator==(d1, d2)); }

    void manageLoggingArguments(std::vector<String> args) {
        arma::logEntry entry{ args };
        entry.saveLogData();
    }

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

    void logEntry::saveLogData() {

        std::fstream fs{ missionName + ".csv"};
        rapidcsv::Document doc(fs, rapidcsv::LabelParams(0,0), 
            rapidcsv::SeparatorParams(),
            rapidcsv::ConverterParams(true, 0, 0));

        /*
        * compose FPS
        * check if name exists with index
        * Find name in data entry, if not found return zero
        * else add fps
        * if name does not exist
        * add row full of zero up to last one
        * 
        * check if column exists with index, set column with edited data else add it
        */
        if (fs.is_open() && doc.GetColumnCount() != 0) {

            for (const logData& ld : logs) {
                if (doc.GetRowIdx(ld.name) == -1) {
                    std::vector<int> rowFPS(doc.GetColumnCount()-1, 0);
                    rowFPS.push_back(ld.fps);

                    doc.InsertRow(doc.GetRowCount(), rowFPS, ld.name);
                }       
            }

            std::vector<int> fpsColumn(doc.GetRowCount(), 0);
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

            doc.Save(missionName + ".csv");
        }
        else {
            std::ofstream of{ missionName + ".csv", std::ios::out};
            of << "timestamp," << timeStamp << "\n";
            for (const logData& ld : logs) {
                of << ld.name << "," << ld.fps;
                if (ld != logs.back())
                    of << "\n";
            }
            of.close();
        }
    }
    logData logEntry::find(const String s) {
        for (logData& ld : logs) {
            if (ld.name == s) return ld;
        }
        return logData(); //return an empty object to draw empty data from
    }
}