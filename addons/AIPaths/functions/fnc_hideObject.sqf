
/* ----------------------------------------------------------------------------
Function: 
    btc_AIPaths_fnc_initPostHideObject

Description:
    Hides textures ingame

Parameters:
    _object -

Returns:

Examples:
    (begin example)
        [cursorObject] call btc_AIPaths_fnc_initPostHideObject;
    (end)

Author:
    Fyuran

---------------------------------------------------------------------------- */
#include "..\script_component.hpp"

params[
    ["_object", objNull, [objNull]],
    ["_value", true, [false, 0]]
];
#ifdef DEBUG_MODE_FULL
    [format ["%1, called %2 is %3 being hidden", __LINE__, _object, ["","not"] select !_value]] remoteExecCall ["systemChat", 0];
#endif

if(_value isEqualType 0) then {
    _value = _value isEqualTo 1;
};
if(!isServer) exitWith {};
if(!_value) exitWith {};

GVAR(objects) = missionNamespace getVariable [QGVAR(objects), []];

private _textures = getObjectTextures _object;
{
    _object setObjectTextureGlobal [_forEachIndex, ""];
    GVAR(objects) pushBack _object;
}forEach _textures;