class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_Actions {
            class ACE_MainActions {

            class kat_btc_FAK_M1_Item {
                displayName = CSTRING(M1_Unpack);
                condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,0)] call KATFUNC(misc,FAK_checkSlot) && !([_target] call ACEFUNC(common,isAwake)));
                statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,0)] call KATFUNC(misc,FAK_unpack));
                exceptions[] = {"isNotSwimming", "isNotInside", "notOnMap", "isNotSitting"};
                showDisabled = 0;
                icon = QPATHTOF(data\m1_fak.paa);

                class Slot1 {
                    displayName = KATCSTRING(misc,FAK_Slot_1);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,1)] call KATFUNC(misc,FAK_checkSlot));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,1)] call KATFUNC(misc,FAK_unpack));
                    showDisabled = 0;
                    icon = QPATHTOF(data\m1_fak.paa);
                };

                class Slot2: Slot1 {
                    displayName = KATCSTRING(misc,FAK_Slot_2);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,2)] call KATFUNC(misc,FAK_checkSlot));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,2)] call KATFUNC(misc,FAK_unpack));
                };

                class Slot3: Slot1 {
                    displayName = KATCSTRING(misc,FAK_Slot_3);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,3)] call KATFUNC(misc,FAK_checkSlot));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,3)] call KATFUNC(misc,FAK_unpack));
                };

                class Slot4: Slot1 {
                    displayName = KATCSTRING(misc,FAK_Slot_4);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,4)] call KATFUNC(misc,FAK_checkSlot));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,4)] call KATFUNC(misc,FAK_unpack));
                };

                class Slot5: Slot1 {
                    displayName = KATCSTRING(misc,FAK_Slot_5);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,5)] call KATFUNC(misc,FAK_checkSlot));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,5)] call KATFUNC(misc,FAK_unpack));
                };

                class Slot6: Slot1 {
                    displayName = KATCSTRING(misc,FAK_Slot_6);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,6)] call KATFUNC(misc,FAK_checkSlot));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,6)] call KATFUNC(misc,FAK_unpack));
                };

                class Slot7: Slot1 {
                    displayName = KATCSTRING(misc,FAK_Slot_7);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,7)] call KATFUNC(misc,FAK_checkSlot));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,7)] call KATFUNC(misc,FAK_unpack));
                };

                class Slot8: Slot1 {
                    displayName = KATCSTRING(misc,FAK_Slot_8);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,8)] call KATFUNC(misc,FAK_checkSlot));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1',3,8)] call KATFUNC(misc,FAK_unpack));
                };
            };

            class kat_btc_FAK_M1_Magazine {
                displayName = CSTRING(M2_Unpack);
                condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,0)] call KATFUNC(misc,FAK_checkSlot) && !([_target] call ACEFUNC(common,isAwake)));
                statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,0)] call KATFUNC(misc,FAK_unpack));
                exceptions[] = {"isNotSwimming", "isNotInside", "notOnMap", "isNotSitting"};
                showDisabled = 0;
                icon = QPATHTOF(data\m1_fak.paa);

                class Slot1 {
                    displayName = KATCSTRING(misc,FAK_Slot_1);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,1)] call KATFUNC(misc,FAK_checkSlot));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,1)] call KATFUNC(misc,FAK_unpack));
                    showDisabled = 0;
                    icon = QPATHTOF(data\m1_fak.paa);
                };

                class Slot2: Slot1 {
                    displayName = KATCSTRING(misc,FAK_Slot_2);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,2)] call KATFUNC(misc,FAK_checkSlot));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,2)] call KATFUNC(misc,FAK_unpack));
                };

                class Slot3: Slot1 {
                    displayName = KATCSTRING(misc,FAK_Slot_3);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,3)] call KATFUNC(misc,FAK_checkSlot));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,3)] call KATFUNC(misc,FAK_unpack));
                };

                class Slot4: Slot1 {
                    displayName = KATCSTRING(misc,FAK_Slot_4);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,4)] call KATFUNC(misc,FAK_checkSlot));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,4)] call KATFUNC(misc,FAK_unpack));
                };

                class Slot5: Slot1 {
                    displayName = KATCSTRING(misc,FAK_Slot_5);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,5)] call KATFUNC(misc,FAK_checkSlot));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,5)] call KATFUNC(misc,FAK_unpack));
                };

                class Slot6: Slot1 {
                    displayName = KATCSTRING(misc,FAK_Slot_6);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,6)] call KATFUNC(misc,FAK_checkSlot));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,6)] call KATFUNC(misc,FAK_unpack));
                };

                class Slot7: Slot1 {
                    displayName = KATCSTRING(misc,FAK_Slot_7);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,7)] call KATFUNC(misc,FAK_checkSlot));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,7)] call KATFUNC(misc,FAK_unpack));
                };

                class Slot8: Slot1 {
                    displayName = KATCSTRING(misc,FAK_Slot_8);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,8)] call KATFUNC(misc,FAK_checkSlot));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M1_Magazine',3,8)] call KATFUNC(misc,FAK_unpack));
                };
            };

            class kat_btc_FAK_M2_Item {
                    displayName = CSTRING(M2_Unpack);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,0)] call KATFUNC(misc,FAK_checkSlot) && !([_target] call ACEFUNC(common,isAwake)));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,0)] call KATFUNC(misc,FAK_unpack));
                    exceptions[] = {"isNotSwimming", "isNotInside", "notOnMap", "isNotSitting"};
                    showDisabled = 0;
                    icon = QPATHTOF(data\m1_fak.paa);

                    class Slot1 {
                        displayName = KATCSTRING(misc,FAK_Slot_1);
                        condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,1)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,1)] call KATFUNC(misc,FAK_unpack));
                        showDisabled = 0;
                        icon = QPATHTOF(data\m1_fak.paa);
                    };

                    class Slot2: Slot1 {
                        displayName = KATCSTRING(misc,FAK_Slot_2);
                        condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,2)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,2)] call KATFUNC(misc,FAK_unpack));
                    };

                    class Slot3: Slot1 {
                        displayName = KATCSTRING(misc,FAK_Slot_3);
                        condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,3)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,3)] call KATFUNC(misc,FAK_unpack));
                    };

                    class Slot4: Slot1 {
                        displayName = KATCSTRING(misc,FAK_Slot_4);
                        condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,4)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,4)] call KATFUNC(misc,FAK_unpack));
                    };

                    class Slot5: Slot1 {
                        displayName = KATCSTRING(misc,FAK_Slot_5);
                        condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,5)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,5)] call KATFUNC(misc,FAK_unpack));
                    };

                    class Slot6: Slot1 {
                        displayName = KATCSTRING(misc,FAK_Slot_6);
                        condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,6)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,6)] call KATFUNC(misc,FAK_unpack));
                    };

                    class Slot7: Slot1 {
                        displayName = KATCSTRING(misc,FAK_Slot_7);
                        condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,7)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,7)] call KATFUNC(misc,FAK_unpack));
                    };

                    class Slot8: Slot1 {
                        displayName = KATCSTRING(misc,FAK_Slot_8);
                        condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,8)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2',4,8)] call KATFUNC(misc,FAK_unpack));
                    };
                };

                class kat_btc_FAK_M2_Magazine {
                    displayName = CSTRING(M2_Unpack);
                    condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,0)] call KATFUNC(misc,FAK_checkSlot) && !([_target] call ACEFUNC(common,isAwake)));
                    statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,0)] call KATFUNC(misc,FAK_unpack));
                    exceptions[] = {"isNotSwimming", "isNotInside", "notOnMap", "isNotSitting"};
                    showDisabled = 0;
                    icon = QPATHTOF(data\m2_fak.paa);

                    class Slot1 {
                        displayName = KATCSTRING(misc,FAK_Slot_1);
                        condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,1)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,1)] call KATFUNC(misc,FAK_unpack));
                        showDisabled = 0;
                        icon = QPATHTOF(data\m2_fak.paa);
                    };

                    class Slot2: Slot1 {
                        displayName = KATCSTRING(misc,FAK_Slot_2);
                        condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,2)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,2)] call KATFUNC(misc,FAK_unpack));
                    };

                    class Slot3: Slot1 {
                        displayName = KATCSTRING(misc,FAK_Slot_3);
                        condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,3)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,3)] call KATFUNC(misc,FAK_unpack));
                    };

                    class Slot4: Slot1 {
                        displayName = KATCSTRING(misc,FAK_Slot_4);
                        condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,4)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,4)] call KATFUNC(misc,FAK_unpack));
                    };

                    class Slot5: Slot1 {
                        displayName = KATCSTRING(misc,FAK_Slot_5);
                        condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,5)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,5)] call KATFUNC(misc,FAK_unpack));
                    };

                    class Slot6: Slot1 {
                        displayName = KATCSTRING(misc,FAK_Slot_6);
                        condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,6)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,6)] call KATFUNC(misc,FAK_unpack));
                    };

                    class Slot7: Slot1 {
                        displayName = KATCSTRING(misc,FAK_Slot_7);
                        condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,7)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,7)] call KATFUNC(misc,FAK_unpack));
                    };

                    class Slot8: Slot1 {
                        displayName = KATCSTRING(misc,FAK_Slot_8);
                        condition = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,8)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_target,'kat_btc_FAK_M2_Magazine',4,8)] call KATFUNC(misc,FAK_unpack));
                    };
                };
            }; 
            /*-----------------------------------------------------------------------------------------------------SELF ACTIONS HERE*/
            /*-----------------------------------------------------------------------------------------------------SELF ACTIONS HERE*/
            /*-----------------------------------------------------------------------------------------------------SELF ACTIONS HERE*/
            class ACE_SelfActions {
                class KAT_Equipment {
                    class kat_btc_FAK_M1_Magazine {
                        displayName = CSTRING(M1_Unpack);
                        condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,0)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,0)] call KATFUNC(misc,FAK_unpack));
                        exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
                        showDisabled = 0;
                        icon = QPATHTOF(data\m1_fak.paa);

                        class IFAKInfo {
                            displayName = KATCSTRING(misc,FAK_DisplayItems);
                            condition = QUOTE([ARR_2(_player,'kat_btc_FAK_M1_Magazine')] call ACEFUNC(common,hasMagazine));
                            statement = QUOTE([ARR_2(_player,0)] call KATFUNC(misc,FAK_displayContent));
                            exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
                            showDisabled = 0;
                            icon = KATQPATHTOF(misc,ui\IFAK_DisplayItems.paa);
                        };
                        
                        class Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_1);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,1)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,1)] call KATFUNC(misc,FAK_unpack));
                            exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
                            showDisabled = 0;
                            icon = QPATHTOF(data\m1_fak.paa);
                        };

                        class Slot1_Repack {
                            displayName = KATCSTRING(misc,FAK_Slot_1_Repack);
                            condition = QUOTE(!([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,1)] call KATFUNC(misc,FAK_checkSlot)) && [ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,1)] call KATFUNC(misc,FAK_checkRepack));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,1)] call KATFUNC(misc,FAK_repack));
                            exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
                            showDisabled = 0;
                            icon = KATQPATHTOF(misc,ui\IFAK_Repack.paa);
                        };

                        class Slot2: Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_2);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,2)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,2)] call KATFUNC(misc,FAK_unpack));
                        };

                        class Slot2_Repack: Slot1_Repack {
                            displayName = KATCSTRING(misc,FAK_Slot_2_Repack);
                            condition = QUOTE(!([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,2)] call KATFUNC(misc,FAK_checkSlot)) && [ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,2)] call KATFUNC(misc,FAK_checkRepack));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,2)] call KATFUNC(misc,FAK_repack));
                        };

                        class Slot3: Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_3);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,3)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,3)] call KATFUNC(misc,FAK_unpack));
                        };

                        class Slot3_Repack: Slot1_Repack {
                            displayName = KATCSTRING(misc,FAK_Slot_3_Repack);
                            condition = QUOTE(!([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,3)] call KATFUNC(misc,FAK_checkSlot)) && [ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,3)] call KATFUNC(misc,FAK_checkRepack));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,3)] call KATFUNC(misc,FAK_repack));
                        };

                        class Slot4: Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_4);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,4)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,4)] call KATFUNC(misc,FAK_unpack));
                        };

                        class Slot4_Repack: Slot1_Repack {
                            displayName = KATCSTRING(misc,FAK_Slot_4_Repack);
                            condition = QUOTE(!([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,4)] call KATFUNC(misc,FAK_checkSlot)) && [ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,4)] call KATFUNC(misc,FAK_checkRepack));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M1_Magazine',3,4)] call KATFUNC(misc,FAK_repack));
                        };
                    };

                    class kat_btc_FAK_M1_Item {
                        displayName = CSTRING(M1_Unpack);
                        condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M1',3,0)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M1',3,0)] call KATFUNC(misc,FAK_unpack));
                        exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
                        showDisabled = 0;
                        icon = QPATHTOF(data\m1_fak.paa);

                        class AFAKInfo {
                            displayName = KATCSTRING(misc,FAK_DisplayItems);
                            condition = QUOTE([ARR_2(_player,'kat_btc_FAK_M1')] call ACEFUNC(common,hasItem));
                            statement = QUOTE([ARR_2(_player,1)] call KATFUNC(misc,FAK_displayContent));
                            exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
                            showDisabled = 0;
                            icon = KATQPATHTOF(misc,ui\AFAK_DisplayItems.paa);
                        };

                        class Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_1);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M1',3,1)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M1',3,1)] call KATFUNC(misc,FAK_unpack));
                            exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
                            showDisabled = 0;
                            icon = QPATHTOF(data\m1_fak.paa);
                        };

                        class Slot2: Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_2);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M1',3,2)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M1',3,2)] call KATFUNC(misc,FAK_unpack));
                        };

                        class Slot3: Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_3);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M1',3,3)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M1',3,3)] call KATFUNC(misc,FAK_unpack));
                        };

                        class Slot4: Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_4);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M1',3,4)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M1',3,4)] call KATFUNC(misc,FAK_unpack));
                        };

                        class Slot5: Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_5);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M1',3,5)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M1',3,5)] call KATFUNC(misc,FAK_unpack));
                        };

                        class Slot6: Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_6);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M1',3,6)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M1',3,6)] call KATFUNC(misc,FAK_unpack));
                        };
                    };

                    class kat_btc_FAK_M2_Magazine {
                        displayName = CSTRING(M2_Unpack);
                        condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,0)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,0)] call KATFUNC(misc,FAK_unpack));
                        exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
                        showDisabled = 0;
                        icon = QPATHTOF(data\M2_fak.paa);

                        class IFAKInfo {
                            displayName = KATCSTRING(misc,FAK_DisplayItems);
                            condition = QUOTE([ARR_2(_player,'kat_btc_FAK_M2_Magazine')] call ACEFUNC(common,hasMagazine));
                            statement = QUOTE([ARR_2(_player,0)] call KATFUNC(misc,FAK_displayContent));
                            exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
                            showDisabled = 0;
                            icon = KATQPATHTOF(misc,ui\IFAK_DisplayItems.paa);
                        };
                        
                        class Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_1);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,1)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,1)] call KATFUNC(misc,FAK_unpack));
                            exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
                            showDisabled = 0;
                            icon = QPATHTOF(data\M2_fak.paa);
                        };

                        class Slot1_Repack {
                            displayName = KATCSTRING(misc,FAK_Slot_1_Repack);
                            condition = QUOTE(!([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,1)] call KATFUNC(misc,FAK_checkSlot)) && [ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,1)] call KATFUNC(misc,FAK_checkRepack));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,1)] call KATFUNC(misc,FAK_repack));
                            exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
                            showDisabled = 0;
                            icon = KATQPATHTOF(misc,ui\IFAK_Repack.paa);
                        };

                        class Slot2: Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_2);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,2)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,2)] call KATFUNC(misc,FAK_unpack));
                        };

                        class Slot2_Repack: Slot1_Repack {
                            displayName = KATCSTRING(misc,FAK_Slot_2_Repack);
                            condition = QUOTE(!([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,2)] call KATFUNC(misc,FAK_checkSlot)) && [ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,2)] call KATFUNC(misc,FAK_checkRepack));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,2)] call KATFUNC(misc,FAK_repack));
                        };

                        class Slot3: Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_3);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,3)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,3)] call KATFUNC(misc,FAK_unpack));
                        };

                        class Slot3_Repack: Slot1_Repack {
                            displayName = KATCSTRING(misc,FAK_Slot_3_Repack);
                            condition = QUOTE(!([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,3)] call KATFUNC(misc,FAK_checkSlot)) && [ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,3)] call KATFUNC(misc,FAK_checkRepack));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,3)] call KATFUNC(misc,FAK_repack));
                        };

                        class Slot4: Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_4);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,4)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,4)] call KATFUNC(misc,FAK_unpack));
                        };

                        class Slot4_Repack: Slot1_Repack {
                            displayName = KATCSTRING(misc,FAK_Slot_4_Repack);
                            condition = QUOTE(!([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,4)] call KATFUNC(misc,FAK_checkSlot)) && [ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,4)] call KATFUNC(misc,FAK_checkRepack));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M2_Magazine',4,4)] call KATFUNC(misc,FAK_repack));
                        };
                    };

                    class kat_btc_FAK_M2_Item {
                        displayName = CSTRING(M2_Unpack);
                        condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M2',4,0)] call KATFUNC(misc,FAK_checkSlot));
                        statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M2',4,0)] call KATFUNC(misc,FAK_unpack));
                        exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
                        showDisabled = 0;
                        icon = QPATHTOF(data\m2_fak.paa);

                        class AFAKInfo {
                            displayName = KATCSTRING(misc,FAK_DisplayItems);
                            condition = QUOTE([ARR_2(_player,'kat_btc_FAK_M2')] call ACEFUNC(common,hasItem));
                            statement = QUOTE([ARR_2(_player,1)] call KATFUNC(misc,FAK_displayContent));
                            exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
                            showDisabled = 0;
                            icon = KATQPATHTOF(misc,ui\AFAK_DisplayItems.paa);
                        };

                        class Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_1);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M2',4,1)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M2',4,1)] call KATFUNC(misc,FAK_unpack));
                            exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting"};
                            showDisabled = 0;
                            icon = QPATHTOF(data\m2_fak.paa);
                        };

                        class Slot2: Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_2);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M2',4,2)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M2',4,2)] call KATFUNC(misc,FAK_unpack));
                        };

                        class Slot3: Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_3);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M2',4,3)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M2',4,3)] call KATFUNC(misc,FAK_unpack));
                        };

                        class Slot4: Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_4);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M2',4,4)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M2',4,4)] call KATFUNC(misc,FAK_unpack));
                        };

                        class Slot5: Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_5);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M2',4,5)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M2',4,5)] call KATFUNC(misc,FAK_unpack));
                        };

                        class Slot6: Slot1 {
                            displayName = KATCSTRING(misc,FAK_Slot_6);
                            condition = QUOTE([ARR_4(_player,'kat_btc_FAK_M2',4,6)] call KATFUNC(misc,FAK_checkSlot));
                            statement = QUOTE([ARR_4(_player,'kat_btc_FAK_M2',4,6)] call KATFUNC(misc,FAK_unpack));
                        };
                    };
                };
            };
        };
    };
};