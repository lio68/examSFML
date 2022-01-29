#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h> 
#include <cmath>

    using namespace sf;
    using namespace std;
 
int main()
{
        constexpr unsigned WIN_WIDTH = 900;
        constexpr unsigned WIN_HEIGHT = 700;

      // Устанавливаем 8-й уровень сглаживания
    	ContextSettings settings;
	    settings.antialiasingLevel = 8;

          Image image;
          Texture texture;

	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WIN_WIDTH,WIN_HEIGHT), "SFML Works!");

    window.setFramerateLimit(50); // запустите это один раз, после создания окна  чтобы  приложение запускалось с установленной вами частотой кадров,отличной от частоты монитора 60.

	  
       window.setVerticalSyncEnabled(true);// Включаем вертикальную синхронизацию (для плавной анимации)          

           //   Способ загрузки текстуры в спрайт

		  if( !image.loadFromFile("Imgur.png"))
			 return -1;

          if(! texture.loadFromImage(image))
             return -2; 
		   Sprite sprite(texture);

        Clock clock;//вызываем функцию времени
	 //===//===//===//===//===//===//===//===//===//===//===//===//===//===//===//
// Скорость определим в переменой
    float speed = 400.f;
    // А в этой переменной мы определяем направление
    float way = 1.f;
	 
	// Главный цикл приложения: выполняется, пока открыто окно
	while (window.isOpen())	{

		// Обрабатываем события в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}

     // Запускаем таймер; отсчеты выполняем в секундах

		  // float delta = clock.restart().asSeconds();

		   for (int r=0;r<=4;r++)// перебор номера картинок анимации
                {

                  if(r==4)
                      r=0;            

        sprite.setTextureRect(IntRect(64*r,192,64,96));

           Sleep(269);

          float delta = clock.restart().asSeconds();


           window.clear(Color::Green);//очищает экран , делает фон зелёным

//sprite.move(speed * delta * way,0);//движение спрайта

           window.draw(sprite); // Отрисовка спрайтa
	
           window.display();//всё это показывает

		}
		     
     }

  }
	

