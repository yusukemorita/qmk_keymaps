# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
EXTRAKEY_ENABLE = no       # Audio control and System control
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
POINTING_DEVICE_ENABLE = no
MOUSEKEY_ENABLE = no        # Mouse keys


OPT_DEFS += -DPOINTING_DEVICE_CONFIGURATION_TRACKPOINT
PS2_ENABLE = yes
PS2_DRIVER = vendor
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = ps2
MSG_POINTING_DEVICE = trackpoint
