MOUSEKEY_ENABLE = no     # Mouse keys
VIA_ENABLE      = yes    # Enable VIA
CONSOLE_ENABLE  = yes    # Console for debug

# `PERSONAL_EMAIL`, `PERSONAL_EMAIL_DEV`, `WORK_EMAIL`
# should be defined as env variables at compile time
EXTRAFLAGS += -DENV_EMAIL_1=\"$(PERSONAL_EMAIL)\"
EXTRAFLAGS += -DENV_EMAIL_2=\"$(WORK_EMAIL)\"
EXTRAFLAGS += -DENV_EMAIL_3=\"$(PERSONAL_EMAIL_DEV)\"
