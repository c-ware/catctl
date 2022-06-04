dnl M4 Makefile template for UNIX systems
dnl part of the catctl project

CC=cc
CCLD=cc
CFLAGS=

PREFIX=/usr/local

LIBOBJ=syscmd(`find src/lib -type f -name "*.c" | tr "\n" " " | sed "s/\.c/.o/g" | sed "s://:/:g"')
PROGOBJ=syscmd(`find src/prog -type f -name "*.c" | tr "\n" " " | sed "s/\.c/.o/g" | sed "s://:/:g"')

MANUALS=syscmd(`for f in $(find . -type f -name "*.cware"); do echo $f | xargs basename; done | tr "\n" " "')

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


