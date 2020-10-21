CC=cc
CFLAGS=-Wall

OBJDIR=obj

LIBS=

TARGET=cray
SRCS=$(wildcard src/*.c)
OBJS=${SRCS:src/%.c=obj/%.o}
DEPS=$(wildcard src/*.h)


${TARGET}: ${OBJS} 
	${CC} -o $@ $^ ${CFLAGS}

obj/%.o: src/%.c
	@mkdir -p obj
	${CC} -c -o $@ $^ ${CFLAGS}

.PHONY: clean

clean:
	@rm -rf ${TARGET} ${OBJS} obj