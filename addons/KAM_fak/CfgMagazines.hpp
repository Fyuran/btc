class CfgMagazines {
    class CA_Magazine;

    class kat_btc_FAK_M1_Magazine: CA_Magazine {
        scope = 2;
        scopeArsenal = 0;
        author = "=BTC= Fyuran";
        displayName = KATCSTRING(misc,IFAK_Display);
        descriptionShort = KATCSTRING(misc,IFAK_DESC);
        picture = QPATHTOF(data\m1_fak.paa);
        
        ammo = "";
        count = 19;
        initSpeed = 0;
        tracersEvery = 0;
        lastRoundsTracer = 0;
        mass = 50;
    };

    class kat_btc_FAK_M2_Magazine: CA_Magazine {
        scope = 2;
        scopeArsenal = 0;
        author = "=BTC= Fyuran";
        displayName = KATCSTRING(misc,IFAK_Display);
        descriptionShort = KATCSTRING(misc,IFAK_DESC);
        picture = QPATHTOF(data\m2_fak.paa);
        
        ammo = "";
        count = 209;
        initSpeed = 0;
        tracersEvery = 0;
        lastRoundsTracer = 0;
        mass = 286;
    };
};