cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(poco-macro-hid)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/macros.cpp
    src/display.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} pico_stdlib tinyusb_device tinyusb_board)

pico_add_extra_outputs(${PROJECT_NAME})