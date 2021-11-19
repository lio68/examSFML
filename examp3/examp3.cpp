#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {

    RenderWindow window(VideoMode(500, 500), "lesson-3-2");

    Texture texture;
    if (!texture.loadFromFile("tux.png"))
        return -1;

    Sprite sprite;
    sprite.setTexture(texture);

    // Включаем таймер
    Clock clock; 
    // Скорость определим в переменой
    float speed = 100.f;
    // А в этой переменной мы определяем направление
    float way = 1.f;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        // Запускаем таймер; отсчеты выполняем в секундах
        float delta = clock.restart().asSeconds();

        if ((sprite.getPosition().y <= 380)&&(sprite.getPosition().x==0)){

            sprite.move(0, speed * delta * way);
              cout << "x1 = "<< sprite.getPosition().x ;
              cout << "  y1 = "<< sprite.getPosition().y << '\n';

		}

        if ((sprite.getPosition().y>=373)&&(sprite.getPosition().x<=380)){

            sprite.setTexture(texture);
            sprite.move(speed * delta * way, 0);
			  cout << "x2 = "<< sprite.getPosition().x ;
              cout << "  y2 = "<< sprite.getPosition().y << '\n';

		}


        if ((sprite.getPosition().y>=0)&&(sprite.getPosition().x>=380)){

            sprite.setTexture(texture);
            way=-1;
            sprite.move(0,speed * delta * way);
			  cout <<"x3 = "<< sprite.getPosition().x ;
              cout <<"  y3 = "<< sprite.getPosition().y << '\n';

         		}

		
      if ((0<sprite.getPosition().y==0)&&(0<sprite.getPosition().x<=380)){


            sprite.setTexture(texture);
			//sprite.setPosition(380,0);
            way=-1;
            sprite.move(speed * delta * way,0);
			cout <<"x4 = "<< sprite.getPosition().x ;
            cout <<"  y4 = "<< sprite.getPosition().y << '\n';

if ((sprite.getPosition().y<0)&&(sprite.getPosition().x<0)){
   sprite.setPosition(0,0);
   sprite.move(0,0);
}		 
	}   

        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
