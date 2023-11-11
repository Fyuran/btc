#include "pch.h"
#include "armaFunctions.h"
#include "armaClasses.h"


String ArmA::copyData(const fs::path& filePath)
{
	_SYSTEMTIME systemTime, localTime;
	GetSystemTime(&systemTime);
	GetLocalTime(&localTime);

	String backupSuffix = std::format("{} ({}'{}.{}-{}-{}){}", filePath.stem().string(),
		localTime.wHour, localTime.wMinute, systemTime.wDay, systemTime.wMonth, systemTime.wYear,
		filePath.extension().string()); //NAME(HH'MM.dd-mm-yyyy).JSON

	fs::path backupFilePath{ backupSuffix };

	bool hasCopied = fs::copy_file(filePath, backupFilePath, fs::copy_options::overwrite_existing);

	String out = std::format("{}", fs::absolute(filePath).string());
	if (hasCopied)
		out += "<br/>A copy has been made: " + backupFilePath.filename().string() + "<br/>"; // <br/> will be used by Arma formatText
	else
		out += "<br/>No copy could be made.<br/>";

	return out;
}


String ArmA::writeData(const char* function) {
	std::stringstream ss;
	String fileNameFull;
	JSON json;
	try {
		ss << function; //btc_hm_%1 {JSON HERE}, .JSON will be later appended
		ss >> fileNameFull >> json;

		if (fileNameFull.empty()) throw std::invalid_argument("invalid file name found");
		fileNameFull += ".JSON";
	}
	catch (const std::exception& e) {
		return e.what();
	}

	std::promise<bool> p;
	std::future<bool> f = p.get_future();

	std::thread thread1([=, &p](JSON json) {

		std::ofstream jsonFile{ fileNameFull };
		if (jsonFile) {
			jsonFile << std::setw(4) << json;
			jsonFile.close();

			p.set_value_at_thread_exit(!(jsonFile.is_open()));
		}
		}, std::move(json));
	thread1.detach();

	bool hasWrittenToFile = f.get();

	if (hasWrittenToFile) return "File Written";
	else return "Couldn't write file.";
}

String ArmA::getData(const fs::path& filePath, const int outputSize, armaCallbackPtr callbackPtr) {

	String fileNameFull = filePath.filename().string();
	std::unique_ptr<JSON> json{ std::make_unique<JSON>() };
	try {
		std::ifstream jsonFile(fileNameFull);
		*json = JSON::parse(jsonFile);
	}
	catch (const std::exception& e) {
		return e.what();
	}

	String fileName = filePath.stem().string();
	std::unique_ptr<ArmA::armaData> arma{ std::make_unique<ArmA::armaData>(std::move(json), outputSize, callbackPtr, fileName) };
	std::thread thread1{ &ArmA::armaData::getDataToCallback, std::move(arma) };
	thread1.detach();

	return "Loading Data";
}


String ArmA::retrieveList()
{
	const fs::directory_iterator dir{"."};
	std::vector<String> vecDirs;

	for (const auto& p : dir) {
		const String ext{ p.path().extension().string() };
		if (ext == ".JSON")
			vecDirs.push_back(fs::absolute(p.path()).string());	 
	}

	return ArmA::to_string(vecDirs);
}


String ArmA::to_string(const std::vector<String>& vec) {
	std::stringstream ss;
	ss << "[";
	for (const auto& el : vec) {
		ss << R"(")" << el << R"(")" << (el != vec.back() ? ", " : "");
	}
	ss << "]";

	return ss.str();
}

String ArmA::deleteData(const fs::path& filePath) {
	String fileNameFull = filePath.filename().string();

	fs::remove(filePath);

	String fmt = std::format("{} has been deleted", fileNameFull);
	return fmt;
}

String ArmA::renameData(const fs::path& filePath, const String& name) {
	String fileNameFull = filePath.filename().string();
	
	fs::path newFilePath{ name + ".JSON"};
	String newFileNameFull = newFilePath.filename().string();

	fs::rename(filePath, newFilePath);

	String fmt = std::format("{} has been renamed to {}", fileNameFull, newFileNameFull);
	return fmt;
}