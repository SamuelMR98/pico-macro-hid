cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_FETCH_FROM_GIT on)
include(pico_sdk_import.cmake)

project(pico-macro-hid C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(pico-macro-hid
    src/actions.c
    src/buttons.c
    src/display.c
    src/main.c
    src/profiles.c
    src/usb_hid.c
)

target_include_directories(pico-macro-hid PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/config
)

target_link_libraries(pico-macro-hid
    pico_stdlib
)

pico_enable_stdio_usb(pico-macro-hid 1)
pico_enable_stdio_uart(pico-macro-hid 0)

pico_add_extra_outputs(pico-macro-hid)