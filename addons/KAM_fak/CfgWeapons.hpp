class CfgWeapons {
    class kat_IFAK;
    class CBA_MiscItem_ItemInfo;

    class kat_btc_FAK_M1: kat_IFAK {
        author = "=BTC= Fyuran";
        displayName = "M1 FAK";
        editorPreview = QPATHTOF(data\m1_fak.paa);
        picture = QPATHTOF(data\m1_fak.paa);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 50;
        };
    };
    class kat_btc_FAK_M2: kat_btc_FAK_M1 {
        displayName = "M2 FAK";
        editorPreview = QPATHTOF(data\m2_fak.paa);
        picture = QPATHTOF(data\m2_fak.paa);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 286;
        };
    };
};