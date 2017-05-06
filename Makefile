# (c) 2004 Charles Eidsness

LIBDIR = /home/charles/cs001.1.0/toolchain/usr/lib
INCDIR = /home/charles/cs001.1.0/toolchain/usr/include
BINDIR = /usr/bin

CROSS = mipsel-linux-
CC = $(CROSS)gcc
AR = $(CROSS)ar
RANLIB = $(CROSS)ranlib

CFLAGS += -static -Wall -g
LDFLAGS += -static -Wall -g
ARFLAGS = cru

libdtmf_LIB = libdtmf.a
libdtmf_oss_OBJ = dtmf-oss.o
libdtmf_alsa_OBJ = dtmf-alsa.o
libdtmf_SRC = dtmf.c
libdtmf_oss_INC = dtmf-oss.h
libdtmf_alsa_INC = dtmf-alsa.h
libdtmf_INC = dtmf.h

testdtmf_EXE = test-dtmf
testdtmf_OBJ = test-dtmf.o
testdtmf_LIBS =  -ldtmf -lasound -lpthread -lm -ldl

.PHONY: alsa oss clean install uninstall disassemble install-test

alsa: $(libdtmf_LIB).alsa Makefile
	cp $(libdtmf_alsa_INC) $(libdtmf_INC)

$(libdtmf_LIB).alsa:$(libdtmf_alsa_OBJ)
	$(AR) $(ARFLAGS) $(libdtmf_LIB) $^
	$(RANLIB) $(libdtmf_LIB)

$(libdtmf_alsa_OBJ):$(libdtmf_SRC)
	$(CC) $(CFLAGS) -DDTMF_ALSA -c $< -o $@

oss: $(libdtmf_LIB).oss Makefile
	cp $(libdtmf_oss_INC) $(libdtmf_INC)

$(libdtmf_LIB).oss:$(libdtmf_oss_OBJ)
	$(AR) $(ARFLAGS) $(libdtmf_LIB) $^
	$(RANLIB) $(libdtmf_LIB)

$(libdtmf_oss_OBJ):$(libdtmf_SRC)
	$(CC) $(CFLAGS)	-c $< -o $@

clean:
	rm -f *.o $(libdtmf_LIB) $(testdtmf_EXE) $(libdtmf_OBJ).dis $(libdtmf_INC)

install:
	install -c -m 666 $(libdtmf_LIB) $(LIBDIR)
	cp $(libdtmf_INC) $(INCDIR)

uninstall:
	rm -f $(LIBDIR)/$(libdtmf_LIB)
	rm -f $(INCDIR)/$(libdtmf_INC)
	rm -f $(BINDIR)/$(testdtmf_EXE)

disassemble:
	mipsel-linux-objdump -DS $(libdtmf_OBJ) > $(libdtmf_OBJ).dis

$(testdtmf_EXE): $(testdtmf_OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(testdtmf_LIBS)
	
install-test: $(testdtmf_EXE)
	install -c -m 755 $(testdtmf_EXE) $(BINDIR)

