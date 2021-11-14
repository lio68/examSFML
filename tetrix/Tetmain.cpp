#include <SFML/Graphics.hpp>
 
using namespace sf;
 
int main()
{	
	RenderWindow window(VideoMode(320, 480), "The Game!");
	
    // Создание и загрузка текстуры
	Texture texture;
	texture.loadFromFile("images\\tiles.png");
	
    // Создание спрайта
	Sprite sprite(texture);

   // Вырезаем из спрайта отдельный квадратик размером 18х18 пикселей
	sprite.setTextureRect(IntRect(0, 0, 18, 18));
 
	// Главный цикл приложения: выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем события в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
 
		// Установка цвета фона - белый
		window.clear(Color::White);
		
        // Отрисовка спрайта
        window.draw(sprite);
	
	    // Отрисовка окна
        window.display();
	}
 
	return 0;
}
