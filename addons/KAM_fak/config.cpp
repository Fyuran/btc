#include "script_component.hpp"
class CfgPatches {
	class ADDON {
		name = "=BTC= KAT FAKS";
		author = "=BTC= Black Templars Clan";
        authors[] = {"=BTC=Fyuran"};
		url = "http://www.blacktemplars.altervista.org";
		requiredVersion = 0.1;
		// List of objects (CfgVehicles classes) contained in the addon. Important also for Zeus content (units and groups) unlocking.
		units[] = {"kat_btc_FAK_M1_Item", "kat_btc_FAK_M1_Mag", "kat_btc_FAK_M2_Item", "kat_btc_FAK_M2_Mag"};
		// List of weapons (CfgWeapons classes) contained in the addon.
		weapons[] = {"kat_btc_FAK_M1", "kat_btc_FAK_M2"};
		requiredAddons[] = {"cba_xeh", "kat_main", "kat_misc"};
	};
};

#include "CfgFunctions.hpp"
#include "CfgVehicles.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"

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