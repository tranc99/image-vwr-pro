#include <iostream>
// Qt-Creator delays output to the console via cout till the app is finished.
// With qDebug() we get it at runtime
#include <QDebug>
#include <SFML/Graphics.hpp>

using namespace std;

// Creates the RenderWindow with a size of 800*600 and 32 bits colordepth as
// a global variable
sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Jump & Run Tutorial");
// The event that we use to catch the closing of the game
sf::Event Event;

bool init() {
    // return that initialization was successful
    return true;
}

void update() {
    // look for events

}


int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    window.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}
