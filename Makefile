CLIfe: cursor.o space.o lifeboard.o engine.o main.o
	g++ -o CLIfe cursor.o space.o lifeboard.o engine.o main.o

cursor.o: include/cursor.h src/cursor.cpp
	g++ -c -Iinclude include/cursor.h src/cursor.cpp

space.o: include/space.h src/space.cpp
	g++ -c -Iinclude include/space.h src/space.cpp

lifeboard.o: include/lifeboard.h src/lifeboard.cpp
	g++ -c -Iinclude include/lifeboard.h src/lifeboard.cpp

engine.o: include/engine.h src/engine.cpp
	g++ -c -Iinclude include/engine.h src/engine.cpp

main.o: include/engine.h src/main.cpp
	g++ -c -Iinclude src/main.cpp

clean:
	rm CLIfe cursor.o space.o lifeboard.o engine.o main.o
