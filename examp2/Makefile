
cc = g++
examp2.exe: examp2.o

	$(cc) examp2.o -o examp2.exe -L '/Program Files/SFML/lib' -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lwinmm -lgdi32
	rm examp2.o
	./examp2.exe

examp2.o: examp2.cpp

	$(cc) -c examp2.cpp -I '/Program Files/SFML/include'

