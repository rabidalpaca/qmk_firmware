MCU 					= RP2040
BOOTLOADER      		= rp2040
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = vendor
ALLOW_WARNINGS 			= yes
LEADER_ENABLE           = no
COMBO_ENABLE 			= yes
TAP_DANCE_ENABLE        = yes
SERIAL_DRIVER = vendor
SRC += secrets.c
