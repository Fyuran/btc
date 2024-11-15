#include "script_component.hpp"

class CfgPatches {
	class ADDON {
		name = "=BTC= Wearable Sleeve Insignia";
		author = "=BTC= Black Templars Clan";
        authors[] = {"=BTC=Fyuran"};
		units[] = {};
		url = "https://www.blacktemplars.it/";
		requiredVersion = 0.1;
		weapons[] = {};
		requiredAddons[] = {};
	};
};

class CfgUnitInsignia {
	class GVAR(1) {
		displayName = "Tiny Bunny - Alice the Fox";
		author = "Fyuran";
		texture = QPATHTOF(data\alissa_patch.paa);
		material = "\A3\Ui_f\data\GUI\Cfg\UnitInsignia\default_insignia.rvmat";
		textureVehicle = "";
	};

	class GVAR(medic_1) : GVAR(1) {
		displayName = "Medic - Patch 1";
		texture = QPATHTOF(data\medic_patch_1.paa);
	};

	class GVAR(medic_2) : GVAR(1) {
		displayName = "Medic - Patch 2";
		texture = QPATHTOF(data\medic_patch_2.paa);
	};
	
	class GVAR(medic_3) : GVAR(1) {
		displayName = "Medic - Patch 3";
		texture = QPATHTOF(data\medic_patch_3.paa);
	};
	
	class GVAR(medic_4) : GVAR(1) {
		displayName = "Medic - Patch 4";
		texture = QPATHTOF(data\medic_patch_4.paa);
	};
	
	class GVAR(medic_5) : GVAR(1) {
		displayName = "Medic - Patch 5";
		texture = QPATHTOF(data\medic_patch_5.paa);
	};

	class GVAR(medic_6) : GVAR(1) {
		displayName = "Medic - Patch 6";
		texture = QPATHTOF(data\medic_patch_6.paa);
	};
};