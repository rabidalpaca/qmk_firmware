MCU 					= RP2040
BOOTLOADER      		= rp2040
SERIAL_DRIVER = vendor
ALLOW_WARNINGS 			= yes
LEADER_ENABLE           = yes
COMBO_ENABLE 			= yes
REPEAT_KEY_ENABLE = yes
TAP_DANCE_ENABLE        = no
SRC += secrets.c
VPATH += keyboards/gboards
SRC += features/achordion.c
SRC += features/layer_lock.c
TRI_LAYER_ENABLE = yes
RGBLIGHT_ENABLE = yes
WS2812_DRIVER = vendor


