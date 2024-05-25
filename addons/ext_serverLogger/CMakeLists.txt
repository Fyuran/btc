cmake_minimum_required (VERSION 3.29.3)

project ("btc_serverLogger_x64"
    LANGUAGES CXX
)

add_library (btc_serverLogger_x64 SHARED)
target_include_directories(btc_serverLogger_x64 PUBLIC
    "include"
)
target_sources (btc_serverLogger_x64 PUBLIC 
    "src/dllmain.cxx"
    "src/dllmain.def"
    "src/armaLogData.cxx"
)
target_compile_features(btc_serverLogger_x64 PUBLIC cxx_std_14)

include(FetchContent)
FetchContent_Declare(
  rapidcsv
  GIT_REPOSITORY "https://github.com/d99kris/rapidcsv.git"
)
FetchContent_MakeAvailable(rapidcsv)
target_link_libraries(btc_serverLogger_x64 PUBLIC rapidcsv)

if(MSVC)
    target_compile_options(btc_serverLogger_x64 PUBLIC
        $<$<CONFIG:>:/MT>
        $<$<CONFIG:Debug>:/MTd>
        $<$<CONFIG:Release>:/MT>
    )
endif()

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME ON)

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS OFF)
    set(BOOST_ROOT "c:/boost_1_85_0")
    set(BOOST_LIBRARYDIR "${BOOST_ROOT}/stage/lib")
endif()

if(UNIX AND NOT APPLE)
    target_link_options(btc_serverLogger_x64 PUBLIC -static-libgcc -static-libstdc++)
endif()

find_package(Boost 1.85 COMPONENTS filesystem REQUIRED)
target_link_libraries(btc_serverLogger_x64 PUBLIC Boost::filesystem)