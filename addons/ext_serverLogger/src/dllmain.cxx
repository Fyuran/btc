#include "dllmain.h"
#include "armaLogFncs.h"
#include <thread>

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
	strncpy_safe(output, "use RVExtensionArgs, available functions: manageSession, manageNewSession", outputSize);
}

//"extension" callExtension["function", ["arguments"...]]
int RVExtensionArgs(char* output, int outputSize, const char* function, const char** args, int argsCnt) {
	std::vector<String> arguments;
	for (unsigned int i = 0; i < argsCnt; i++)
		arguments.push_back(args[i]);

	//String filename = arguments.at(1);
	//boost::remove_erase_if(filename, boost::is_any_of("\""));
	//BF::path p = BF::current_path() / filename.append(".csv");
	//if (BF::exists(p))
	//	BF::remove(p);

	/*DATA FUNCTIONS*/

	if (strcmp(function, "manageSession") == 0) {
		std::thread t1{ arma::manageSession, arguments };
		t1.detach();

		strncpy_safe(output, "data saved", outputSize);
		return 201;
	}

	/*---------------------*/
	strncpy_safe(output, "Available functions: manageSession, manageNewSession", outputSize);
	return -1;
}

// "btc_serverLogger" callExtension ["manageSession", ["tempMissionSP", "Altis", ["Server", "test", 0, 0]]];
// "btc_serverLogger" callExtension ["manageSession",["tempMissionSP", "Altis", ["=BTC= Cpl.Fyuran","_SERVER_",80,3800],["=BTC= Cpt.Ramius","12325425",56,3800],["=BTC= Col.Giallustio","12325425",45,3800],["=BTC= Cpl.Raven","12325425",45,3800]]];
// "btc_serverLogger" callExtension ["manageSession",["tempMissionSP", "Altis", ["=BTC= Cpl.Fyuran","_SERVER_",80,3800],["=BTC= Cpt.Ramius","12325425",56,3800],["=BTC= Col.Giallustio","12325425",45,3800]]];
// "btc_serverLogger" callExtension ["manageSession",["tempMissionSP", "Altis", ["=BTC= Cpl.Fyuran","_SERVER_",80,3800],["=BTC= Cpt.Ramius","12325425",56,3800],["=BTC= Col.Giallustio","12325425",45,3800],["=BTC= Cpl.Raven","12325425",50,3800]]];
// "btc_serverLogger" callExtension ["manageSession",["tempMissionSP", "Altis", ["=BTC= Cpl.Fyuran","_SERVER_",80,3800],["=BTC= Cpt.Ramius","12325425",56,3800],["=BTC= Cpl.Raven","12325425",87,3800], ["=BTC= Spc.Freeman","12325425",74,3800]]];