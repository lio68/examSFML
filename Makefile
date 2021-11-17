cc = g++
o = examp3.o
ee = examp3.exe
pp = examp3.cpp	

examp3.exe: $(o)

	$(cc) $(o) -o $(ee) -L '/Program Files/SFML/lib' -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lwinmm -lgdi32
	rm $(o)
	./$(ee)	

$(o): $(pp)

	$(cc) -c $(pp) -I '/Program Files/SFML/include'



