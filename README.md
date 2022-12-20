# Sofle Split ErgoMech

Currently I own two Sofles, a RGB and a Choc. I use the same layout and features on both of them, at least if possible. The Choc has for example no downlight LEDs and no indicators
Besides that I've build both with 2 OLEDs and 2 rotary encoders
Both have 3D printed tilted cases

Features:
- Alternative Layer with:
  - Umlauts, created with Linux Compose mechanism
  - F1 to F12, brackets and print screen
- Holding TAB switches to RGB Matrix configuration
- Cursor layer with PageUp/Down, Home, End
- Indicator LEDs to show current layer
- On on-standard layer: Highlight key with alt function
- Right OLED: Current layer and modifiers
- Left OLED: Neko-Cat animation depending on WPS
- Caps-Word on left+right shift

TODOs:
- Separated control of downlights
- ARASAKA-Logo on OLED on wake-up
- WPM graph
- Update Sofle Choc variant

![Sofle](soflekeyboard.jpg)

[Layout](http://www.keyboard-layout-editor.com/#/gists/1e62fbb4f1adce56eced4e547606cf52)

## Sofle RGB

 - Keys: Gazzew U4 RGB
 - Keycaps: Pudding Black
 
Thanks to some messing around my left side has a MCU with dfu bootloader, my right side with caterina
make sofle_rgb:default:avrdude-split-right
make sofle_rgb:default:dfu-split-left

![SofleRGB](sofle_rgb.jpg)

## Sofle Choc

Note: Currently outdated and needs some rework for current QMK version!

- Keys: Kailh red choc
- Keycaps: Pudding Black

![SofleChoc](sofle_choc.jpg)

