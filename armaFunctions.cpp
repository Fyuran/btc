#include "pch.h"
#include "armaFunctions.h"
#include "armaClasses.h"

String ArmA::copyJSONfile(const String& fileNameFull) {
	fs::path filePath{ fileNameFull };

	_SYSTEMTIME systemTime, localTime;
	GetSystemTime(&systemTime);
	GetLocalTime(&localTime);

	String backupSuffix = std::format("{} ({}'{}.{}-{}-{}){}", filePath.stem().generic_string(), 
		localTime.wHour, localTime.wMinute, systemTime.wDay, systemTime.wMonth, systemTime.wYear,
			filePath.extension().generic_string()); //NAME(HH'MM.dd-mm-yyyy).JSON

	fs::path backupFilePath{ backupSuffix }; 

	bool hasCopied = false;
	if (fs::exists(filePath))
		hasCopied = fs::copy_file(filePath, backupFilePath, fs::copy_options::overwrite_existing);

	String out = std::format("{}", fs::absolute(filePath).generic_string());
	if (hasCopied)
		out += "<br/>A backup has been made: " + backupFilePath.filename().generic_string() + "<br/>"; // <br/> will be used by Arma formatText
	else
		out += "<br/>No backup, old file couldn't be found.<br/>";

	return out;
}

String ArmA::copyJSONfile(const fs::path pathFilename)
{
	return ArmA::copyJSONfile(pathFilename.filename().generic_string());
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

	String hasCopied = ArmA::copyJSONfile(fileNameFull);

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

	if (hasWrittenToFile) return hasCopied;
	else return "Couldn't write file.";
}

String ArmA::getData(const fs::path filePath, const int outputSize, armaCallbackPtr callbackPtr) {

	String fileNameFull = filePath.filename().generic_string();
	std::unique_ptr<JSON> json{ std::make_unique<JSON>() };
	try {
		std::ifstream jsonFile(fileNameFull);
		*json = JSON::parse(jsonFile);
	}
	catch (const std::exception& e) {
		return e.what();
	}

	String fileName = filePath.stem().generic_string();
	std::unique_ptr<ArmA::armaData> arma{ std::make_unique<ArmA::armaData>(std::move(json), outputSize, callbackPtr, fileName) };
	std::thread thread1{ &ArmA::armaData::getDataToCallback, std::move(arma) };
	thread1.detach();

	return "Loading Data";
}

String ArmA::deleteData(const fs::path filePath) {
	String hasCopied;
	String fileNameFull = filePath.filename().generic_string();

	hasCopied = ArmA::copyJSONfile(filePath);
	fs::remove(filePath);

	String fmt = std::format("{} has been deleted. {}", fileNameFull, hasCopied);
	return fmt;
}
