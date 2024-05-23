
/* ----------------------------------------------------------------------------
Function: 
    btc_serverLogger_fnc_serverAddData

Description:
    Adds server data to global var holding clients data

Parameters:

Returns:

Examples:
    (begin example)
        [] call btc_serverLogger_fnc_serverAddData;
    (end)

Author:
    Fyuran

---------------------------------------------------------------------------- */
#include "..\script_component.hpp"

GVAR(addData_EH) = [QGVAR(addData_EH), { 

    private _name = serverName;
    private _uid = "_SERVER_";
    if(!isDedicated) then { //listen server acts as client machine too
        _name = name player;
        _uid = _uid insert [-1, " " + getPlayerUID player];
    };

    private _data = [
        _name,
        _uid,
        diag_fps,
        viewDistance,
        missionName
    ];

    #ifdef DEBUG_MODE_FULL
        private _timestamp = [CBA_missionTime] call CBA_fnc_formatElapsedTime;
        [format["%1: server adding its data", _timestamp]] remoteExecCall ["systemChat", 0];
        diag_log format ["%1: server adding its data %2", __FILE__, _data];
    #endif

    [QGVAR(server_saveData_EH), _data] call CBA_fnc_serverEvent;

}] call CBA_fnc_addEventHandler;