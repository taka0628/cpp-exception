CXX = g++

TARGET = main.out

SRCS = $(shell find . -name "*.cpp" -type f | cut -d '/' -f 2)
# SRCS = main.cpp traceback.cpp

OBJ_DIR = build

OBJS = ${SRCS:%.cpp=${OBJ_DIR}/%.o}

LDGFLAGS =

LDFLAGS =

CFLAGS = -Wall\
	-std=c++11\
	-O2



${TARGET}: ${OBJS}
	${CXX} -o $@ $^ ${LDFLAGS} ${LDGFLAGS}

${OBJ_DIR}/%.o: %.cpp
	mkdir -p build
	cd build;\
	${CXX} -c ../$^ ${CFLAGS}

clean:
	rm -rf ${OBJDIR}/*.o ${TARGET}
	rm -rf $(shell find . -name *.out -type f)

rebuild:
	make clean
	make