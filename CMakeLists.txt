cmake_minimum_required (VERSION 3.8)

project ("btc_ArmaToJSON_x64"
           LANGUAGES CXX
)


add_library (btc_ArmaToJSON_x64 SHARED)
target_sources (btc_ArmaToJSON_x64 PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/armaClasses.cxx"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/armaFunctions.cxx"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/dllmain.cxx"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/dllmain.def"
)

target_precompile_headers(
	btc_ArmaToJSON_x64 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/pch.h"
)

target_include_directories(btc_ArmaToJSON_x64 PRIVATE
                           "${CMAKE_CURRENT_SOURCE_DIR}/include"
                           )

target_compile_features(btc_ArmaToJSON_x64 PRIVATE cxx_std_20)

install(TARGETS btc_ArmaToJSON_x64 
    RUNTIME DESTINATION "F:/SteamLibrary/steamapps/common/Arma 3"
    LIBRARY DESTINATION "/home/fyuran/.local/share/Steam/steamcmd/arma3"
)
