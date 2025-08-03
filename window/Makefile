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
CLEAN=rm -f $(EXE) *.o *.a
endif

all: window.o loadtexbmp.o shader.o

window.o: window.cpp window.hpp
loadtexbmp.o: loadtexbmp.cpp
shader.o: shader.cpp

.cpp.o:
	g++ -c $(CFLG) -I /usr/include/opencv4 $<

# Clean
clean:
	$(CLEAN)