
CC=cc
CCLD=cc
CFLAGS=

PREFIX=/usr/local

LIBOBJ=src/lib/catctl_rpt.o src/lib/catctl_tone.o src/lib/catctl_ptt.o src/lib/catctl_cw.o src/lib/catctl_mode.o src/lib/catctl_freq.o src/lib/catctl_band.o 
PROGOBJ=src/prog/prog_main.o src/prog/prog_argparse.o src/prog/prog_process.o src/prog/libarg.o 

MANUALS=

LIBS=src/lib/libcatctl.a

PROGS=catctl

all: $(PROGS)

.c.o:
	$(CC) $(CFLAGS) -Isrc/lib -Isrc/prog -c $< -o $@

$(PROGS): $(PROGOBJ) $(LIBS)
	$(CCLD) -o catctl $(PROGOBJ) -Lsrc/lib -lcatctl
	

$(LIBS): $(LIBOBJ)
	ar cr src/lib/libcatctl.a $(LIBOBJ)

.PHONY: clean install

clean:
	rm -f $(PROGOBJ) $(LIBOBJ) $(PROGS) $(LIBS)


