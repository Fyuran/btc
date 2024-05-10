/* ----------------------------------------------------------------------------
Function: btc_dlcbypass_fnc_addAction

Description:
Allows non-owners of DLC to enter as either driver, pilot/co-pilot, gunner or commander.

Parameters:
<Object> Vehicle
<String> Colour

Returns:
None

Examples:
[cursorTarget,"#00FFFF"] call btc_dlcbypass_fnc_addAction

Author: =BTC=Fyuran

---------------------------------------------------------------------------- */
#define __ACTION_DIS 8
#include "script_component.hpp"

params [
	["_vehicle",objNull,[objNull]],
	["_colour","#00FFFF",[""]]
];
if !(alive _vehicle) exitWith {};

private _classNames = uiNamespace getVariable [QGVAR(vehicles)];
if !(typeOf _vehicle in _classNames) exitWith {};
if (_classNames isEqualTo []) exitWith {};

private _vehicleName = (getText(configfile >> "CfgVehicles" >> typeOf _vehicle >> "displayName"));

//GetIn
private _str_driver = ["Get in %1 as Driver","Get in %1 as Pilot"] select (_vehicle isKindOf "Air");

_vehicle addAction
[
		format["<t color='%2'>%1</t>",
		format[_str_driver, _vehiclename], // %1
		_colour], // %2
	{
		(_this select 1) moveInDriver(_this select 0);
	},
	nil,
	3,
	true,
	true,
	'',
	'
		(vehicle _this isEqualTo _this) &&
		{isNull driver _target} &&
		{locked _target <= 1}
	',
	__ACTION_DIS
];


if ((_vehicle emptyPositions "gunner") > 0) then {
	_vehicle addAction
	[
			format["<t color='%2'>%1</t>",
			format["Get in %1 as Gunner", _vehiclename], // %1
			_colour], // %2
		{
			(_this select 1) moveInGunner(_this select 0);
		},
		nil,
		3,
		true,
		true,
		'',
		'
			(vehicle _this isEqualTo _this) &&
			{isNull gunner _target} &&
			{locked _target <= 1}
		',
		__ACTION_DIS
	];
};

if ((_vehicle emptyPositions "commander") > 0) then {
	_vehicle addAction
	[
			format["<t color='%2'>%1</t>",
			format["Get in %1 as Commander", _vehiclename], // %1
			_colour], // %2
		{
			(_this select 1) moveInCommander(_this select 0);
		},
		nil,
		3,
		true,
		true,
		'',
		'
			(vehicle _this isEqualTo _this) &&
			{isNull commander _target} &&
			{locked _target <= 1}		
		',
		__ACTION_DIS
	];
};

//SwitchTo
private _str_ToDriver = ["To Driver's seat","To Pilot's seat"] select (_vehicle isKindOf "Air");

_vehicle addAction
[
		format["<t color='%2'>%1</t>",
		_str_ToDriver, // %1
		_colour], // %2
	{
		params ["_target", "_caller"];
		if(!local _target) then {
			[_target, clientOwner] remoteExecCall["setOwner", 2];
		};
		[{local (_this select 0)}, {
			params ["_target", "_caller"];
			moveOut _caller;		
			_caller moveInDriver _target;
		}, [_target, _caller]] call CBA_fnc_waitUntilAndExecute;

	},
	nil,
	3,
	true,
	true,
	'',
	'
		(vehicle _this isEqualTo _target) &&
		{isNull driver _target} &&
		{locked _target <= 1}
	',
	__ACTION_DIS
];


if ((_vehicle emptyPositions "gunner") > 0) then {
	_vehicle addAction
	[
			format["<t color='%2'>%1</t>",
			"To Gunner's seat", // %1
			_colour], // %2
		{
			params ["_target", "_caller"];
			if(!local _target) then {
				[_target, clientOwner] remoteExecCall["setOwner", 2];
			};
			[{local (_this select 0)}, {
				params ["_target", "_caller"];
				moveOut _caller;		
				_caller moveInGunner _target;
			}, [_target, _caller]] call CBA_fnc_waitUntilAndExecute;

		},
		nil,
		3,
		true,
		true,
		'',
		'
			(vehicle _this isEqualTo _target) &&
			{isNull gunner _target} &&
			{locked _target <= 1}
		',
		__ACTION_DIS
	];
};

if ((_vehicle emptyPositions "commander") > 0) then {
	_vehicle addAction
	[
			format["<t color='%2'>%1</t>",
			"To Commander's seat", // %1
			_colour], // %2
		{
			params ["_target", "_caller"];
			if(!local _target) then {
				[_target, clientOwner] remoteExecCall["setOwner", 2];
			};
			[{local (_this select 0)}, {
				params ["_target", "_caller"];
				moveOut _caller;		
				_caller moveInCommander _target;
			}, [_target, _caller]] call CBA_fnc_waitUntilAndExecute;

		},
		nil,
		3,
		true,
		true,
		'',
		'
			(vehicle _this isEqualTo _target) &&
			{isNull commander _target} &&
			{locked _target <= 1}	
		',
		__ACTION_DIS
	];
};