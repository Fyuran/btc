#include "dllmain.h"
#include "armaLogData.h"

constexpr auto CURRENT_VERSION = "1.0.0.0";

int strncpy_safe(char* output, const char* src, int size)
{
	int i;
	size--;
	for (i = 0; i < size && src[i] != '\0'; i++)
	{
		output[i] = src[i];
	}
	output[i] = '\0';
	return i;
}

//--- Extension version information shown in .rpt file
void RVExtensionVersion(char* output, int outputSize) {
	//--- max outputSize is 32 bytes
	strncpy_safe(output, CURRENT_VERSION, outputSize);
}

void RVExtension(char* output, int outputSize, const char* function) {
	strncpy_safe(output, "", outputSize);
}

//"extension" callExtension["function", ["arguments"...]]
int RVExtensionArgs(char* output, int outputSize, const char* function, const char** args, int argsCnt) {
	std::vector<std::vector<String>> arguments;

	for (unsigned int i = 0; i < argsCnt; i++) {
		std::vector<String> argument;
		boost::algorithm::split(argument, args[i], boost::is_any_of(","));
		for (String& s : argument) {
			boost::remove_erase_if(s, boost::is_any_of("[]"));
			boost::trim(s);
		}
		arguments.push_back(argument);
	}
	

	/*DATA FUNCTIONS*/
	if (strcmp(function, "saveLogData") == 0) {
		arma::saveLogData(arguments);
		strncpy_safe(output, "data saved", outputSize);
		return 201;
	}

	/*---------------------*/
	strncpy_safe(output, "Available Functions: saveLogData", outputSize);
	return -1;
}

//"btc_serverLogger" callExtension ""
// "btc_serverLogger" callExtension ["saveLogData",[["0:00:17","=BTC= Cpl.Fyuran","_SERVER_ _SP_PLAYER_",144.144,3800,"tempMissionSP"],["0:00:17","Your mum","13123134",144.144,3800,"tempMissionSP"]]];