cc = g++
o = clock.o
ee = clock.exe
pp = clock.cpp	

examp3.exe: $(o)

	$(cc) $(o) -o $(ee) -L '/Program Files/SFML/lib' -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lwinmm -lgdi32
	rm $(o)
	./$(ee)	

$(o): $(pp)

	$(cc) -c $(pp) -I '/Program Files/SFML/include'



