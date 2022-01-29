#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>


using namespace sf;
using namespace std;

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;//ширина окна
    constexpr unsigned WINDOW_HEIGHT = 600;//высота окна
    constexpr float BALL_SIZE = 40;//диаметр круга
     Vector2f speedG = {70.f,40.f};//скорость круга
     Vector2f speedR = {40.f,70.f};//скорость круга
     Vector2f speedB = {70.f,7.f};//скорость круга


   RenderWindow window(VideoMode({WINDOW_WIDTH , WINDOW_HEIGHT }),"Moving Ball" );  //, Style::Fullscreen );доп.параметр весь экран

        Clock clock;
//==================================================================//
//===  Блок зелёного круга =========================================//

   CircleShape shapeG(BALL_SIZE);//создание круга
   shapeG.setPosition({50,50});// установка начальной позиции круга
   shapeG.setFillColor(Color(0xAD,0xCB,0x3A));//цвет круга зелёный
   
//==================================================================//
//===  Блок красного круга =========================================//

   CircleShape shapeR(BALL_SIZE);//создание круга
   shapeR.setPosition({350,150});// установка начальной позиции круга
   shapeR.setFillColor(Color(254,0,53));//цвет круга красный

//==================================================================//
//===  Блок синего круга =========================================//

   CircleShape shapeB(BALL_SIZE);//создание круга
   shapeB.setPosition({500,450});// установка начальной позиции круга
   shapeB.setFillColor(Color(1,170,254));//цвет круга зелёный
   


   while(window.isOpen())
   {
       Event event;
	   while(window.pollEvent(event))
	   {

          if (event.type==Event::Closed)
		  {
              window.close();
		  }
	   }

Vector2f positionG = shapeG.getPosition();//получение текущих координат зелёного круга
Vector2f positionR = shapeR.getPosition();//получение текущих координат красного круга
Vector2f positionB = shapeB.getPosition();//получение текущих координат синего круга

	       const float dt = clock.restart().asSeconds();

              positionG += speedG*dt;
              positionR += speedR*dt;
              positionB += speedB*dt;

  //============= Удары об борт	зелёного круга ===========================//		  
     
          if ((positionG.x + 2*BALL_SIZE >= WINDOW_WIDTH)&&(speedG.x>0))
			 {
                 speedG.x = -speedG.x;
			 }


	      if ((positionG.x < 0)&&(speedG.x < 0))
			 {
                 speedG.x = -speedG.x;
			 }


          if ((positionG.y + 2*BALL_SIZE >= WINDOW_HEIGHT)&&(speedG.y > 0))
			 {
                 speedG.y = -speedG.y;
			 }

          if ((positionG.y < 0)&&(speedG.y < 0))
			 {
                 speedG.y = -speedG.y;
			 }

//============= Удары об борт красного круга ===========================//		  
     
          if ((positionR.x + 2*BALL_SIZE >= WINDOW_WIDTH)&&(speedR.x>0))
			 {
                 speedR.x = -speedR.x;
			 }


	      if ((positionR.x < 0)&&(speedR.x < 0))
			 {
                 speedR.x = -speedR.x;
			 }


          if ((positionR.y + 2*BALL_SIZE >= WINDOW_HEIGHT)&&(speedR.y > 0))
			 {
                 speedR.y = -speedR.y;
			 }

          if ((positionR.y < 0)&&(speedR.y < 0))
			 {
                 speedR.y = -speedR.y;
			 }


//============= Удары об борт синего круга ===========================//		  
     
          if ((positionB.x + 2*BALL_SIZE >= WINDOW_WIDTH)&&(speedB.x>0))
			 {
                 speedB.x = -speedB.x;
			 }


	      if ((positionB.x < 0)&&(speedB.x < 0))
			 {
                 speedB.x = -speedB.x;
			 }


          if ((positionB.y + 2*BALL_SIZE >= WINDOW_HEIGHT)&&(speedB.y > 0))
			 {
                 speedB.y = -speedB.y;
			 }

          if ((positionB.y < 0)&&(speedB.y < 0))
			 {
                 speedB.y = -speedB.y;
			 }
//============== удары между красным и зелёным ============================//

if (((positionR.x-positionG.x)<=40)||((positionG.x-positionR.x)<=40))
{

//speedR.x = -speedR.x;
//speedG.x = -speedG.x;


}

	  


		      shapeG.setPosition(positionG);
              shapeR.setPosition(positionR);
              shapeB.setPosition(positionB);

            window.clear();
			window.draw(shapeG);
            window.draw(shapeR);
            window.draw(shapeB); 
		  //cout << dt << '\n';
            window.display();
   }

}
