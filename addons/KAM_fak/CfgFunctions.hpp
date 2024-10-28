class CfgFunctions {
    class overwrite_kat_misc_FAK {
        tag = "kat_misc";
        class kat_misc {
            class ammoToArray {
                file = QPATHTOF(functions\fnc_FAK_ammoToArray.sqf);
            };
            class treatmentSuccess {
                file = QPATHTOF(functions\fnc_FAK_arrayToAmmo.sqf);
            };
            class checkRepack {
                file = QPATHTOF(functions\fnc_FAK_checkRepack.sqf);
            };
            class checkSlot {
                file = QPATHTOF(functions\fnc_FAK_checkSlot.sqf);
            };
            class displayContent {
                file = QPATHTOF(functions\fnc_FAK_displayContent.sqf);
            };
            class repack {
                file = QPATHTOF(functions\fnc_FAK_repack.sqf);
            };
            class unpack {
                file = QPATHTOF(functions\fnc_FAK_unpack.sqf);
            };
            class updateContents {
                file = QPATHTOF(functions\fnc_FAK_updateContents.sqf);
            };
        };
    };
};