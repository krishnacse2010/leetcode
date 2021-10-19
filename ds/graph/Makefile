# -------------------Makefile ------------------------ 
#
# To build List and related modules
#
#------------------------------------------------------

CC=g++
GDB=-g
CPP_11=--std=c++11

FLAGS= ${GDB} ${CPP_11}

FILES=List.cpp
BIN=List.out

all:
	${CC} ${FLAGS} ${FILES} -o ${BIN}

run:
	./${BIN}

clean:
	rm -rf ${BIN}

