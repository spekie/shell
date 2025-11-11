SRC = main.c
OBJ = ${SRC:.c=.o}
DESTDIR = /usr/local

all: shell

.c.o:
	${CC} -c ${CFLAGS} $<

shell: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f shell ${OBJ}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f shell ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/shell

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/shell

.PHONY: all clean install uninstall
