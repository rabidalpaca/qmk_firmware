MCU 					= RP2040
BOOTLOADER      		= rp2040
WS2812_DRIVER = vendor
SERIAL_DRIVER = vendor
ALLOW_WARNINGS 			= yes
LEADER_ENABLE           = no
TAP_DANCE_ENABLE        = no
SRC += secrets.c
VPATH += keyboards/gboards

