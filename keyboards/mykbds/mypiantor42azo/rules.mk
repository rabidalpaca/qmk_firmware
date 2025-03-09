MCU 					= RP2040
BOOTLOADER      		= rp2040
# RGB_MATRIX_ENABLE = yes
# RGB_MATRIX_DRIVER = WS2812
# RGBLIGHT_ENABLE = yes
# rcRGBLIGHT_DRIVER  = WS2812
WS2812_DRIVER = vendor
SERIAL_DRIVER = vendor
ALLOW_WARNINGS 			= yes
LEADER_ENABLE           = yes
COMBO_ENABLE 			= yes
REPEAT_KEY_ENABLE = yes
TAP_DANCE_ENABLE        = yes
SRC += secrets.c
VPATH += keyboards/gboards
SRC += features/layer_lock.c
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = azoteq_iqs5xx


