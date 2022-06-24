TARGET = PSPGAME
OBJS = src/main.o \
	   src/playstate.o \
	   src/char/sonic.o \
	   src/animation.o \
	   src/psp/pad.o \
	   src/psp/audio.o \
	   src/psp/wav.o \
	   src/psp/glib2d.o 

LIBS = -ljpeg -lpng -lz -lpspgum -lpspgu -lpsprtc -lm -lpspvram -lpspaudio -lpspmp3

CFLAGS = -O2 -G0 -Wall -g -fno-builtin-printf
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

# PSP JUNK
PSP_FW_VERSION = 500
PSP_LARGE_MEMORY = 1

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = PSP GAME
PSP_EBOOT_ICON = ICON0.png
PSP_EBOOT_PIC1 = PIC1.png


PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak 
