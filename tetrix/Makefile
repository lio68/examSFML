cc = g++

Tetmain.exe: Tetmain.o

	$(cc) Tetmain.o -o Tetmain.exe -L '/Program Files/SFML/lib' -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lwinmm -lgdi32
	rm Tetmain.o
	./Tetmain.exe	

Tetmain.o: Tetmain.cpp

	$(cc) -c Tetmain.cpp -I '/Program Files/SFML/include'



