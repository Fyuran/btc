#include "armaFileFunctions.h"
#include <boost/date_time.hpp>

namespace arma {

	String getCurrentDateTime() {

		std::ostringstream ss;
		boost::posix_time::ptime time{ boost::posix_time::second_clock::local_time() };

		auto time_facet = new boost::posix_time::time_facet{ "%d-%m-%Y %H-%M" };
		ss.imbue(std::locale(ss.getloc(), time_facet));
		ss << time;

		return ss.str();
	}

	String copyFile(const fs::path& filePath)
	{

		String filePathFull = filePath.filename().string(); //Get the name portion without the timestamp from file
		String name;
		std::stringstream ss;
		ss << filePathFull;  
		ss >> name; //terminates extraction once whitespace is reached
		String backupSuffix{ name + " (" + getCurrentDateTime() + ").JSON" };
		fs::path backupFilePath{ backupSuffix };

		bool hasCopied = false;
		try {
			hasCopied = fs::copy_file(filePath, backupFilePath, fs::copy_options::overwrite_existing);
		}
		catch (std::exception& e) {
			return e.what();
		}
	
		String out{ fs::absolute(filePath).string() };
		if (hasCopied)
			out += "<br/>A copy has been made: " + backupFilePath.filename().string() + "<br/>"; // <br/> will be used by Arma formatText
		else
			out += "<br/>No copy could be made.<br/>";

		return out;
	}


	String writeFile(const char* function) {
		String fileNameFull;
		JSON json;

		try {
			std::stringstream ss;
			ss << function; //btc_hm_${worldName} ${JSON}
			ss >> fileNameFull >> json;

			if (fileNameFull.empty()) throw std::invalid_argument("invalid file name");

			fileNameFull += " (" + getCurrentDateTime() + ").JSON" ;
		}
		catch (const std::exception& e) {
			return e.what();
		}

		std::promise<bool> p;
		std::future<bool> f{ p.get_future() };
		std::filesystem::path filePath{ fs::current_path() / "JSON" / fileNameFull};

		std::thread thread1([&]() {
			if (!fs::exists(filePath.parent_path()))
				fs::create_directories(filePath.parent_path());
			std::ofstream jsonFile{ filePath };
			if (jsonFile) {
				jsonFile << std::setw(4) << json;
				jsonFile.close();

				p.set_value_at_thread_exit(!(jsonFile.is_open()));
			}
			});
		thread1.detach();

		bool hasWrittenToFile{ f.get() };

		if (hasWrittenToFile) return filePath.string();
		else return "";
	}

	const String retrieveList()
	{
		const std::filesystem::path filePath{ fs::current_path() / "JSON" };
		if(!fs::exists(filePath))
			fs::create_directories(filePath);
		const fs::directory_iterator dir{ filePath };
		std::vector<String> vecDirs;

		try {
			for (const auto& p : dir) {
				const String ext{ p.path().extension().string() };
				if (ext == ".JSON")
					vecDirs.push_back(fs::absolute(p.path()).string());
			}
		}
		catch (const std::exception& e) {
			return e.what();
		}


		return to_string(vecDirs);
	}


	String to_string(const std::vector<String>& vec) {
		std::stringstream ss;
		ss << "[";
		for (const auto& el : vec) {
			ss << R"(")" << el << R"(")" << (el != vec.back() ? ", " : ""); // ["ELEMENT1", "ELEMENT2",...]
		}
		ss << "]";

		return ss.str();
	}

	String deleteFile(const fs::path& filePath) {
		String fileNameFull{ filePath.filename().string() };

		try {
			fs::remove(filePath);
		}
		catch (const std::exception& e) {
			return e.what();
		}

		return fileNameFull + " has been deleted";
	}

	String renameFile(const fs::path& filePath, String name) {
		name += " (" + getCurrentDateTime() + ").JSON";

		fs::path newFilePath{ name };

		try {
			fs::rename(filePath, newFilePath);
		}
		catch (const std::exception& e) {
			return e.what();
		}
		
		return fs::absolute(newFilePath).string();
	}

}