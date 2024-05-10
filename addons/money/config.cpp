#define mag_xx(a,b) class _xx_##a {magazine = a; count = b;}
#define weap_xx(a,b) class _xx_##a {weapon = a; count = b;}
#define item_xx(a,b) class _xx_##a {name = a; count = b;}
#include "script_component.hpp"

class CfgPatches { 
	class ADDON {
		name = "=BTC= Money";
		units[] = {QGVAR(stack_Item),GVAR(stack_small),GVAR(stack_medium),GVAR(stack_large),GVAR(pallet),GVAR(pallet_empty)};
		weapons[] = {QGVAR(stack)};
		requiredAddons[] = {"cba_xeh", "A3_Weapons_F"};
		url = "http://www.blacktemplars.altervista.org";
		author = "=BTC= Black Templars Clan";
        authors[] = {"=BTC=Fyuran"};
		requiredVersion = "0.1";
	};
}; 

class CfgWeapons {
    class CBA_MiscItem; 
	class CBA_MiscItem_ItemInfo;
    class GVAR(stack): CBA_MiscItem {
        author = "=BTC=Fyuran";  
        displayName = "Money Stack"; 
        model = QPATHTOF(data\money_stack.p3d); 
        scope = 2; 
        picture = QPATHTOF(data\1_usd.paa);   
        descriptionShort = "United States Dollars";
		descriptionUse = "<t color='#9cf953'>Use: </t>Purchase items at base shop.";
		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 0.01;
		};
	};
};

class CfgVehicles {
	class Item_Base_F;
	class GVAR(stack_Item): Item_Base_F {
        author = "=BTC=Fyuran";  
        displayName = "Money Stack"; 
        model = "\A3\Weapons_F\DummyItemHorizontal.p3d"; 
        scope = 2; 
        picture = "pictureStaticObject"; 
		editorPreview = QPATHTOF(data\1_usd.paa); 	
		editorCategory = "EdCat_Equipment";
		editorSubcategory = "EdSubcat_InventoryItems";
		vehicleClass = "Items";	
		scopeCurator = 2;		
		class TransportItems {
			item_xx(GVAR(stack),1);
		};
	};
	
	class ReammoBox_F;
	class GVAR(stack_small): ReammoBox_F {
		author = "=BTC=Fyuran";  
		mapSize = 0.78;
        displayName = "Money Stacks (Small)";
		maximumLoad = 0.03;	
		transportMaxMagazines = 0;
		transportMaxWeapons = 10;
		transportMaxBackpacks = 0;
		supplyRadius = -1;
        model = QPATHTOF(data\money_stack_small.p3d);   
		picture = "pictureStaticObject";
		icon = "iconObject_1x1";
        scope = 2;
		scopeCurator = 2; 
		class TransportItems {
			item_xx(GVAR(stack),3);
		};
	};
	class GVAR(stack_medium): GVAR(stack_small) {
        displayName = "Money Stacks (Medium)";
		maximumLoad = 0.10;	
		model = QPATHTOF(data\money_stack_medium.p3d);  
		class TransportItems {
			item_xx(GVAR(stack),10);
		};		
	};
	class GVAR(stack_large): GVAR(stack_small) {
        displayName = "Money Stacks (Large)";
		model = QPATHTOF(data\money_stack_large.p3d);
		maximumLoad = 1.00;			
		class TransportItems {
			item_xx(GVAR(stack),100);
		};				
	};
	class GVAR(pallet): GVAR(stack_small) {
        displayName = "Money Pallet";
		model = QPATHTOF(data\money_pallet.p3d);
		maximumLoad = 10.01;
		class TransportItems {
			item_xx(GVAR(stack),1000);
		};		
	};
	class ThingX;
	class GVAR(pallet_empty): ThingX {
		author = "=BTC=Fyuran"; 
		picture = "pictureStaticObject";
		icon = "iconObject_1x1";
        scope = 2;
		scopeCurator = 2;		
		mapSize = 0.78;
        displayName = "Money Pallet (Empty)";
		model = QPATHTOF(data\money_pallet_empty.p3d);
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
