
/* ----------------------------------------------------------------------------
Function: 
    btc_serverLogger_fnc_serverPreInit

Description:
    Manages necessary event handling for server in preInit

Parameters:

Returns:

Examples:
    (begin example)
        [] call btc_serverLogger_fnc_serverPreInit;
    (end)

Author:
    Fyuran

---------------------------------------------------------------------------- */
#include "..\script_component.hpp"

[
    QGVAR(logging_cooldown), // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "LIST", // setting type
    "Server logging period", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "Server Logger Addon", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [[1, 2, 3, 4, 5], ["1 minute", "2 minutes", "3 minutes", "4 minutes", "5 minutes"], 1], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {  
        params ["_value"];
        GVAR(logging_cooldown) = _value * 60;
        #ifdef DEBUG_MODE_FULL
            [format ["%1: logging_cooldown set to %2", __FILE__, GVAR(logging_cooldown)]] remoteExecCall ["systemChat", 0];
        #endif
    }, // function that will be executed once on mission start and every time the setting is changed.
    true //_needRestart - Setting will be marked as needing mission restart after being changed. (optional, default false) <BOOL>
] call CBA_fnc_addSetting;

//server manages receiving data
GVAR(addData_EH) = [QGVAR(addData_EH), { 
    params [
        ["_name", "", [""]],
        ["_uid", "", [""]],
        ["_fps", -1, [0]],
        ["_viewDistance", -1, [0]],
        ["_timestamp", -1, [0]]
    ];

    private _hash = ["name", "uid", "fps", "viewDistance", "timestamp"] createHashMapFromArray [
        _name,
        _uid,
        _fps,
        _viewDistance,
        _timestamp
    ];

    GVAR(logger_data) set [_uid, _hash];

    #ifdef DEBUG_MODE_FULL
        [format ["%1: adding data: %2", __FILE__, _this]] remoteExecCall ["systemChat", 0];
    #endif
}] call CBA_fnc_addEventHandler;

//manages client's data on the client's network side
GVAR(JIP_Clients_EH_ID) = [{
    if(!hasInterface) exitWith {};
    
    GVAR(client_sendData_EH) = [QGVAR(client_sendData_EH), { 

        private _data = [
            name player,
            getPlayerUID player,
            diag_fps, //average framerate calculated over last 16 frames.
            viewDistance,
            CBA_missionTime
        ];

        [QGVAR(addData_EH), _data] call CBA_fnc_serverEvent;

        #ifdef DEBUG_MODE_FULL
            [format ["%1: %2(%3) sending data: %4", __FILE__, name player, getPlayerUID player, _data]] remoteExecCall ["systemChat", 0];
        #endif
    }] call CBA_fnc_addEventHandler;
}] remoteExecCall ["call", [0, -2] select isDedicated, true];

//periodic EH trigger
if(isNil QGVAR(logging_cooldown)) then {
    GVAR(logging_cooldown) = 2 * 60;
};
GVAR(PFH) = [{
    GVAR(logger_data) = createHashMap;
    if(isDedicated) then [{
        [QGVAR(client_sendData_EH)] call CBA_fnc_remoteEvent;
    }, {
        [QGVAR(client_sendData_EH)] call CBA_fnc_globalEvent;
    }];
    
    private _allPlayers = allPlayers - entities "HeadlessClient_F";
    if(count _allPlayers isEqualTo 0) exitWith {
        #ifdef DEBUG_MODE_FULL
            [format ["%1: no players found", __FILE__]] remoteExecCall ["systemChat", 0];
        #endif
    };

    private _statement = {
        #ifdef DEBUG_MODE_FULL
            [format ["%1: data threshold reached or timeout reached, calling extension", __FILE__]] remoteExecCall ["systemChat", 0];
        #endif
    };

    [{
        (count GVAR(logger_data)) isEqualTo (_this#0)
    }, _statement, [count _allPlayers], 60, _statement] call CBA_fnc_waitUntilAndExecute;

    #ifdef DEBUG_MODE_FULL
        [format ["clients should be sending data...", __FILE__, _this]] remoteExecCall ["systemChat", 0];
    #endif
}, GVAR(logging_cooldown), []] call CBA_fnc_addPerFrameHandler;