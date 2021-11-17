#include <SFML/Graphics.hpp>

using namespace sf;

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

        if (sprite.getPosition().y <= 380){

          // sprite.setTexture(texture);

           sprite.move(0, speed * delta * way);
		}


        if ((sprite.getPosition().y>=373)&&(sprite.getPosition().x<=373)){

            sprite.setTexture(texture);

            sprite.move(speed * delta * way, 0);
		}
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
