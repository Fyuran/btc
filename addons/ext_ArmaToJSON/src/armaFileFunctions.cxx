#include "armaFileFunctions.h"

String arma::currentDateTime() {
	time_t now = time(0);
	tm tstruct = *localtime(&now);
	char buf[80];
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	// for more information about date/time format
	strftime(buf, sizeof(buf), "%H-%M %d-%m-%Y", &tstruct);

	return buf;
}

String arma::currentDate = { arma::currentDateTime() };

String arma::copyFile(const fs::path& filePath)
{

	String filePathFull = filePath.filename().string(); //Get the name portion without the timestamp from file
	String name;
	std::stringstream ss;
	ss << filePathFull;  
	ss >> name; //terminates extraction once whitespace is reached
	String backupSuffix{ name + " (" + arma::currentDate + ").JSON" };
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


String arma::writeFile(const char* function) {
	String fileNameFull;
	JSON json;

	try {
		std::stringstream ss;
		ss << function; //btc_hm_%1 {JSON HERE}, .JSON will be later appended
		ss >> fileNameFull >> json;

		if (fileNameFull.empty()) throw std::invalid_argument("invalid file name");

		fileNameFull += " (" + arma::currentDate + ").JSON" ;
	}
	catch (const std::exception& e) {
		return e.what();
	}

	std::promise<bool> p;
	std::future<bool> f{ p.get_future() };

	std::thread thread1([&]() {

		std::ofstream jsonFile{ fileNameFull };
		if (jsonFile) {
			jsonFile << std::setw(4) << json;
			jsonFile.close();

			p.set_value_at_thread_exit(!(jsonFile.is_open()));
		}
		});
	thread1.detach();

	bool hasWrittenToFile{ f.get() };

	fs::path filePath{ fileNameFull };
	if (hasWrittenToFile) return fs::absolute(filePath).string();
	else return "";
}

String arma::retrieveList()
{
	const fs::directory_iterator dir{"."};
	std::vector<String> vecDirs;

	for (const auto& p : dir) {
		const String ext{ p.path().extension().string() };
		if (ext == ".JSON")
			vecDirs.push_back(fs::absolute(p.path()).string());	 
	}

	return arma::to_string(vecDirs);
}


String arma::to_string(const std::vector<String>& vec) {
	std::stringstream ss;
	ss << "[";
	for (const auto& el : vec) {
		ss << R"(")" << el << R"(")" << (el != vec.back() ? ", " : ""); // ["ELEMENT1", "ELEMENT2",...]
	}
	ss << "]";

	return ss.str();
}

String arma::deleteFile(const fs::path& filePath) {
	String fileNameFull{ filePath.filename().string() };

	fs::remove(filePath);

	return fileNameFull + " has been deleted";
}

String arma::renameFile(const fs::path& filePath, String name) {
	name += " (" + arma::currentDate + ").JSON";

	fs::path newFilePath{ name };

	fs::rename(filePath, newFilePath);

	return fs::absolute(newFilePath).string();
}