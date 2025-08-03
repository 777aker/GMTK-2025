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

all: piece.o bishop.o king.o knight.o pawn.o queen.o rook.o

piece.o: piece.cpp
bishop.o: bishop.cpp
king.o: king.cpp
knight.o: knight.cpp
pawn.o: pawn.cpp
queen.o: queen.cpp
rook.o: rook.cpp

.cpp.o:
	x86_64-w64-mingw32-g++ -c $(CFLG) -I /usr/include/opencv4 $<

# Clean
clean:
	$(CLEAN)