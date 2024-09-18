cmake_minimum_required (VERSION 3.8)
cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0135 NEW)

project ("btc_ArmaToJSON_x64"
           LANGUAGES CXX
)

add_library (btc_ArmaToJSON_x64 SHARED)

target_sources (btc_ArmaToJSON_x64 PRIVATE 
    "src/armaFileFunctions.cpp"
    "src/dllmain.cpp"
    "src/dllmain.def"
    "src/armaDataFunctions.cpp"
    "include/armaDataFunctions.hpp"
    "include/armaFileFunctions.hpp"
    "include/dllmain.hpp"
  )
target_include_directories(btc_ArmaToJSON_x64 PRIVATE
    "include"
)

target_compile_features(btc_ArmaToJSON_x64 PRIVATE cxx_std_17)

if(MSVC)
    target_compile_options(btc_ArmaToJSON_x64 PRIVATE
        $<$<CONFIG:>:/MT>
        $<$<CONFIG:Debug>:/MTd>
        $<$<CONFIG:Release>:/MT>
    )
    target_compile_definitions(btc_ArmaToJSON_x64 PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME ON)

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS OFF)
    set(BOOST_ROOT "c:/boost_1_85_0")
    set(BOOST_LIBRARYDIR "${BOOST_ROOT}/stage/lib")
endif()

if(UNIX AND NOT APPLE)
    target_link_options(btc_ArmaToJSON_x64 PRIVATE -static-libgcc -static-libstdc++)
endif()

include(FetchContent)
FetchContent_Declare(json 
    GIT_REPOSITORY "https://github.com/nlohmann/json.git"
)
FetchContent_MakeAvailable(json)

find_package(Boost 1.85 COMPONENTS date_time REQUIRED)
target_link_libraries(btc_ArmaToJSON_x64 PRIVATE nlohmann_json::nlohmann_json Boost::date_time)

if(WIN32) 
    install(TARGETS btc_ArmaToJSON_x64 DESTINATION "D:/SteamLibrary/steamapps/common/Arma 3")
endif()
if(UNIX)
    install(TARGETS btc_ArmaToJSON_x64 DESTINATION "~/.local/share/Steam/steamapps/common/Arma 3 Server")
endif()