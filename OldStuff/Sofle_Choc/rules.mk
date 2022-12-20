ENCODER_ENABLE = yes			# Rotary encoders
MOUSEKEY_ENABLE = no			# mousekeys for the right encoder (Warning: Needs lots of flash)
EXTRAKEY_ENABLE = yes			# Audio/Systemcontrol keys
CONSOLE_ENABLE = no				# No debug console
LTO_ENABLE = yes				# Link time optimisation
RGBLIGHT_ENABLE = yes			# RGB Backlight
OLED_ENABLE = yes				# OLED support
OLED_DRIVER = SSD1306			# OLED Driver
TAP_DANCE_ENABLE = yes			# Tap dancing
WPM_ENABLE = yes				# WPM calculator

SRC += features/caps_word.c
