#include "script_component.hpp"
#define CBA_SETTINGS_CAT "KAT - ADV Medical: Misc"

// Remove M1 when empty
[
    KATQGVAR(misc,M1_RemoveWhenEmpty),
    "CHECKBOX",
    KATLLSTRING(misc,SETTING_FAK_RemoveWhenEmpty),
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_M1)],
    [true],
    true
] call CBA_fnc_addSetting;

//M1 Container
[
    KATQGVAR(misc,M1_Container),
    "LIST",
    [KATLLSTRING(misc,SETTING_FAK_Container), KATLLSTRING(misc,SETTING_FAK_Container_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_M1)],
    [[0, 1, 2, 3], [KATLLSTRING(misc,SETTING_Container_Default), KATLLSTRING(misc,SETTING_Container_Uniform), KATLLSTRING(misc,SETTING_Container_Vest), KATLLSTRING(misc,SETTING_Container_Backpack)], 0],
    2
] call CBA_fnc_addSetting;

//M1 Slot Color
[
    KATQGVAR(misc,M1_Slot_Color),
    "COLOR",
    [KATLLSTRING(misc,SETTING_FAK_SlotColor), KATLLSTRING(misc,SETTING_FAK_SlotColor_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_M1)],
    [0.56, 0.93, 0.56],
    2
] call CBA_fnc_addSetting;

//M1 Item Color
[
    KATQGVAR(misc,M1_Item_Color),
    "COLOR",
    [KATLLSTRING(misc,SETTING_FAK_ItemColor), KATLLSTRING(misc,SETTING_FAK_ItemColor_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_M1)],
    [0.67, 0.84, 0.90],
    2
] call CBA_fnc_addSetting;

//M1 First Slot Item
//[['ACE_fieldDressing',6],['ACE_elasticBandage',6],['kat_chestSeal',1],['ACE_epinephrine',1],['kat_larynx',1],['ACE_tourniquet',4]]
[
    KATQGVAR(misc,M1FirstSlotItem),
    "EDITBOX",
    [KATLLSTRING(misc,SETTING_FirstSlot_Item), KATLLSTRING(misc,SETTING_ItemSlot_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_M1)],
    "[['ACE_fieldDressing',6],['ACE_elasticBandage',6]]",
    1,
    {
        private _string = missionNamespace getVariable [KATQGVAR(misc,M1FirstSlotItem), []];
        private _array = parseSimpleArray _string;
        missionNamespace setVariable [KATQGVAR(misc,M1FirstSlotItem), _array, true];
        call KATFUNC(misc,FAK_updateContents);
    }
] call CBA_Settings_fnc_init;

//M1 Second Slot Item
[
    KATQGVAR(misc,M1SecondSlotItem),
    "EDITBOX",
    [KATLLSTRING(misc,SETTING_SecondSlot_Item), KATLLSTRING(misc,SETTING_ItemSlot_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_M1)],
    "[['kat_chestSeal',1],['ACE_epinephrine',1],['kat_larynx',1],['ACE_tourniquet',4]]",
    1,
    {
        private _string = missionNamespace getVariable [KATQGVAR(misc,M1SecondSlotItem), []];
        private _array = parseSimpleArray _string;
        missionNamespace setVariable [KATQGVAR(misc,M1SecondSlotItem), _array, true];
        call KATFUNC(misc,FAK_updateContents);
    }
] call CBA_Settings_fnc_init;

//[['ACE_elasticBandage',40],['ACE_packingBandage',25],['ACE_quikclot',25],['kat_chestSeal',6],['ACE_epinephrine',8],['ACE_morphine',8],['kat_Pulseoximeter',6],['ACE_splint',6],['ACE_tourniquet',6],['kat_IV_16',10],['ACE_surgicalKit',1],['kat_IO_FAST',1],['kat_accuvac',1],['kat_larynx',1],['kat_etomidate',6],['kat_lidocaine',4],['kat_nitroglycerin',6],['kat_norepinephrine',6],['kat_stethoscope',1],['ACE_suture',4],['kat_EACA',6],['ACE_bloodIV',3],['ACE_bloodIV_500',4],['kat_BVM',1],['kat_naloxone',2],['ACE_salineIV_250',2],['kat_plate',2],['kat_clamp',1],['kat_coag_sense',1],['kat_vacuum',3],['kat_lorazepam',2],['kat_retractor',1],['kat_scalpel',1],['kat_AED',1],['ACE_bloodIV_250',3]]
// Remove M2 when empty
[
    KATQGVAR(misc,M2_RemoveWhenEmpty),
    "CHECKBOX",
    KATLLSTRING(misc,SETTING_FAK_RemoveWhenEmpty),
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_M2)],
    [true],
    true
] call CBA_fnc_addSetting;

//M2 Container
[
    KATQGVAR(misc,M2_Container),
    "LIST",
    [KATLLSTRING(misc,SETTING_FAK_Container), KATLLSTRING(misc,SETTING_FAK_Container_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_M2)],
    [[0, 1, 2, 3], [KATLLSTRING(misc,SETTING_Container_Default), KATLLSTRING(misc,SETTING_Container_Uniform), KATLLSTRING(misc,SETTING_Container_Vest), KATLLSTRING(misc,SETTING_Container_Backpack)], 0],
    2
] call CBA_fnc_addSetting;

//M2 Slot Color
[
    KATQGVAR(misc,M2_Slot_Color),
    "COLOR",
    [KATLLSTRING(misc,SETTING_FAK_SlotColor), KATLLSTRING(misc,SETTING_FAK_SlotColor_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_M2)],
    [0.56, 0.93, 0.56],
    2
] call CBA_fnc_addSetting;

//M2 Item Color
[
    KATQGVAR(misc,M2_Item_Color),
    "COLOR",
    [KATLLSTRING(misc,SETTING_FAK_ItemColor), KATLLSTRING(misc,SETTING_FAK_ItemColor_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_M2)],
    [0.67, 0.84, 0.90],
    2
] call CBA_fnc_addSetting;

//M2 First Slot Item
[
    KATQGVAR(misc,M2FirstSlotItem),
    "EDITBOX",
    [KATLLSTRING(misc,SETTING_FirstSlot_Item), KATLLSTRING(misc,SETTING_ItemSlot_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_M2)],
    "[['ACE_elasticBandage',40],['ACE_packingBandage',25],['ACE_quikclot',25],['kat_chestSeal',6],['ACE_epinephrine',8],['ACE_morphine',8]]",
    1,
    {
        private _string = missionNamespace getVariable [KATQGVAR(misc,M2FirstSlotItem), []];
        private _array = parseSimpleArray _string;
        missionNamespace setVariable [KATQGVAR(misc,M2FirstSlotItem), _array, true];
        call KATFUNC(misc,FAK_updateContents);
    }
] call CBA_Settings_fnc_init;

//M2 Second Slot Item
[
    KATQGVAR(misc,M2SecondSlotItem),
    "EDITBOX",
    [KATLLSTRING(misc,SETTING_SecondSlot_Item), KATLLSTRING(misc,SETTING_ItemSlot_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_M2)],
    "[['kat_Pulseoximeter',6],['ACE_splint',6],['ACE_tourniquet',6],['kat_IV_16',10],['ACE_surgicalKit',1],['kat_IO_FAST',1]]",
    1,
    {
        private _string = missionNamespace getVariable [KATQGVAR(misc,M2SecondSlotItem), []];
        private _array = parseSimpleArray _string;
        missionNamespace setVariable [KATQGVAR(misc,M2SecondSlotItem), _array, true];
        call KATFUNC(misc,FAK_updateContents);
    }
] call CBA_Settings_fnc_init;

//M2 Third Slot Item
[
    KATQGVAR(misc,M2ThirdSlotItem),
    "EDITBOX",
    [KATLLSTRING(misc,SETTING_ThirdSlot_Item), KATLLSTRING(misc,SETTING_ItemSlot_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_M2)],
    "[['kat_accuvac',1],['kat_larynx',1],['kat_etomidate',6],['kat_lidocaine',4],['kat_nitroglycerin',6],['kat_norepinephrine',6],['kat_stethoscope',1],['ACE_suture',4],['kat_EACA',6],['ACE_bloodIV',3]]",
    1,
    {
        private _string = missionNamespace getVariable [KATQGVAR(misc,M2ThirdSlotItem), []];
        private _array = parseSimpleArray _string;
        missionNamespace setVariable [KATQGVAR(misc,M2ThirdSlotItem), _array, true];
        call KATFUNC(misc,FAK_updateContents);
    }
] call CBA_Settings_fnc_init;

//M2 Fourth Item
[
    KATQGVAR(misc,M2FourthSlotItem),
    "EDITBOX",
    [KATLLSTRING(misc,SETTING_FourthSlot_Item), KATLLSTRING(misc,SETTING_ItemSlot_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_M2)],
    "[['ACE_bloodIV_500',4],['kat_BVM',1],['kat_naloxone',2],['ACE_salineIV_250',2],['kat_plate',2],['kat_clamp',1],['kat_coag_sense',1],['kat_vacuum',3],['kat_lorazepam',2],['kat_retractor',1],['kat_scalpel',1],['kat_AED',1],['ACE_bloodIV_250',3]]",
    1,
    {
        private _string = missionNamespace getVariable [KATQGVAR(misc,M2FourthSlotItem), []];
        private _array = parseSimpleArray _string;
        missionNamespace setVariable [KATQGVAR(misc,M2FourthSlotItem), _array, true];
        call KATFUNC(misc,FAK_updateContents);
    }
] call CBA_Settings_fnc_init;