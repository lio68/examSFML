#include <SFML/Graphics.hpp>
#include <iostream>

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

std::cout << delta << "\n";//смотрим как живет время

        // Смотрим, дошел ли до края?
        // если да, меняем направление
        if (sprite.getPosition().x > 380) way = -1;
        if (sprite.getPosition().x < 0) way = 1;
        // Перемещаем Тукса
        sprite.move(speed * delta * way, speed * delta * way);
 
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
