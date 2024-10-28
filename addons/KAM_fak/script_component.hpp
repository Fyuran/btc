#define MAINPREFIX z
#define PREFIX btc
#define COMPONENT KAM_fak

#include "\x\cba\addons\main\script_macros_common.hpp"

// BEGIN ACE3 reference macros

#define ACE_PREFIX ace

#define ACE_ADDON(component)        DOUBLES(ACE_PREFIX,component)

#define ACEGVAR(module,var)         TRIPLES(ACE_PREFIX,module,var)
#define QACEGVAR(module,var)        QUOTE(ACEGVAR(module,var))
#define QQACEGVAR(module,var)       QUOTE(QACEGVAR(module,var))

#define ACEFUNC(module,function)    TRIPLES(DOUBLES(ACE_PREFIX,module),fnc,function)
#define QACEFUNC(module,function)   QUOTE(ACEFUNC(module,function))

#define ACELSTRING(module,string)   QUOTE(TRIPLES(STR,DOUBLES(ACE_PREFIX,module),string))
#define ACELLSTRING(module,string)  localize ACELSTRING(module,string)
#define ACECSTRING(module,string)   QUOTE(TRIPLES($STR,DOUBLES(ACE_PREFIX,module),string))

#define ACEPATHTOF(component,path) \z\ace\addons\component\path
#define QACEPATHTOF(component,path) QUOTE(ACEPATHTOF(component,path))

// BEGIN KAT reference macros

#define KAT_PREFIX kat

#define KATGVAR(module,var) TRIPLES(KAT_PREFIX,module,var)
#define KATQGVAR(module,var) QUOTE(KATGVAR(module,var))
#define KATQQGVAR(module,var) QUOTE(KATQGVAR(module,var))

#define KATFUNC(module,function) TRIPLES(DOUBLES(KAT_PREFIX,module),fnc,function)
#define KATQFUNC(module,function) QUOTE(KATFUNC(module,function))

#define KATLSTRING(module,string) QUOTE(TRIPLES(STR,DOUBLES(KAT_PREFIX,module),string))
#define KATLLSTRING(module,string) localize KATLSTRING(module,string)
#define KATCSTRING(module,string) QUOTE(TRIPLES($STR,DOUBLES(KAT_PREFIX,module),string))

#define KATPATHTOF(component,path) \x\KAM\addons\component\path
#define KATQPATHTOF(component,path) QUOTE(KATPATHTOF(component,path))

#ifdef DISABLE_COMPILE_CACHE
    #undef PREP
    #define PREP(fncName) DFUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fnc,fncName).sqf)
#else
    #undef PREP
    #define PREP(fncName) [QPATHTOF(functions\DOUBLES(fnc,fncName).sqf), QFUNC(fncName)] call SLX_XEH_COMPILE_NEW
#endif