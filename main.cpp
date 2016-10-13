//
// Created by jasonm on 10/12/2016.
//

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "the title");
    window.setFramerateLimit(60);

    sf::CircleShape circleShape(50);
    circleShape.setFillColor(sf::Color::Red);
    circleShape.setOutlineColor(sf::Color::White);
    circleShape.setOutlineThickness(3);

    sf::RectangleShape rectangleShape(sf::Vector2f(50, 50));
    rectangleShape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		// handle input
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::EventType::Closed:
				window.close();
				break;
            case sf::Event::EventType::Resized:


			case sf::Event::EventType::KeyPressed:
				if (event.key.code == sf::Keyboard::Key::Space)
					window.setTitle("space pressed");
				break;
			case sf::Event::EventType::KeyReleased:
				if (event.key.code == sf::Keyboard::Key::Space)
					window.setTitle("space released");
				else if (event.key.code == sf::Keyboard::Key::Escape)
					window.close();
				break;
			}
		}

		// update scene
        rectangleShape.rotate(1.5f);
        rectangleShape.move(sf::Vector2f(1, 0));

        // render cycle
        window.clear(sf::Color::Black);

        // draw all the objects
        window.draw(circleShape);
        window.draw(rectangleShape);

        window.display();
	}
    return 0;
}