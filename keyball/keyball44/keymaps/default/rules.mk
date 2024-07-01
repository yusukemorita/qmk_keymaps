OLED_ENABLE = yes

# `EMAIL` should be defined as an env variable at compile time
EXTRAFLAGS += -DEMAIL=\"$(EMAIL)\"
