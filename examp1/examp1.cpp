#include <SFML/Graphics.hpp>
#include <iostream> // подключаем, чтобы посмотреть на время в консоли
 #include "map.h" //подключили код с картой игры (ландшафт игры)
using namespace sf;
int main()
{
 RenderWindow window(sf::VideoMode(900, 700), "Lesson 6. kychka-pc.ru");
 
 
 ////// Загрузка текстуры в спрайт героя ////////////////
 Texture herotexture;
 herotexture.loadFromFile("images/Imgur.png"); 
 Sprite herosprite;
 herosprite.setTexture(herotexture);
 herosprite.setTextureRect(IntRect(0, 0, 64, 96));
 herosprite.setPosition(250, 100);

////// Загрузка текстуры неба //////////////////////////
 //Texture skytexture;
 //skytexture.loadFromFile("images/sky.png"); 
 //Sprite skysprite;
 //skysprite.setTexture(skytexture);
 //skysprite.setTextureRect(IntRect(0, 0, 90, 50));
 //skysprite.setPosition(0, 0);

 ////// Загрузка текстуры кирпича //////////////////////////
 Texture bricktexture;
 bricktexture.loadFromFile("images/stone2.png"); 
 Sprite bricksprite;
 bricksprite.setTexture(bricktexture); 
//bricksprite.setTextureRect(IntRect(0,0, 90, 50));
//bricksprite.setPosition(0, 650);

////// Загрузка текстуры газона //////////////////////////
 Texture gazontexture;
 gazontexture.loadFromFile("images/gazon.png"); 
 Sprite gazonsprite;
 gazonsprite.setTexture(gazontexture);
 //gazonsprite.setTextureRect(IntRect(0,0, 90, 50));
 //gazonsprite.setPosition(0, 600);


     float CurrentFrame = 0;//хранит текущий кадр
 
 Clock clock; //создаем переменную времени, т.о. привязка ко времени(а не мощности/загруженности процессора). 
 
 while (window.isOpen())
 {
 
 float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
 clock.restart(); //перезагружает время
 time = time/800; //скорость игры 
 
 
 Event event;
 while (window.pollEvent(event))
 {
 if (event.type == sf::Event::Closed)
 window.close();
 }

// herosprite.move(0,0.05*time);

if (event.type != Event::KeyPressed)//событие не нажатия клавиши
  herosprite.setTextureRect(IntRect(0, 0, 64, 96));

 if ((Keyboard::isKeyPressed(Keyboard::Left) ||
	(Keyboard::isKeyPressed(Keyboard::A)))) {
    CurrentFrame += 0.007*time; //служит для прохождения по "кадрам". переменная доходит 
	                            // до 4,суммируя произведение времени и скорости.       
								//изменив 0.005 можно изменить скорость анимации.
    if (CurrentFrame > 4) CurrentFrame -= 4; //проходимся по кадрам с первого по 4 кадр включительно. если пришли к 4 кадру - откидываемся назад.
			herosprite.setTextureRect(IntRect(64 * int(CurrentFrame), 96, 64, 96)); //проходимся по координатам Х. получается 0,64*1,64*2,64*3 и опять 0
	        herosprite.move(-0.04*time, 0);//движение самого персонажа
 } //-0,1 это скорость, умножаем её на наше время и получаем пройденное расстояние

 if ((Keyboard::isKeyPressed(Keyboard::Right) ||
     (Keyboard::isKeyPressed(Keyboard::D)))) {
     CurrentFrame += 0.007*time; 
     if (CurrentFrame > 4) CurrentFrame -= 4;
     herosprite.setTextureRect(IntRect(64 * int(CurrentFrame), 192, 64, 96)); 
	     herosprite.move(0.04*time, 0);
 }

 if ((Keyboard::isKeyPressed(Keyboard::Up) ||
	 (Keyboard::isKeyPressed(Keyboard::W)))) {
     CurrentFrame += 0.007*time; 
     if (CurrentFrame > 4) CurrentFrame -= 4;
     herosprite.setTextureRect(IntRect(64 * int(CurrentFrame), 288, 64, 96)); 
	     herosprite.move(0, -0.04*time);
 }		 

 if ((Keyboard::isKeyPressed(Keyboard::Down) ||
	 (Keyboard::isKeyPressed(Keyboard::S)))) {
     CurrentFrame += 0.007*time; 
     if (CurrentFrame > 4) CurrentFrame -= 4;
     herosprite.setTextureRect(IntRect(64 * int(CurrentFrame), 0, 64, 96)); 
	     herosprite.move(0, 0.04*time); 
 } 
 
 window.clear(Color::Cyan);//очищает экран , делает фон зелёным

/////////////////////////////Рисуем карту/////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			/*if (TileMap[j][i] == ' '){
			   skysprite.setTextureRect(IntRect(0, 0, 90, 70));
               skysprite.setPosition(i*90, j*70);
               window.draw(skysprite);

			}*/

			if (TileMap[j][i] == 't'){
			   gazonsprite.setTextureRect(IntRect(0, 0, 90, 70));
               gazonsprite.setPosition(i*90, j*70);
               window.draw(gazonsprite);

			}

			if (TileMap[j][i] == '0'){
			   bricksprite.setTextureRect(IntRect(0, 0, 90, 70));
               bricksprite.setPosition(i*90, j*70);
               window.draw(bricksprite);

			} 
 
		}

 //window.draw(skysprite);
 //window.draw(gazonsprite);
 //window.draw(bricksprite);
 window.draw(herosprite);
 window.display();
 }
 
 return 0;
}
