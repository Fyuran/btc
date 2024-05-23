cmake_minimum_required (VERSION 3.8)
cmake_policy(SET CMP0076 NEW) 

project ("btc_ArmaToJSON_x64"
           LANGUAGES CXX
)


add_library (btc_ArmaToJSON_x64 SHARED)
target_sources (btc_ArmaToJSON_x64 PUBLIC 
    "src/armaFileFunctions.cxx"
    "src/dllmain.cxx"
    "src/dllmain.def"
    "src/armaDataFunctions.cxx"
)

target_precompile_headers(
	btc_ArmaToJSON_x64 PUBLIC "include/pch.h"
)

target_include_directories(btc_ArmaToJSON_x64 PUBLIC
                           "include"
)
target_link_libraries(btc_ArmaToJSON_x64 -static-libgcc -static-libstdc++)

target_compile_features(btc_ArmaToJSON_x64 PUBLIC cxx_std_20)
