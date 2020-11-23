# Mostly written by Jonathan Larmour, Red Hat, Inc.
# Reference to ecos.mak added by John Dallaway, eCosCentric Limited, 2003-01-20
# This file is in the public domain and may be used for any purpose

# Usage:   make INSTALL_DIR=/path/to/ecos/install

INSTALL_DIR = /home/sce/ecos-work/pc_install

include $(INSTALL_DIR)/include/pkgconf/ecos.mak

XCC           = $(ECOS_COMMAND_PREFIX)gcc
XCXX          = $(XCC)
XLD           = $(XCC)

CFLAGS        = -I$(INSTALL_DIR)/include
CXXFLAGS      = $(CFLAGS)
LDFLAGS       = -nostartfiles -L$(INSTALL_DIR)/lib -Ttarget.ld

#####
OBJS	= cmd.o comando.o monitor.o
APP 	= cmd

# RULES

.PHONY: all clean

all: source_fetch bin

run: bin
	qemu-system-i386 -fda $(APP).bin

clean:
	-rm -f cmd $(OBJS)

%.o: %.c
	$(XCC) -c -o $*.o $(CFLAGS) $(ECOS_GLOBAL_CFLAGS) $<

%.o: %.cxx
	$(XCXX) -c -o $*.o $(CXXFLAGS) $(ECOS_GLOBAL_CFLAGS) $<

%.o: %.C
	$(XCXX) -c -o $*.o $(CXXFLAGS) $(ECOS_GLOBAL_CFLAGS) $<

%.o: %.cc
	$(XCXX) -c -o $*.o $(CXXFLAGS) $(ECOS_GLOBAL_CFLAGS) $<

cmd: $(OBJS) source_fetch
	$(XLD) $(LDFLAGS) $(ECOS_GLOBAL_LDFLAGS) -o $(APP) $(OBJS)

bin: cmd
	i386-elf-objcopy -O binary $(APP) $(APP).bin

source_fetch:
	. /opt/ecos/ecosenv.sh
