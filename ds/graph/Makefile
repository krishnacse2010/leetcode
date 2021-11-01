# -------------------Makefile ------------------------ 
#
# To build List and related modules
#
#------------------------------------------------------

CC=g++
GDB=-g
CPP_11=--std=c++11

FLAGS= ${GDB} ${CPP_11}

FILES=Node.cpp Graph.cpp
BIN=gr

ENV=_GRAPH_TEST_

all:
	${CC} ${FLAGS} ${FILES} -o ${BIN} -D ${ENV}

run:
	./${BIN}

clean:
	rm -rf ${BIN}

