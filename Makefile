SRC = main.c
OBJ = shell
DESTDIR = /usr/local

all: ${OBJ}

.c.o:
	${CC} -c ${CFLAGS} $<

ssc: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f ${OBJ}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f ${OBJ} ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/${OBJ}

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/${OBJ}

.PHONY: all clean install uninstall
