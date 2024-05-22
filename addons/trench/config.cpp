#include "basicdefines_A3.hpp"
class CfgPatches{
	class btc_campaign_objects{
		name = "=BTC= Trench objects";
		author = "=BTC=Fyuran";
		url = "http://www.blacktemplars.altervista.org";
		requiredAddons[] = {"A3_Structures_F"};
		requiredVersion = 0.1;
	units[] ={"trench_straight_1m","trench_straight_short","trench_tJunction_1m","trench_tJunction_short","trench_tJunctionRampUp_short","trench_LJunction_right_1m","trench_LJunction_left_1m","trench_LJunction_right_short","trench_LJunction_left_short","trench_curve_right","trench_curve_left","trench_cross_1m","trench_cross_short","trench_crossRampUp","trench_rampUp_1m","trench_cap","trench_cap_closed","trench_cap_round","trench_cap_square"};
		weapons[] = {};
	};
};

class CfgVehicles{
	class Strategic;
	
	//STRAIGHT
	class trench_straight_1m: Strategic{
		author = "=BTC= Fyuran";
		scope = 2;
		editorPreview = "z\btc_trench\data\editorPreview\straight_long.jpg";
		icon = "iconObject_1x1"; 
		scopeCurator = 2;
		displayName = "Trench Straight (Long)"; 
		model = z\btc_trench\data\trench_straight_1m.p3d; // filepath
		hiddenSelections[] = {}; //we want to allow changing the texture of this selection
		hiddenSelectionsTextures[] = {}; // The textures for the selections defined above. If empty, no texture is used.
		hiddenSelectionsMaterials[] = {};
		//vehicleClass = btc_campaign_vehicleClass; // Object in the in-game editor
		mapSize = 1; 
		cost = 100;
	};
 	class trench_straight_short: trench_straight_1m{
		displayName = "Trench Straight (Short)"; 
		model = z\btc_trench\data\trench_straight_short.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\straight_short.jpg";
	};
	//T-JUNCTION
	class trench_tJunction_1m: trench_straight_1m{
		displayName = "Trench T-Junction (Long)"; 
		model = z\btc_trench\data\trench_tJunction_1m.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\TJunction_long.jpg";
	};
	class trench_tJunction_short: trench_straight_1m{
		displayName = "Trench T-Junction (Short)"; 
		model = z\btc_trench\data\trench_tJunction_short.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\TJunction_short.jpg";
	};
	class trench_tJunctionRampUp_short: trench_straight_1m{
		displayName = "Trench T-Junction Ramp (Short)"; 
		model = z\btc_trench\data\trench_TJunctionRampUP_short.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\TJunctionrampUP_short.jpg";
	};
	//L-JUNCTION
	class trench_LJunction_right_1m: trench_straight_1m{
		displayName = "Trench Right L-Curve (Long)"; 
		model = z\btc_trench\data\trench_LJunction_right_1m.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\LJunction_right_long.jpg";
	};
	class trench_LJunction_left_1m: trench_straight_1m{
		displayName = "Trench Left L-Curve (Long)"; 
		model = z\btc_trench\data\trench_LJunction_left_1m.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\LJunction_right_long.jpg";
	};
	class trench_LJunction_right_short: trench_straight_1m{
		displayName = "Trench Right L-Curve (Short)"; 
		model = z\btc_trench\data\trench_LJunction_right_short.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\LJunction_right_short.jpg";
	};
	class trench_LJunction_left_short: trench_straight_1m{
		displayName = "Trench Left L-Curve (Short)"; 
		model = z\btc_trench\data\trench_LJunction_left_short.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\LJunction_left_short.jpg";
	};
	//CURVE
	class trench_curve_right: trench_straight_1m{
		displayName = "Trench Right Curve"; 
		model = z\btc_trench\data\trench_curve_right.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\Curve_right.jpg";
	};
	class trench_curve_left: trench_straight_1m{
		displayName = "Trench Left Curve"; 
		model = z\btc_trench\data\trench_curve_left.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\Curve_left.jpg";
	};
	//CROSS
	class trench_cross_1m: trench_straight_1m{
		displayName = "Trench Crossroads (Long)"; 
		model = z\btc_trench\data\trench_cross_1m.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\Cross_long.jpg";
	};
	class trench_cross_short: trench_straight_1m{
		displayName = "Trench Crossroads (Short)"; 
		model = z\btc_trench\data\trench_cross_short.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\Cross_short.jpg";
	};
	class trench_crossRampUp: trench_straight_1m{
		displayName = "Trench Crossroads Ramp (Short)"; 
		model = z\btc_trench\data\trench_crossRampUp_short.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\CrossrampUP.jpg";
	};
	//RAMP
	class trench_rampUp_1m: trench_straight_1m{
		displayName = "Trench Ramp (Short)"; 
		model = z\btc_trench\data\trench_rampUp.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\rampUP.jpg";
	};
	//CAP
	class trench_cap: trench_straight_1m{
		displayName = "Trench Start"; 
		model = z\btc_trench\data\trench_cap.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\Cap.jpg";
	};
	class trench_cap_closed: trench_straight_1m{
		displayName = "Trench Cap-Closed (Small)"; 
		model = z\btc_trench\data\trench_cap_closed.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\Cap_closed.jpg";
	};
	class trench_cap_round: trench_straight_1m{
		displayName = "Trench Cap-Round (Small)"; 
		model = z\btc_trench\data\trench_cap_round.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\Cap_round.jpg";
	};
	class trench_cap_square: trench_straight_1m{
		displayName = "Trench Cap-Squared (Small)"; 
		model = z\btc_trench\data\trench_cap_square.p3d;
		editorPreview = "z\btc_trench\data\editorPreview\Cap_square.jpg";
	};
};