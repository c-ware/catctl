CC=cl
LINK=link
CFLAGS=
OBJS=syscmd(`find src/ -type f -name "*.c" | tr "\n" " " | sed "s/\.c/.obj/g" | sed "s://:/:g" | sed "s:/:\\\:g"')

.c.obj:
	$(CC) /c $(CFLAGS) /Fo$@ $<

all: $(OBJS) docgen.exe

docgen.exe: $(OBJS)
	$(LINK) /out:docgen.exe $(OBJS)

clean:
    del $(OBJS)
    del docgen.exe
