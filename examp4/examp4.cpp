#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;
int main() {
    RenderWindow window(VideoMode(500, 500), "lesson-4-2");
    Texture texture;
    if (!texture.loadFromFile("tux.png"))
        return -1;
 
    Sprite sprite;
    sprite.setTexture(texture);
    Clock clock;
    int X0 {}, Y0 {}, X, Y;
    float speed = 1000.f;
    float distance;
    bool mspr = false;
    sprite.setPosition(X0, Y0);
 
    while (window.isOpen()) {
        float delta = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        delta = delta / speed;
        Event event;
        if (Mouse::isButtonPressed(Mouse::Left)) {
            Vector2i pos = Mouse::getPosition(window);
            X = pos.x;
            Y = pos.y;
            distance = hypot(X-X0, Y-Y0);
            mspr = true;
        }
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        if (mspr) {
            X0 += delta * (X - X0) / distance;
            Y0 += delta * (Y - Y0) / distance;
            sprite.setPosition(X0, Y0);
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
