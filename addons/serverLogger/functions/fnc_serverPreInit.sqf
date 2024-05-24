
/* ----------------------------------------------------------------------------
Function: 
    btc_serverLogger_fnc_serverPreInit

Description:
    Manages necessary event handling for server in preInit and CBA settings

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

call FUNC(serverSaveData);

call FUNC(clientsAddData);
call FUNC(serverAddData);

[
    QGVAR(logging_cooldown), // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "LIST", // setting type
    "Server logging period", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "=BTC= Server Logger Addon", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [[5, 10, 30, 60, 120, 180, 240, 300], ["5 seconds", "10 seconds", "30 seconds", "1 minute", "2 minutes", "3 minutes", "4 minutes", "5 minutes"], 3], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {  
        params ["_value"];

        GVAR(logging_cooldown) = _value;
        [GVAR(PFH)] call CBA_fnc_removePerFrameHandler;

        #ifdef DEBUG_MODE_FULL
            private _timestamp = [CBA_missionTime] call CBA_fnc_formatElapsedTime;
            [format ["%1: logging_cooldown set to %1", _timestamp, _value]] remoteExecCall ["systemChat", 0];
            diag_log format ["%1: logging_cooldown set to %2", __FILE__, _value];
        #endif

        [_value] call FUNC(serverPFH);
        
    } // function that will be executed once on mission start and every time the setting is changed.
     //_needRestart - Setting will be marked as needing mission restart after being changed. (optional, default false) <BOOL>
] call CBA_fnc_addSetting;