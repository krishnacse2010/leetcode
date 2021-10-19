# -------------------Makefile ------------------------ 
#
# To build List and related modules
#
#------------------------------------------------------

CC=g++
GDB=-g
CPP_11=--std=c++11

FLAGS= ${GDB} ${CPP_11}

FILES=Node.cpp Tree.cpp
BIN=Tree.out

ENV=__TEST_TREE__

all:
	${CC} ${FLAGS} ${FILES} -o ${BIN} -D ${ENV}

run:
	./${BIN}

clean:
	rm -rf ${BIN}

