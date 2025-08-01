EXE=window.a

all: $(EXE)

#  Msys/MinGW
ifeq "$(OS)" "Windows_NT"
CFLG=-O3 -Wall -DUSEGLEW -I/mingw64/include/opencv4
LIBS=-lglfw3 -lglew32 -lglu32 -lopengl32 -lm -std=c++2a -pthread
CLEAN=rm -f *.exe *.o *.a
else
#  OSX
ifeq "$(shell uname)" "Darwin"
CFLG=-O3 -Wall -Wno-deprecated-declarations  -DUSEGLEW -I/usr/include/opencv4
LIBS=-lglfw -lglew -framework Cocoa -framework OpenGL -framework IOKit -std=c++2a -pthread
#  Linux/Unix/Solaris
else
CFLG=-O3 -Wall -I/usr/include/opencv4
LIBS=-lglfw -lGLU -lGL -lm -std=c++2a -pthread
endif
#  OSX/Linux/Unix/Solaris
CLEAN=rm -f $(EXE) *.o *.a
endif

window.o: window.cpp window.hpp 

window.a: window.o
	ar -rcs $@ $^

.cpp.o:
	g++ -c $(CFLG) -I /usr/include/opencv4 $<

clean:
	$(CLEAN)