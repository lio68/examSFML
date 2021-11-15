
#include <SFML/Graphics.hpp>
using namespace sf;
int main() {
    RenderWindow window(VideoMode(500, 500), "lesson-3-4");
    Texture texture;
    if (!texture.loadFromFile("ciferblat.png"))
        return -1;
    Sprite ciferblat;
    ciferblat.setPosition(0,0);
    ciferblat.setTexture(texture);
    // Создаем стрелку
    RectangleShape strelka(Vector2f(5, 225));
    // Устанавливаем позицию откуда начинать рисовать
    strelka.setPosition(250, 250);
    // И поворачиваем, чтобы установить конец стрелки вверху
    strelka.rotate(180);
    strelka.setFillColor(Color(255, 0, 0));
    Clock clock;
 
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        // Перекрашиваем окно в белый
        window.RenderTarget::clear(Color::White);
        float delta = clock.restart().asSeconds();
        // Каждую секунду поворачиваемся на 6 градусов
        strelka.rotate(6 * delta);
        // Рисуем спрайт
        window.draw(ciferblat);
        // Показываем текущее положение стрелки
        window.draw(strelka);
        window.display();
    }
    return 0;
}
