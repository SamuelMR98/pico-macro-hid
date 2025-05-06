# pico-macro-hid

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

### Requirements

#### Toolchain & Dependencies

- [CMake](https://cmake.org/) (>= 3.13)
- `arm-none-eabi-gcc` toolchain
- [RP2040 Pico SDK](github.com/raspberrypi/pico-sdk)
- VSCode with the following extensions:
  - C/C++ (Microsoft)
  - CMake Tools (Microsoft)
  - Cortex-Debug (Optional, for SWD debugging)

---

### Setup Instructions 🖥️

#### 1. Clone the repository

```bash
git clone https://github.com/SamuelMR98/pico-macro-hud.git
cd pico-macro-hud
```

#### 2. Get the Pico SDK

Clone it outside the project or as a submodule:

```bash
git clone -b master https://github.com/raspberrypi/pico-sdk.git
cd pico-sdk
git submodule update --init
```

Update `pico_sdk_import.cmake` to point to your `pico-sdk` path. You can also set the `PICO_SDK_PATH` environment variable to point to the SDK path.

```cmake
# pico_sdk_import.cmake
set(PICO_SDK_PATH "/path/to/pico-sdk") # Adjust path as needed
include (${PICO_SDK_PATH}/pico_sdk_init.cmake)
```

### Building the Project 🛠️

#### 1. Configure the project with CMake

```bash
mkdir build
cd build
cmake ..
```

#### 2. Compile the project

```bash
make -j4
```

Alternatively, you can use the `cmake --build` command:

```bash
cmake --build . -- -j4
```

or use the VSCode CMake Tools extension to build the project directly from the IDE.

1. Open the project in VSCode.
2. cmd+Shift+P (or Ctrl+Shift+P) to open the command palette.
3. Type "CMake: Configure" and select it.
4. After configuration, type "CMake: Build" and select it.
5. Wait for the build to complete. The output files will be in the `build` directory.

### Flashing the Pico 💾

1. Hold the `BOOTSEL` button on the Pico.
2. Connect the Pico to your computer via USB.
3. A new drive named `RPI-RP2` should appear.
4. Copy the generated `.uf2` file from the `build` directory to the `RPI-RP2` drive.

   ```bash
    cp build/pico-macro-hud.uf2 /path/to/RPI-RP2 
    ```

The Pico will reboot and run the code.

### Roadmap 🔜

- [x] Breadboard button support
- [ ] USB HID keyboard support
- [ ] SPI/I2C display support (SSD1306 or ST7735)
- [ ] MacroPad hardware support (Adafruit)
