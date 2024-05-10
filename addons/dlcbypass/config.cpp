#include "script_component.hpp"
class CfgPatches
{
	class ADDON
	{
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"cba_xeh"};
		url = "http://www.blacktemplars.altervista.org";
		author[] = {"=BTC=Fyuran"};
		requiredVersion = "0.1";
	};
};
class Extended_InitPost_EventHandlers
{
	class LandVehicle
	{
		init = QUOTE(_this call FUNC(addAction));
	};
	class Air
	{
		init = QUOTE(_this call FUNC(addAction));
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

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_postInit));
    };
};