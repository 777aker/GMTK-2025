#  Msys/MinGW
ifeq "$(OS)" "Windows_NT"
CFLG=-O3 -Wall -g -DUSEGLEW -I/mingw64/include/opencv4 -std=c++20
LIBS=-lmingw32 -mwindows -lglfw3 -lglew32 -lglu32 -lopengl32 -lm
CLEAN=rm -f *.exe *.o *.a
else
#  OSX
ifeq "$(shell uname)" "Darwin"
CFLG=-O3 -Wall -g -Wno-deprecated-declarations  -DUSEGLEW -I/usr/include/opencv4 -std=c++20
LIBS=-lglfw -lglew -framework Cocoa -framework OpenGL -framework IOKit
#  Linux/Unix/Solaris
else
CFLG=-O3 -Wall -g -I/usr/include/opencv4 -std=c++20
LIBS=-lglfw -lGLU -lGL -lm
endif
#  OSX/Linux/Unix/Solaris
CLEAN=rm -f $(EXE) *.o *.a choop choop.exe
endif

SUBDIRS := $(wildcard */.)

all: $(SUBDIRS) choop.exe
clean: $(SUBDIRS)
	$(CLEAN)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.cpp.o:
	x86_64-w64-mingw32-g++ -c $(CFLG) -I /usr/include/opencv4 $<

.PHONY: $(SUBDIRS)

SRC = $(wildcard */*.cpp)
OBJ = $(SRC:.cpp=.o)

choop: $(OBJ)
	x86_64-w64-mingw32-g++ $(CFLG) -o $@ $^ $(LIBS)