/*
  Name: TFAR_fnc_vestLr

  Author: =BTC=Fyuran
    Returns the backpack radio (if there is one)

  Arguments:
    0: Unit <OBJECT>

  Return Value:
    Manpack or nil if no radio <ARRAY>

  Example:
    _radio = player call TFAR_fnc_vestLR;

  Public: Yes
*/

private _vest = vest _this;
if (([_vest, "tf_hasLRradio", 0] call TFAR_fnc_getWeaponConfigProperty) == 1) exitWith {
	private _dummy = _this getVariable ["TFAR_vest_radioLr",objNull];
	if(isNull _dummy) then {
		private _dummy_class = call {
			private _side = side _this;
			if (_side == WEST) exitWith {"TFAR_rt1523g"};
			if (_side == EAST) exitWith {"TFAR_mr3000"};
			if (_side == resistance) exitWith {"TFAR_anprc155"};
		};
		_dummy = _dummy_class createVehicleLocal [0,0,0];
		hideObject _dummy;
		_this setVariable ["TFAR_vest_radioLr",_dummy];
	};
	
    [_dummy, "radio_settings"]
};
nil