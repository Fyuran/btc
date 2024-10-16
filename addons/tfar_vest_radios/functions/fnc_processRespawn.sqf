/*
  Name: TFAR_fnc_processRespawn

  Author: NKey, Garth de Wet (L-H), =BTC=Fyuran
    Handles getting switching radios, handles whether a manpack must be added to the player or not.

  Arguments:
    None

  Return Value:
    None

  Example:
    call TFAR_fnc_processRespawn;

  Public: No
*/

params ["_newUnit", "_corpse"]; //_this implicitly passed from the EH

//Arma might lag behind and others still see the unit as alive and think it's a spectator
_corpse setVariable ["TFAR_forceSpectator", false, true];

[{!(isNull player)}, {
    TFAR_currentUnit = call TFAR_fnc_currentUnit;

    TF_respawnedAt = time;
    if (alive TFAR_currentUnit) then {
        if (TFAR_giveMicroDagrToSoldier)  then {
            TFAR_currentUnit linkItem "TFAR_microdagr";
        };

        [
            {(time - TF_respawnedAt > 5)},
            {true call TFAR_fnc_requestRadios;}
        ] call CBA_fnc_waitUntilAndExecute;
		
		//Handle vest
		_old_vest_radioLr = _corpse getVariable ["TFAR_vest_radioLr",objNull];
		if(!isNull _old_vest_radioLr) then {
			private _vestDummy = _newUnit setVariable ["TFAR_vest_radioLr",_old_vest_radioLr];
		};
		
        //Handle backpack replacement for group leaders
        if (leader TFAR_currentUnit != TFAR_currentUnit) exitWith {};
        if (!TFAR_giveLongRangeRadioToGroupLeaders or {backpack TFAR_currentUnit == "B_Parachute"} or {player call TFAR_fnc_isForcedCurator}) exitWith {};
        if ([(backpack TFAR_currentUnit), "tf_hasLRradio", 0] call TFAR_fnc_getVehicleConfigProperty == 1) exitWith {};
		
        private _items = backpackItems TFAR_currentUnit;
        private _backPack = unitBackpack TFAR_currentUnit;
        private _newItems = [];

        TFAR_currentUnit action ["putbag", TFAR_currentUnit];
        //In my tests in editor it took 0.89 seconds till the backpack is down
        [{backpack TFAR_currentUnit == ""},
        {
            TFAR_currentUnit addBackpack ((TFAR_currentUnit call TFAR_fnc_getDefaultRadioClasses) select 0);
            {
                if (TFAR_currentUnit canAddItemToBackpack _x) then {
                    TFAR_currentUnit addItemToBackpack _x;
                } else {
                    _newItems pushBack _x;
                };
                true;
            } count _items;

            clearItemCargoGlobal _backPack;
            clearMagazineCargoGlobal _backPack;
            clearWeaponCargoGlobal _backPack;
            {
                if (isClass (configFile >> "CfgMagazines" >> _x)) then{
                    _backPack addMagazineCargoGlobal [_x, 1];
                } else {
                    _backPack addItemCargoGlobal [_x, 1];
                    _backPack addWeaponCargoGlobal [_x, 1];
                };
                true;
            } count _newItems;
        }] call CBA_fnc_waitUntilAndExecute;
    };
    [TFAR_currentUnit, false] call TFAR_fnc_forceSpectator;
    if (TFAR_ShowVolumeHUD) then { //#TODO should really move this into a macro
        ("TFAR_core_HUDVolumeIndicatorRsc" call BIS_fnc_rscLayer) cutRsc ["TFAR_core_HUDVolumeIndicatorRsc", "PLAIN", 0, true];
    };
    call TFAR_fnc_updateSpeakVolumeUI;
}] call CBA_fnc_waitUntilAndExecute;
