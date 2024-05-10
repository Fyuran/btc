
/*
PREP MACRO ’\MAINPREFIX\PREFIX\SUBPREFIX\COMPONENT\fnc_<FNC>.sqf’
ADDON is already defined by CBA(PREFIX,COMPONENT)
*/
#include "script_component.hpp"
class CfgPatches {
	class ADDON {
		name = "=BTC= Water Bottle & Canteen stamina regain";
		author = "=BTC= Black Templars Clan";
        authors[] = {"=BTC=Fyuran"};
		units[] = {"ACE_Canteen_Nearly_Empty_Item","ACE_Canteen_Nearly_Full_Item"};
		url = "http://www.blacktemplars.altervista.org";
		requiredVersion = 0.1;
		weapons[] = {"ACE_Canteen_Nearly_Empty","ACE_Canteen_Nearly_Full"};
		requiredAddons[] = {"ace_advanced_fatigue","ace_interaction","ace_medical_feedback","ace_field_rations"};
	};
};

class CfgWeapons {
    
};

class CfgVehicles {

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

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_postInit));
    };
};