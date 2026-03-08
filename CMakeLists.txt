cmake_minimum_required(VERSION 3.15)
project(UnlockAllCars)

set(CMAKE_CXX_STANDARD 20)

# ── Percorso SDK BakkesMod ──
# Modifica se il tuo SDK è in un posto diverso
set(BAKKESMOD_SDK_PATH "C:/BakkesModSDK" CACHE PATH "BakkesMod SDK path")

file(GLOB SOURCES "*.cpp" "*.h")

add_library(UnlockAllCars SHARED ${SOURCES})

target_include_directories(UnlockAllCars PRIVATE
    ${BAKKESMOD_SDK_PATH}/include
)

target_link_libraries(UnlockAllCars PRIVATE
    ${BAKKESMOD_SDK_PATH}/lib/pluginsdk.lib
)

# Output diretto nella cartella plugin di BakkesMod
set_target_properties(UnlockAllCars PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "$ENV{APPDATA}/bakkesmod/bakkesmod/plugins"
    SUFFIX ".dll"
)
