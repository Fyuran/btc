////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 9.10
//https://mikero.bytex.digital/Downloads
//'now' is Wed May 17 17:31:36 2023 : 'file' last modified on Fri Feb 21 20:52:07 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class btc_tfar_vest_radios
	{
		name = "=BTC= VSM TFAR VEST RADIOS";
		author = "=BTC=Fyuran";
		url = "http://www.blacktemplars.altervista.org";
		requiredVersion = 1.88;
		weapons[] = {"VSM_CarrierRig_RTO_ProjectHonor","VSM_FAPC_RTO_ProjectHonor","VSM_CarrierRig_RTO_OGA_OD","VSM_FAPC_RTO_OGA","VSM_FAPC_RTO_OGA_OD","VSM_CarrierRig_RTO_OGA","VSM_CarrierRig_RTO_OCP","VSM_FAPC_RTO_OCP","VSM_CarrierRig_RTO_multicamTropic","VSM_FAPC_RTO_MulticamTropic","VSM_CarrierRig_RTO_Multicam","VSM_FAPC_RTO_Multicam","VSM_CarrierRig_RTO_M81","VSM_FAPC_RTO_M81","VSM_CarrierRig_RTO_AOR1","VSM_FAPC_RTO_AOR1","V_PlateCarrier1_RTO_rgr","V_PlateCarrier1_RTO_blk","V_PlateCarrier2_RTO_rgr","V_PlateCarrier2_RTO_blk","V_PlateCarrier3_RTO_rgr","V_PlateCarrierGL_RTO_rgr","V_PlateCarrierGL_RTO_blk","V_PlateCarrierGL_RTO_mtp","V_PlateCarrierSpec_RTO_rgr","V_PlateCarrierSpec_RTO_blk","V_PlateCarrierSpec_RTO_mtp"};
		units[] = {};
		requiredAddons[] = {"A3_Weapons_F_Vests","task_force_radio","VSM_Vests_Config"};
	};
};
class CfgFunctions
{
	class TFAR
	{
		class Radio
		{
			class lrRadiosList
			{
				file = "\z\btc\addons\tfar_vest_radios\functions\fnc_lrRadiosList.sqf";
			};
			class vestLr
			{
				file = "\z\btc\addons\tfar_vest_radios\functions\fnc_vestLr.sqf";
			};
			class processRespawn
			{
				file = "\z\btc\addons\tfar_vest_radios\functions\fnc_processRespawn.sqf";
			};
		};
	};
};
class CfgWeapons
{
	class VSM_CarrierRig_Operator_ProjectHonor;
	class VSM_CarrierRig_RTO_ProjectHonor: VSM_CarrierRig_Operator_ProjectHonor
	{
		displayName = "[VSM] ProjectHonor LBT Armatus (RTO)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class VSM_FAPC_Operator_ProjectHonor;
	class VSM_FAPC_RTO_ProjectHonor: VSM_FAPC_Operator_ProjectHonor
	{
		displayName = "[VSM] ProjectHonor DT FAPC (RTO)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class VSM_CarrierRig_Operator_OGA_OD;
	class VSM_CarrierRig_RTO_OGA_OD: VSM_CarrierRig_Operator_OGA_OD
	{
		displayName = "[VSM] OGA OD LBT Armatus (RTO)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class VSM_FAPC_Operator_OGA;
	class VSM_FAPC_RTO_OGA: VSM_FAPC_Operator_OGA
	{
		displayName = "[VSM] OGA DT FAPC (RTO)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class VSM_FAPC_Operator_OGA_OD;
	class VSM_FAPC_RTO_OGA_OD: VSM_FAPC_Operator_OGA_OD
	{
		displayName = "[VSM] OGA OD DT FAPC (RTO)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class VSM_CarrierRig_Operator_OGA;
	class VSM_CarrierRig_RTO_OGA: VSM_CarrierRig_Operator_OGA
	{
		displayName = "[VSM] OGA LBT Armatus (RTO)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class VSM_CarrierRig_Operator_OCP;
	class VSM_CarrierRig_RTO_OCP: VSM_CarrierRig_Operator_OCP
	{
		displayName = "[VSM] OCP LBT Armatus (RTO)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class VSM_FAPC_Operator_OCP;
	class VSM_FAPC_RTO_OCP: VSM_FAPC_Operator_OCP
	{
		displayName = "[VSM] OCP DT FAPC (RTO)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class VSM_CarrierRig_Operator_multicamTropic;
	class VSM_CarrierRig_RTO_multicamTropic: VSM_CarrierRig_Operator_multicamTropic
	{
		displayName = "[VSM] MulticamTropic LBT Armatus (RTO)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class VSM_FAPC_Operator_MulticamTropic;
	class VSM_FAPC_RTO_MulticamTropic: VSM_FAPC_Operator_MulticamTropic
	{
		displayName = "[VSM] MulticamTropic DT FAPC (RTO)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class VSM_CarrierRig_Operator_Multicam;
	class VSM_CarrierRig_RTO_Multicam: VSM_CarrierRig_Operator_Multicam
	{
		displayName = "[VSM] Multicam LBT Armatus (RTO)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class VSM_FAPC_Operator_Multicam;
	class VSM_FAPC_RTO_Multicam: VSM_FAPC_Operator_Multicam
	{
		displayName = "[VSM] Multicam DT FAPC (RTO)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class VSM_CarrierRig_Operator_M81;
	class VSM_CarrierRig_RTO_M81: VSM_CarrierRig_Operator_M81
	{
		displayName = "[VSM] M81 LBT Armatus (RTO)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class VSM_FAPC_Operator_M81;
	class VSM_FAPC_RTO_M81: VSM_FAPC_Operator_M81
	{
		displayName = "[VSM] M81 DT FAPC (RTO)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class VSM_CarrierRig_Operator_AOR1;
	class VSM_CarrierRig_RTO_AOR1: VSM_CarrierRig_Operator_AOR1
	{
		displayName = "[VSM] AOR1 LBT Armatus (RTO)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class VSM_FAPC_Operator_AOR1;
	class VSM_FAPC_RTO_AOR1: VSM_FAPC_Operator_AOR1
	{
		displayName = "[VSM] AOR1 DT FAPC (RTO)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class V_PlateCarrier1_rgr;
	class V_PlateCarrier1_RTO_rgr: V_PlateCarrier1_rgr
	{
		displayName = "Carrier Lite RTO (Green)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class V_PlateCarrier1_blk;
	class V_PlateCarrier1_RTO_blk: V_PlateCarrier1_blk
	{
		displayName = "Carrier Lite RTO (Black)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class V_PlateCarrier2_rgr;
	class V_PlateCarrier2_RTO_rgr: V_PlateCarrier2_rgr
	{
		displayName = "Carrier Rig RTO (Green)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class V_PlateCarrier2_blk;
	class V_PlateCarrier2_RTO_blk: V_PlateCarrier2_blk
	{
		displayName = "Carrier Rig RTO (Black)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class V_PlateCarrier3_rgr;
	class V_PlateCarrier3_RTO_rgr: V_PlateCarrier3_rgr
	{
		displayName = "Carrier Rig RTO (Green)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class V_PlateCarrierGL_rgr;
	class V_PlateCarrierGL_RTO_rgr: V_PlateCarrierGL_rgr
	{
		displayName = "Carrier GL Rig RTO (Green)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class V_PlateCarrierGL_blk;
	class V_PlateCarrierGL_RTO_blk: V_PlateCarrierGL_blk
	{
		displayName = "Carrier GL Rig RTO (Black)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class V_PlateCarrierGL_mtp;
	class V_PlateCarrierGL_RTO_mtp: V_PlateCarrierGL_mtp
	{
		displayName = "Carrier GL Rig RTO (MTP)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class V_PlateCarrierSpec_rgr;
	class V_PlateCarrierSpec_RTO_rgr: V_PlateCarrierSpec_rgr
	{
		displayName = "Carrier Special Rig RTO (Green)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class V_PlateCarrierSpec_blk;
	class V_PlateCarrierSpec_RTO_blk: V_PlateCarrierSpec_blk
	{
		displayName = "Carrier Special Rig RTO (Black)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
	class V_PlateCarrierSpec_mtp;
	class V_PlateCarrierSpec_RTO_mtp: V_PlateCarrierSpec_mtp
	{
		displayName = "Carrier Special Rig RTO (MTP)";
		author = "Black Templars Clan";
		tf_hasLRradio = 1;
	};
};
class Extended_PreStart_EventHandlers
{
	class btc_tfar_vest_radios
	{
		init = "call compile preprocessFileLineNumbers '\z\btc\addons\tfar_vest_radios\XEH_preStart.sqf'";
	};
};
class Extended_PreInit_EventHandlers
{
	class btc_tfar_vest_radios
	{
		init = "call compile preprocessFileLineNumbers '\z\btc\addons\tfar_vest_radios\XEH_preInit.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class btc_tfar_vest_radios
	{
		init = "call compile preprocessFileLineNumbers '\z\btc\addons\tfar_vest_radios\XEH_postInit.sqf'";
	};
};
