cc = g++
o = examp4.o
ee = examp4.exe
pp = examp4.cpp	

examp3.exe: $(o)

	$(cc) $(o) -o $(ee) -L '/Program Files/SFML/lib' -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lwinmm -lgdi32
	rm $(o)
	./$(ee)	

$(o): $(pp)

	$(cc) -c $(pp) -I '/Program Files/SFML/include'



