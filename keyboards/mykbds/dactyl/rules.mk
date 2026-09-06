MCU 					= RP2040
BOOTLOADER      		= rp2040
SERIAL_DRIVER = vendor
ALLOW_WARNINGS 			= yes
LEADER_ENABLE           = yes
COMBO_ENABLE 			= yes
LAYER_LOCK_ENABLE = yes
TAP_DANCE_ENABLE        = no
SRC += secrets.c
RGBLIGHT_ENABLE = yes
WS2812_DRIVER = vendor


