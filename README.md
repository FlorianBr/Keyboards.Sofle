# Sofle Split ErgoMech

Currently I own two [Sofles](https://josefadamcik.github.io/SofleKeyboard/), a RGB and a Choc. One (maybe two...) more are currently in the works. The Sofle seems to be my "End-Game" keyboard and seems to be perfect for my use-case.

I use the same layout and features on both of them, at least if possible. The Choc has for example no downlight LEDs and no indicator LEDs. I've build both with 2 OLEDs and 2 rotary encoders, both have 3D printed tilted cases. For the next ones I plan to replace the right encoder with a trackpad, and the OLEDs with LCDs.

List of features:

- ColemakDH Layout
- Alternative Layer with:
  - Umlauts, created with Linux Compose mechanism
  - F1 to F12, brackets and print screen
- Alternative Layer with:
  - Cursor keys on WASD
  - PageUp/Down, Home, End
- Holding TAB switches to RGB Matrix configuration
- Indicator LEDs to show current layer (not on choc)
- On alternative layers: Highlight key with alt function
- Left OLED: Current layer and modifiers
- Right OLED: Neko-Cat animation depending on WPS
- Caps-Word on left+right shift

TODOs:

- ARASAKA-Logo on OLED on wake-up
- WPM graph

![Sofle](soflekeyboard.jpg)

[Layout](http://www.keyboard-layout-editor.com/#/gists/1e62fbb4f1adce56eced4e547606cf52)

## The Keyboards

### Sofle RGB v1

- Keys: Gazzew U4 RGB
- Keycaps: Pudding Black
- OS: QMK

Thanks to some messing around my left side has a MCU with dfu bootloader, my right side with caterina:

- make sofle_rgb:default:avrdude-split-right
- make sofle_rgb:default:dfu-split-left

![SofleRGB](sofle_rgb.jpg)

### Sofle Choc v1

- Keys: Kailh red choc
- Keycaps: Pudding Black
- OS: QMK

![SofleChoc](sofle_choc.jpg)

### Sofle RGB v2

Currently work in progress/planning. Should replace my desktop keyboard, powered by USB but still connected by Bluetooth

- Keys: Gazzew U4 RGB again
- Keycaps: TBD
- Controller: 2x Nice!Nano
- Displays: 2x Nice!View
- Others: Pimoroni Trackball
- OS: ZMK

### Sofle Choc v2

Currently in planning. For mobile/office use. Powered by USB or LiIon, connected by Bluetooth

- Keys: Kailh Choc Sunset Tactile
- Keycaps: TBD
- Controller: TBD
- Displays: TBD
- OS: TBD
