#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

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

    // Declare and create a new window
    sf::Window window2(sf::VideoMode(800, 600), "SFML window");
    // Limit the framerate to 60 frames per second (this step is optional)
    window2.setFramerateLimit(60);
    // The main loop - ends as soon as the window is closed
    while (window2.isOpen())
    {
       // Event processing
       sf::Event event;
       while (window2.pollEvent(event))
       {
           // Request for closing the window
           if (event.type == sf::Event::Closed)
               window2.close();
       }
       // Activate the window for OpenGL rendering
       window2.setActive();
       // OpenGL drawing commands go here...
       // End the current frame and display its contents on screen
       window2.display();
    }
    return 0;
}
