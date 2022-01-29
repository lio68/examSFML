cc = g++       # переменная для названия компилятора 
o = main.o     # переменная для объектного файла
ee = main.exe  # переменная для исполняемого файла
pp = main.cpp  # переменная для исходного файла	

$(ee): $(o)

	$(cc) $(o) -o $(ee) -L '/Program Files/SFML/lib' -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lwinmm -lgdi32
	rm $(o)
	./$(ee)	

$(o): $(pp)

	$(cc) -c $(pp) -I '/Program Files/SFML/include'

