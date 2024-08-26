MCU 					= RP2040
BOOTLOADER      		= rp2040
# RGB_MATRIX_ENABLE = yes
# RGB_MATRIX_DRIVER = WS2812
# RGBLIGHT_ENABLE = yes
# rcRGBLIGHT_DRIVER  = WS2812
WS2812_DRIVER = vendor
SERIAL_DRIVER = vendor
ALLOW_WARNINGS 			= yes
LEADER_ENABLE           = no
COMBO_ENABLE 			= yes
TAP_DANCE_ENABLE        = no

SRC += secrets.c
VPATH += keyboards/gboards
# SRC += features/achordion.c
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c


