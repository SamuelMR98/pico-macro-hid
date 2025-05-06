# pico-macro-hud

Macros and HUD keyboard using a Raspberry Pico (RP2040)

## Project Overview

- **Device**: Raspberry Pi Pico (RP2040)

- **Purpose**: Macro keyboard + display (e.g., OLEDs, TFTs, etc.) controller

- **Language**: C++ (using Pico SDK)

- **Toolchain**: CMake + arm-none-eabi-gcc

- **Display**: 128x64 OLED (SSD1306) or TFT (ILI9341)

## Features

- **Macro Functionality**: Define and execute keyboard macros
- **HUD Keyboard**: Emulate a USB keyboard to send keystrokes to a host computer
- **Display Support**: Interface with OLED or TFT displays for visual feedback
- **Customizable**: Easily modify macros and settings through configuration files
- **User-Friendly**: Simple interface for defining and executing macros
- **Cross-Platform**: Compatible with Windows, macOS, and Linux

## Getting Started

### Prerequisites

- Raspberry Pi Pico board
- USB cable for connecting the Pico to your computer
- CMake installed on your system
- arm-none-eabi-gcc toolchain installed
- Pico SDK installed and configured
- SSD1306 or ILI9341 display (optional, for visual feedback)
- Optional: Additional libraries for display support (e.g., Adafruit GFX, Adafruit SSD1306, etc.)
- Optional: Additional libraries for HUD keyboard support (e.g., TinyUSB)
- Optional: Additional libraries for macro functionality (e.g., Keyboard library)
- Optional: Additional libraries for configuration file parsing (e.g., JSON library)
