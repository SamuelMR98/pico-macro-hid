# pico-macro-hud

Starter project for an RP2040-based macro keyboard / HUD controller.

## Current milestone

This starter version focuses on:

- breadboard buttons
- clean module structure
- page/profile concept
- serial-debug "macro execution"
- easy path to later add:
  - TinyUSB HID keyboard output
  - real OLED/TFT display support
  - persistent config
  - desktop configurator

## Wiring assumptions

This version assumes each button:

- connects one side to a GPIO pin
- connects the other side to GND
- uses the RP2040 internal pull-up resistor

So the input is:

- HIGH = not pressed
- LOW = pressed

## Default pins

- Button 1 -> GPIO 2
- Button 2 -> GPIO 3
- Button 3 -> GPIO 4
- Button 4 -> GPIO 5

## Build

From inside `firmware/`:

```bash
mkdir -p build
cd build
cmake ..
make -j
```

### Done Checklist

- [x] Basic button input handling
- [ ] Page/profile system
- [ ] Serial debug output for macro execution
- [ ] Clean module structure
- [ ] Documentation
- [ ] Example macros
- [ ] Test on actual hardware
- [ ] Prepare for next steps (HID output, display, config)
