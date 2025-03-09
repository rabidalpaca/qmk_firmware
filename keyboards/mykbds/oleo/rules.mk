MCU 					= RP2040
BOOTLOADER      		= rp2040
SERIAL_DRIVER = vendor
ALLOW_WARNINGS 			= yes
TAP_DANCE_ENABLE        = no
ENCODER_MAP_ENABLE      = yes
SRC += secrets.c
VPATH += keyboards/gboards


