#define MAINPREFIX z
#define PREFIX btc
#define COMPONENT weight_calculator
#include "\x\cba\addons\main\script_macros_common.hpp"
#ifdef DISABLE_COMPILE_CACHE
    #undef PREP
    #define PREP(fncName) DFUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fnc,fncName).sqf)
#else
    #undef PREP
    #define PREP(fncName) [QPATHTOF(functions\DOUBLES(fnc,fncName).sqf), QFUNC(fncName)] call SLX_XEH_COMPILE_NEW
#endif