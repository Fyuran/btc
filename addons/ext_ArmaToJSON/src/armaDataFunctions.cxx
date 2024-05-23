#include "armaDataFunctions.h"

int arma::getSplitCount(const String& s, const int& outputMaxSize) {
    return (ceil(s.length() / outputMaxSize)) + 1;
}

std::vector<String> arma::splitBySize(const String& s, const int& outputMaxSize) {
    size_t pieces = getSplitCount(s, outputMaxSize);
    std::vector<String> vec;
    vec.reserve(pieces);

    for (unsigned int i = 0; i < pieces; ++i) {
        String ss = s.substr(i * outputMaxSize, outputMaxSize);
        vec.push_back(ss);
    }

    return vec;
}


template<typename T> String arma::vecToString(const std::vector<T>& v) {
    std::stringstream ss;
    ss << "[";
    if (!v.empty()) {
        for (auto it = v.cbegin(); it != v.cend(); it++) {
            ss << *it;
            if (*it != v.back()) ss << ", ";
        }
    }
    ss << "]";
    return ss.str();
}

String arma::arrangeOutput(const std::map<String, std::vector<String>>& map) {
    std::stringstream ss;
    String string;

    if (!map.empty()) {
        ss << "[";
        for (auto it = map.cbegin(); it != map.cend(); it++) {
            ss << "[" << "\"" << it->first << "\", " << vecToString(it->second) << "],";
        }
        string = ss.str();
        string.pop_back(); //removes trailing comma
        string += "]";
    }

    return string;
}

//void sendData(const String& output, const int& index) {
//    if (index != -1)
//        return splitBySize(output).at(index);
//    else return std::to_string(splitBySize(output).size());
//}
//createHashMapFromArray [[key1, value1], [key2, value2]]
// [ ["city", [ [key1, value1], [key2, value2]...] ]
String arma::getData(const fs::path pathToJSON, const int outputMaxSize, String name, const int index) {

    std::map<String, std::vector<String>> data;
    try {
        std::ifstream jsonFile(pathToJSON);
        JSON json = JSON::parse(jsonFile);

        for (const auto& categories : json.at(name).items()) {
            std::vector<String> elements;
            for (const auto& element : categories.value().items()) {
                String fmt = std::format(R"(["{}", {}])", element.key(), element.value().dump());
                elements.push_back(fmt);
            }
            data.insert_or_assign(categories.key(), elements);
        }

        String output = arrangeOutput(data);
        std::vector<String> split = splitBySize(output, outputMaxSize);
        if (index != -1)
            return split.at(index);
        else return std::format(R"([{}, {}])",split.size(), outputMaxSize);
    }
    catch (const std::exception& e) {
        return e.what();
    }

}
