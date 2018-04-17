# Makefile for creating C program / Arduino code

###################### ARDUINO ######################
ARDUINO_LIBS = RGBLED Time-1.5 
USER_LIB_PATH = /ard/ard-lib

################## MAKEFILE inputs ##################
#FLOW = CPP

#_OBJ = \
#	arduino-i2c-mraa.o

#_DEPS = \
#	i2cBitBangingBus.h

###################### INCLUDE ######################
#include /nas/settings/makefiles/arduino_plus_db.mk
include /nas/settings/makefiles/arduino_only.mk
