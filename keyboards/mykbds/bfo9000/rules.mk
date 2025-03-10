# MCU name
MCU 					= RP2040

# Bootloader selection
BOOTLOADER      		= rp2040

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = yes
RGBLIGHT_DRIVER = WS2812
ALLOW_WARNINGS = yes
LEADER_ENABLE = no
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes
SERIAL_DRIVER = pio
WS2812_DRIVER = pio
RAW_ENABLE = yes


SPLIT_KEYBOARD = yes


