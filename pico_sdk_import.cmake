# Auto-import script for Raspberry Pi Pico SDK
set(PICO_SDK_PATH "$ENV{PICO_SDK_PATH}" CACHE PATH "Path to the Pico SDK")
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)