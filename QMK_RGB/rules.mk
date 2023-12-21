MCU = atmega32u4				# MCU name
# BOOTLOADER = atmel-dfu		# Bootloader selection (left)
BOOTLOADER = caterina			# Bootloader selection (right)

LTO_ENABLE = yes				# Link time optimisation
SPLIT_KEYBOARD = yes			# Its a split keyboard

# Sofles Features
ENCODER_ENABLE = yes			# Rotary encoders
OLED_ENABLE = yes				# OLED support
# OLED_DRIVER = SSD1306			# OLED Driver

# Optional Features
MOUSEKEY_ENABLE = no			# mousekeys (Warning: Needs lots of flash)
EXTRAKEY_ENABLE = yes			# Audio/Systemcontrol keys
CONSOLE_ENABLE = no				# No debug console
TAP_DANCE_ENABLE = yes			# Tap dancing
WPM_ENABLE = yes				# WPM calculator
RGB_MATRIX_ENABLE = yes			# RGB Matrix LEDs
RGB_MATRIX_DRIVER = ws2812		# The Matrix driver
CAPS_WORD_ENABLE = yes			# Enable build in caps-word
