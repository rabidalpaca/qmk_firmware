# MCU name
MCU = STM32F411
BOARD = BLACKPILL_STM32_F411

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
ENCODER_ENABLE = yes
LEADER_ENABLE = no
SPLIT_KEYBOARD = yes
SERIAL_DRIVER = usart
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes
# WS2812_DRIVER = pwm

#  LAYOUTS = LAYOUT_ortho_4x12

# Disable unsupported hardware
AUDIO_SUPPORTED = no
BACKLIGHT_SUPPORTED = no
KEYBOARD_SHARED_EP = yes