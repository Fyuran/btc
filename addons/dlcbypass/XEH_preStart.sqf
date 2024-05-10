#include "XEH_PREP.hpp"

_dlcsvehicles = [];

if !(isDLCAvailable 601670) then {
	_Jets = "getText (_x >> 'DLC' ) isEqualTo 'Jets' &&  
	{ getText (_x >> 'vehicleClass') isEqualTo 'Air' }" configClasses (configFile >> "CfgVehicles");
	_Jets = _Jets apply {configName _x};
	_dlcsvehicles append _Jets;
};

if !(isDLCAvailable 798390) then {
	_Tanks = "getText (_x >> 'DLC' ) isEqualTo 'Tank' &&  
	{ getText (_x >> 'vehicleClass') in ['Armored', 'Car'] }" configClasses (configFile >> "CfgVehicles");
	_Tanks = _Tanks apply {configName _x};
	_manual = ["B_AFV_Wheeled_01_cannon_F", "B_T_AFV_Wheeled_01_cannon_F", "B_AFV_Wheeled_01_up_cannon_F", 
	"B_T_AFV_Wheeled_01_up_cannon_F", "I_LT_01_AA_F", "I_LT_01_AT_F", "I_LT_01_scout_F", "I_LT_01_cannon_F"];
	_dlcsvehicles append _Tanks;
};

if !(isDLCAvailable 571710) then {
	_Orange = "getText (_x >> 'DLC' ) isEqualTo 'Orange' &&  
	{ getText (_x >> 'vehicleClass') in ['Armored', 'Car'] }" configClasses (configFile >> "CfgVehicles");
	_Orange = _Orange apply {configName _x};
	_dlcsvehicles append _Orange;
};

if !(isDLCAvailable 1021790) then {
	_Enoch = "getText (_x >> 'DLC' ) isEqualTo 'Enoch' &&  
	{ getText (_x >> 'vehicleClass') in ['Armored', 'Car'] }" configClasses (configFile >> "CfgVehicles");
	_Enoch = _Enoch apply {configName _x};
	_dlcsvehicles append _Enoch;
};

uiNamespace setVariable [QGVAR(vehicles), _dlcsvehicles];