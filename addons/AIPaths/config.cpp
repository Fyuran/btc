#include "script_component.hpp"
// z\btc\addons\AIPaths\materials\dev_2x2.paa
// #(rgb,8,8,3)color(1,0,0,1) R
// #(rgb,8,8,3)color(0,1,0,1) G 
// #(rgb,8,8,3)color(0,0,1,1) B

// a3\data_f\surfaces\beton.paa

// a3\data_f\default.rvmat
// LodNoShadow
class CfgPatches { 
	class ADDON {
		name = "=BTC= AI Paths";
		units[] = {
            QGVAR(2x2),
            QGVAR(2x2_45),
            QGVAR(Roadway_2x2),
            QGVAR(Roadway_2x2_45),

            QGVAR(2x4),
            QGVAR(2x4_45),
            QGVAR(Roadway_2x4),
            QGVAR(Roadway_2x4_45),

            GVAR(4x4),
            GVAR(4x4_45),
            GVAR(Roadway_4x4),
            GVAR(Roadway_4x4_45)

            GVAR(Roadway_4x2_45)
        };
		weapons[] = {};
		requiredAddons[] = {"cba_xeh"};
		url = "https://www.blacktemplars.it/";
		author = "=BTC= Black Templars Clan";
        authors[] = {"=BTC= Fyuran"};
		requiredVersion = "0.1";
	};
}; 

class CBA_Extended_EventHandlers_base;
class CfgVehicles {
	class House;
    
	class GVAR(2x2): House {
        author = "=BTC= Fyuran";  
        displayName = "BTC - AI Path 2x2"; 
        model = QPATHTOF(models\AIPath_2x2.p3d); 
        scope = 2; 
        picture = "pictureStaticObject"; 
        hiddenSelections[] = { 
            "Center_spheres",
			"Outside_spheres",
			"Path_Trace" 
        };
		scopeCurator = 2;
        hiddenSelectionsTextures[] = {
            "#(rgb,8,8,3)color(1,0,0,1)",
            "#(rgb,8,8,3)color(0,0,1,1)",
            "#(rgb,8,8,3)color(0,1,0,1)"
        };
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
        class Attributes {
			class GVAR(Attribute_1) {
                displayName = "$STR_BTC_AIPATHS_HIDEOBJECT"; // Name assigned to UI control class Title
				tooltip = "$STR_BTC_AIPATHS_HIDEOBJECT_TOOLTIP"; // Tooltip assigned to UI control class Title
				property = QGVAR(hideObject); // Unique config property name saved in SQM
				control = "Checkbox"; // UI control base class displayed in Edit Attributes window, points to Cfg3DEN >> Attributes
                
                /*Expression called when applying the attribute in Eden and at the scenario start
			    The expression is called twice - first for data validation, and second for actual saving
				Entity is passed as _this, value is passed as _value
				%s is replaced by attribute config name
				In MP scenario, the expression is called only on server.*/
                expression = QUOTE([_this, _value] call FUNC(hideObject));

                /*Expression called when custom property is undefined yet (i.e., when setting the attribute for the first time)
                Entity (unit, group, marker, comment etc.) is passed as _this
                Returned value is the default value
                BOOLs are passed as numbers ex: 0-false 1-true
                Used when no value is returned, or when it is of other type than NUMBER, STRING or ARRAY
                Custom attributes of logic entities (e.g., modules) are saved always, even when they have default value*/
                defaultValue = true;

                
                //--- Optional properties
                unique = 0; // When 1, only one entity of the type can have the value in the mission (used for example for variable names or player control)
                //validate = "condition"; // Validate the value before saving. If the value is not of given type e.g. "number", the default value will be set. Can be "none", "expression", "condition", "number" or "variable"
                //condition = "object"; // Condition for attribute to appear
                //typeName = "BOOL"; // Defines data type of saved value, can be STRING, NUMBER or BOOL. Used only when control is "Combo", "Edit" or their variants. This is a scripted feature and has no engine support. See code in (configFile >> "Cfg3DEN" >> "Attributes" >> "Combo" >> "attributeSave")
			};
		};
	};
    class GVAR(2x2_45): GVAR(2x2) {
        displayName = "BTC - AI Path 2x2(45°)"; 
        model = QPATHTOF(models\AIPath_2x2_45.p3d); 
	};
	class GVAR(Roadway_2x2): GVAR(2x2) {
        displayName = "BTC - AI Path 2x2(Roadway)"; 
        model = QPATHTOF(models\AIPath_Roadway_2x2.p3d); 
        hiddenSelections[] = { 
            "Plane",
            "Center_spheres",
			"Outside_spheres",
			"Path_Trace" 
        };
        hiddenSelectionsTextures[] = {
            "\z\btc\addons\aipaths\materials\dev_2x2.paa",
            "#(rgb,8,8,3)color(1,0,0,1)",
            "#(rgb,8,8,3)color(0,0,1,1)",
            "#(rgb,8,8,3)color(0,1,0,1)"
        };
	};
    class GVAR(Roadway_2x2_45): GVAR(Roadway_2x2) {
        displayName = "BTC - AI Path 2x2(Roadway 45°)";
        model = QPATHTOF(models\AIPath_Roadway_2x2_45.p3d); 
	};


    class GVAR(2x4): GVAR(2x2) {
        displayName = "BTC - AI Path 2x4"; 
        model = QPATHTOF(models\AIPath_2x4.p3d); 
	};
    class GVAR(2x4_45): GVAR(2x4) {
        displayName = "BTC - AI Path 2x4(45°)"; 
        model = QPATHTOF(models\AIPath_2x4_45.p3d); 
	};
    class GVAR(Roadway_2x4): GVAR(Roadway_2x2) {
        displayName = "BTC - AI Path 2x4(Roadway)";
        model = QPATHTOF(models\AIPath_Roadway_2x4.p3d); 
        hiddenSelectionsTextures[] = {
            "\z\btc\addons\aipaths\materials\dev_2x4.paa",
            "#(rgb,8,8,3)color(1,0,0,1)",
            "#(rgb,8,8,3)color(0,0,1,1)",
            "#(rgb,8,8,3)color(0,1,0,1)"
        };
	};
    class GVAR(Roadway_2x4_45): GVAR(Roadway_2x4) {
        displayName = "BTC - AI Path 2x4(Roadway 45°)";
        model = QPATHTOF(models\AIPath_Roadway_2x4_45.p3d); 
	};


    class GVAR(4x4): GVAR(2x2) {
        displayName = "BTC - AI Path 4x4";
        model = QPATHTOF(models\AIPath_4x4.p3d); 
    };
    class GVAR(4x4_45): GVAR(4x4) {
        displayName = "BTC - AI Path 4x4(45°)";
        model = QPATHTOF(models\AIPath_4x4_45.p3d); 
	};
	class GVAR(Roadway_4x4): GVAR(Roadway_2x2) {
        displayName = "BTC - AI Path 4x4(Roadway)";
        model = QPATHTOF(models\AIPath_Roadway_4x4.p3d); 
        hiddenSelectionsTextures[] = {
            "\z\btc\addons\aipaths\materials\dev_4x4.paa",
            "#(rgb,8,8,3)color(1,0,0,1)",
            "#(rgb,8,8,3)color(0,0,1,1)",
            "#(rgb,8,8,3)color(0,1,0,1)"
        };
    };
    class GVAR(Roadway_4x4_45): GVAR(Roadway_4x4) {
        displayName = "BTC - AI Path 4x4(Roadway 45°)";
        model = QPATHTOF(models\AIPath_Roadway_4x4_45.p3d); 
	};


    class GVAR(4x2_45): GVAR(2x2) {
        displayName = "BTC - AI Path 4x2(45°)";
        model = QPATHTOF(models\AIPath_4x2_45.p3d); 
    };
	class GVAR(Roadway_4x2_45): GVAR(Roadway_2x2) {
        displayName = "BTC - AI Path 4x2(Roadway 45°)";
        model = QPATHTOF(models\AIPath_Roadway_4x2_45.p3d); 
        hiddenSelectionsTextures[] = {
            "\z\btc\addons\aipaths\materials\dev_4x2.paa",
            "#(rgb,8,8,3)color(1,0,0,1)",
            "#(rgb,8,8,3)color(0,0,1,1)",
            "#(rgb,8,8,3)color(0,1,0,1)"
        };
    };
};

class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

/*
class Extended_InitPost_EventHandlers {
    class GVAR(2x2) {
        class GVAR(InitPost) {
            serverInit = QUOTE(_this call FUNC(initPostHideObject));
        };   
    };
    class GVAR(2x2_45): GVAR(2x2) {};
    class GVAR(Roadway_2x2) : GVAR(2x2) {};
    class GVAR(Roadway_2x2_45) : GVAR(Roadway_2x2) {};


    class GVAR(2x4): GVAR(2x2) {};
    class GVAR(2x4_45): GVAR(2x4) {};
    class GVAR(Roadway_2x4): GVAR(2x2) {};
    class GVAR(Roadway_2x4_45): GVAR(Roadway_2x4) {};


    class GVAR(4x4): GVAR(2x2) {};
    class GVAR(4x4_45): GVAR(4x4) {};
    class GVAR(Roadway_4x4): GVAR(2x2) {};
    class GVAR(Roadway_4x4_45): GVAR(Roadway_4x4) {};
};*/
