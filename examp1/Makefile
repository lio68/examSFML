cc = g++
examp1.exe: examp1.o

	$(cc) examp1.o -o examp1.exe -L '/Program Files/SFML/lib' -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lwinmm -lgdi32
	rm examp1.o
	./examp1.exe

examp1.o: examp1.cpp

	$(cc) -c examp1.cpp -I '/Program Files/SFML/include'

