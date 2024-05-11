#include "script_component.hpp"
// z\btc\addons\AIPaths\materials\dev_2x2.paa
// z\btc\addons\AIPaths\materials\dev_wall.paa
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

            QGVAR(2x4),
            QGVAR(2x4_45),

            GVAR(4x2_45),

            GVAR(4x4),
            GVAR(4x4_45),

            GVAR(4x6),

            GVAR(6x4_45),

            GVAR(6x6),

            GVAR(Wall_4x1),
	        GVAR(Wall_4x2),
            GVAR(Wall_6x1),
	        GVAR(Wall_6x2)
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
        displayName = "AI Path 2x2"; 
        model = QPATHTOF(models\Floor_2x2.p3d); 
        scope = 2; 
        picture = "pictureStaticObject";
        icon = "\z\btc\addons\AIPaths\materials\iconAIObject.paa";
        hiddenSelections[] = { 
            "Plane",
            "Center_spheres",
			"Outside_spheres",
			"Path_Trace" 
        };
		scopeCurator = 2;
        hiddenSelectionsTextures[] = {
            "\z\btc\addons\aipaths\materials\dev_2x2.paa",
            "#(rgb,8,8,3)color(1,0,0,1)",
            "#(rgb,8,8,3)color(0,0,1,1)",
            "#(rgb,8,8,3)color(0,1,0,1)"
        };
        editorCategory = QGVAR(EdCat_AIHelpers);
        editorSubcategory = QGVAR(EdSubcat_2x2);
        vehicleClass = "Helpers";
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
	};
    class GVAR(2x2_45): GVAR(2x2) {
        displayName = "AI Path 2x2(45°)"; 
        model = QPATHTOF(models\Floor_2x2_45.p3d); 
	};


    class GVAR(2x4): GVAR(2x2) {
        displayName = "AI Path 2x4"; 
        editorSubcategory = QGVAR(EdSubcat_2x4);
        model = QPATHTOF(models\Floor_2x4.p3d); 
        hiddenSelectionsTextures[] = {
            "\z\btc\addons\aipaths\materials\dev_2x4.paa",
            "#(rgb,8,8,3)color(1,0,0,1)",
            "#(rgb,8,8,3)color(0,0,1,1)",
            "#(rgb,8,8,3)color(0,1,0,1)"
        };
	};
    class GVAR(2x4_45): GVAR(2x4) {
        displayName = "AI Path 2x4(45°)"; 
        model = QPATHTOF(models\Floor_2x4_45.p3d); 
	};




    class GVAR(4x2_45): GVAR(2x2) {
        displayName = "AI Path 4x2(45°)";
        editorSubcategory = QGVAR(EdSubcat_4x2);
        model = QPATHTOF(models\Floor_4x2_45.p3d);
        hiddenSelectionsTextures[] = {
            "\z\btc\addons\aipaths\materials\dev_4x2.paa",
            "#(rgb,8,8,3)color(1,0,0,1)",
            "#(rgb,8,8,3)color(0,0,1,1)",
            "#(rgb,8,8,3)color(0,1,0,1)"
        }; 
    };


    class GVAR(4x4): GVAR(2x2) {
        displayName = "AI Path 4x4";
        editorSubcategory = QGVAR(EdSubcat_4x4);
        model = QPATHTOF(models\Floor_4x4.p3d); 
        hiddenSelectionsTextures[] = {
            "\z\btc\addons\aipaths\materials\dev_4x4.paa",
            "#(rgb,8,8,3)color(1,0,0,1)",
            "#(rgb,8,8,3)color(0,0,1,1)",
            "#(rgb,8,8,3)color(0,1,0,1)"
        };
    };
    class GVAR(4x4_45): GVAR(4x4) {
        displayName = "AI Path 4x4(45°)";
        model = QPATHTOF(models\Floor_4x4_45.p3d); 
	};


    class GVAR(4x6): GVAR(2x2) {
        displayName = "AI Path 4x6";
        editorSubcategory = QGVAR(EdSubcat_4x6);
        model = QPATHTOF(models\Floor_4x6.p3d); 
        hiddenSelectionsTextures[] = {
            "\z\btc\addons\aipaths\materials\dev_4x6.paa",
            "#(rgb,8,8,3)color(1,0,0,1)",
            "#(rgb,8,8,3)color(0,0,1,1)",
            "#(rgb,8,8,3)color(0,1,0,1)"
        };
    };


    class GVAR(6x4_45): GVAR(2x2) {
        displayName = "AI Path 6x4(45°)";
        editorSubcategory = QGVAR(EdSubcat_6x4);
        model = QPATHTOF(models\Floor_6x4_45.p3d);
        hiddenSelectionsTextures[] = {
            "\z\btc\addons\aipaths\materials\dev_6x4.paa",
            "#(rgb,8,8,3)color(1,0,0,1)",
            "#(rgb,8,8,3)color(0,0,1,1)",
            "#(rgb,8,8,3)color(0,1,0,1)"
        }; 
    };


    class GVAR(6x6): GVAR(2x2) {
        displayName = "AI Path 6x6";
        editorSubcategory = QGVAR(EdSubcat_6x6);
        model = QPATHTOF(models\Floor_6x6.p3d); 
        hiddenSelectionsTextures[] = {
            "\z\btc\addons\aipaths\materials\dev_6x6.paa",
            "#(rgb,8,8,3)color(1,0,0,1)",
            "#(rgb,8,8,3)color(0,0,1,1)",
            "#(rgb,8,8,3)color(0,1,0,1)"
        };
    };


    class Wall_F;
    class GVAR(Wall_4x1): Wall_F {
        author = "=BTC= Fyuran";  
        scope = 2; 
        picture = "pictureStaticObject";
        icon = "\z\btc\addons\AIPaths\materials\iconAIObject.paa";
		scopeCurator = 2;
		displayName = "AI Wall 4x1";
        model = QPATHTOF(models\Wall_4x1.p3d); 
        editorCategory = QGVAR(EdCat_AIHelpers);
        vehicleClass = "Helpers";
        editorSubcategory = QGVAR(EdSubcat_Walls);
        hiddenSelections[] = { 
            "Wall"
        };
        hiddenSelectionsTextures[] = {
            "\z\btc\addons\aipaths\materials\dev_wall.paa"
        }; 

        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
	};
	class GVAR(Wall_4x2): GVAR(Wall_4x1) {
		displayName = "AI Wall 4x2"; 
        model = QPATHTOF(models\Wall_4x2.p3d); 
    };
    class GVAR(Wall_6x1): GVAR(Wall_4x1) {
		displayName = "AI Wall 6x1"; 
        model = QPATHTOF(models\Wall_6x1.p3d); 
    };
    class GVAR(Wall_6x2): GVAR(Wall_4x1) {
		displayName = "AI Wall 6x2"; 
        model = QPATHTOF(models\Wall_6x2.p3d); 
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


class Extended_InitPost_EventHandlers {
    class GVAR(2x2) {
        class GVAR(InitPost) {
            serverInit = QUOTE(_this call FUNC(hideObject));
        };   
    };
    class GVAR(2x2_45): GVAR(2x2) {};

    class GVAR(2x4): GVAR(2x2) {};
    class GVAR(2x4_45): GVAR(2x4) {};

    class GVAR(4x2_45): GVAR(2x2) {};

    class GVAR(4x4): GVAR(2x2) {};
    class GVAR(4x4_45): GVAR(4x4) {};

    class GVAR(4x6): GVAR(2x2) {};

    class GVAR(6x4_45): GVAR(2x2) {};

    class GVAR(6x6): GVAR(2x2) {};

    class GVAR(Wall_4x1): GVAR(2x2) {};
    class GVAR(Wall_4x2): GVAR(2x2) {};
    class GVAR(Wall_6x1): GVAR(2x2) {};
    class GVAR(Wall_6x2): GVAR(2x2) {};
};

class CfgEditorCategories {
    class GVAR(EdCat_AIHelpers) {
        displayName = "AI Helpers";
    };
};

class CfgEditorSubcategories {
    class GVAR(EdSubcat_2x2) {
        displayName = "2 by 2";
    };

    class GVAR(EdSubcat_2x4) {
        displayName = "2 by 4";
    };

    class GVAR(EdSubcat_4x2) {
        displayName = "4 by 2";
    };

    class GVAR(EdSubcat_4x4) {
        displayName = "4 by 4";
    };

    class GVAR(EdSubcat_4x6) {
        displayName = "4 by 6";
    };

    class GVAR(EdSubcat_6x4) {
        displayName = "6 by 4";
    };

    class GVAR(EdSubcat_6x6) {
        displayName = "6 by 6";
    };

    class GVAR(EdSubcat_Walls) {
        displayName = "Walls";
    };
};
