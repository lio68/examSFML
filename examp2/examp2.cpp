#include <SFML/Graphics.hpp>
#include <iostream>
 
using namespace sf;

Image image;
Texture texture;
Sprite sprite;


 
int main()
{ 

// Устанавливаем 8-й уровень сглаживания
	ContextSettings settings;
	settings.antialiasingLevel = 8;

        constexpr unsigned WIN_WIDTH = 900;
        constexpr unsigned WIN_HEIGHT = 700;


	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WIN_WIDTH,WIN_HEIGHT), "SFML Works!");

      //Clock clock; //создаем переменную времени
     // Vector2f position = circle.getPosition();
	
	// Скорость определим в переменой
    float speed = 100.f;
    // А в этой переменной мы определяем направление
    float way = 1.f;

	  
      window.setVerticalSyncEnabled(true);// Включаем вертикальную синхронизацию (для плавной анимации)
     // Vector2f speed = {50.f,15.f};//скорость в векторном виде с координатами x,y
 
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
		// Установка цвета фона - белый
		window.clear(Color::White);

           //  1 Способ загрузки текстуры в спрайт
		  if( !image.loadFromFile("Imgur.png"))
			 return -1;

          if(! texture.loadFromImage(image))
             return -2; 
		   Sprite sprite(texture);

          //sprite.setTextureRect(IntRect(0,0,69,96));

          Clock clock; 

     // Запускаем таймер; отсчеты выполняем в секундах
        float delta = clock.restart().asSeconds();

         sprite.move( speed * delta * way,0);

    //std::cout << delta << "\n";//смотрим как живет время

        // Смотрим, дошел ли до края?
        // если да, меняем направление
       // if (sprite.getPosition().x > 650) way = -1;
       // if (sprite.getPosition().x < 0) way = 1;
        // Перемещаем Тукса
		
         sprite.setTextureRect(IntRect(0,0,69,96));

       // sprite.move( speed * delta * way,0);
 
           window.clear();
           window.draw(sprite); // Отрисовка спрайтa 

      /*   //  2 Способ загрузки текстуры в спрайт
 
		// Создаем переменную текстуры
		Texture texture;		
 
	   // Подгружаем нашу текстуру из файла texture.png
	    texture.loadFromFile("erl.png", IntRect(0, 200,WINDOW_WIDTH,WINDOW_HEIGHT));
 
		// Создаем спрайт и устанавливаем ему нашу текстуру
		Sprite sprite(texture);
		
		window.draw(sprite); // Отрисовка спрайта */


	/*	CircleShape circle(BALL_SIZE);// Устанавливаем круг радиусом 30 
		circle.setFillColor(Color::Yellow); // закрашиваем наш круг
        circle.setPosition(15, 15);//начальная позиция с координатами (x,y)

        float time = clock.getElapsedTime().asSeconds();//получение времени в секундах
        // Vector2f speed = {50.f,15.f};//скорость в векторном виде с координатами x,y

            Vector2f position = circle.getPosition();//нач.позиция в векторном виде (x,y)
                  position += speed*time;//изменение позиции

            if((position.x + 2*BALL_SIZE >= WIN_WIDTH) && (speed.x>0))
			{
                   speed.x = -speed.x;
               position += speed*time;//изменение позиции

			  }

           if((position.x < 0) && (speed.x < 0))
			{
                   speed.x = -speed.x;
                 position += speed*time;//изменение позиции

			  }

           if((position.y + 2*BALL_SIZE >= WINDOW_WIDTH) && (speed.y>0))
			{
                   speed.y = -speed.y;
                position += speed*time;//изменение позиции

			  }

           if((position.y < 0) && (speed.y < 0))
			{
                   speed.y = -speed.y;
              position += speed*time;//изменение позиции

			  }

                 
		           //position += speed*time;//изменение позиции


                  //position.y +=v*dtime;// изменение позиции по координате "у" 
                  circle.setPosition(position);//фиксация позиции с учётом изменений

	//if(time>=1.24389e+07){
              // clock.restart(); //перезагружает время
             // circle.setPosition(700, 15); 
             // circle.move(v*((1.24389e+07)-time), 15);
		  // }

	/*else {
		circle.move(v*time, 15); // перемещаем круг для корректного отображения в окне	
		window.draw(circle); // отрисовка круга.
	  }

        // std::cout << time << "\n";//смотрим как живет время


        //window.clear();
		window.draw(circle);*/ // отрисовка круга

		window.display(); // Отрисовка окна

	}
 
	return 0;
}
