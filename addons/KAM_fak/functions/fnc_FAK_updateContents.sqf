#include "..\script_component.hpp"
/*
 * Author: Blue
 * Update contents of FAKs
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call kat_misc_fnc_FAK_updateContents;
 *
 * Public: No
 */

// IFAK
missionNamespace setVariable [KATQGVAR(misc,IFAKContents),
[(missionNamespace getVariable [KATQGVAR(misc,IFAKFirstSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,IFAKSecondSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,IFAKThirdSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,IFAKFourthSlotItem), []])]];

// AFAK
missionNamespace setVariable [KATQGVAR(misc,AFAKContents),
[(missionNamespace getVariable [KATQGVAR(misc,AFAKFirstSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,AFAKSecondSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,AFAKThirdSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,AFAKFourthSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,AFAKFifthSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,AFAKSixthSlotItem), []])]];

// M1
missionNamespace setVariable [KATQGVAR(misc,M1Contents),
[(missionNamespace getVariable [KATQGVAR(misc,M1FirstSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,M1SecondSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,M1ThirdSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,M1FourthSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,M1FifthSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,M1SixthSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,M1SeventhSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,M1EighthSlotItem), []])]];

// M2
missionNamespace setVariable [KATQGVAR(misc,M2Contents),
[(missionNamespace getVariable [KATQGVAR(misc,M2FirstSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,M2SecondSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,M2ThirdSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,M2FourthSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,M2FifthSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,M2SixthSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,M2SeventhSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,M2EighthSlotItem), []])]];

// MFAK
missionNamespace setVariable [KATQGVAR(misc,MFAKContents),
[(missionNamespace getVariable [KATQGVAR(misc,MFAKFirstSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,MFAKSecondSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,MFAKThirdSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,MFAKFourthSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,MFAKFifthSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,MFAKSixthSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,MFAKSeventhSlotItem), []]),
(missionNamespace getVariable [KATQGVAR(misc,MFAKEighthSlotItem), []])]];

// Get Slot Names (didn't wanna create a new file for this)
missionNamespace setVariable [KATQGVAR(misc,FAKSlotNames),
[(KATLLSTRING(misc,FAK_Slot_1_Hint)),
(KATLLSTRING(misc,FAK_Slot_2_Hint)),
(KATLLSTRING(misc,FAK_Slot_3_Hint)),
(KATLLSTRING(misc,FAK_Slot_4_Hint)),
(KATLLSTRING(misc,FAK_Slot_5_Hint)),
(KATLLSTRING(misc,FAK_Slot_6_Hint)),
(KATLLSTRING(misc,FAK_Slot_7_Hint)),
(KATLLSTRING(misc,FAK_Slot_8_Hint))]];

