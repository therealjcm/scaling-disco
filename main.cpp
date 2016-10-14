//
// Created by jasonm on 10/12/2016.
//

#include <SFML/Graphics.hpp>

void initShape(sf::RectangleShape &, sf::Vector2f const &, sf::Color const&);

void initShape(sf::RectangleShape &shape, sf::Vector2f const &pos, sf::Color const& color)
{
	shape.setFillColor(color);
	shape.setPosition(pos);
	shape.setOrigin(shape.getSize() * 0.5f); // center of shape
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "octocat is here");
    window.setFramerateLimit(60);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("octocat.png");
    sf::Vector2u size = playerTexture.getSize();
    float w = static_cast<float>(size.x);
    float h = static_cast<float>(size.y);

	sf::Vector2f startPos = sf::Vector2f(100, 50);
	sf::RectangleShape playerRect(sf::Vector2f(w, h));
    // sf::RectangleShape playerRect(sf::Vector2f(50, 50));
	initShape(playerRect, startPos, sf::Color::Green);
    playerRect.setTexture(&playerTexture);

	sf::RectangleShape targetRect(sf::Vector2f(50, 50));
	initShape(targetRect, sf::Vector2f(550, 50), sf::Color::Blue);

	sf::RectangleShape badRect(sf::Vector2f(100, 100));
	initShape(badRect, sf::Vector2f(350, 50), sf::Color::Red);

	bool gamePaused = false;

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
			case sf::Event::EventType::KeyPressed:
				if (event.key.code == sf::Keyboard::Key::Space)
					window.setTitle("space pressed");
				break;
			case sf::Event::EventType::KeyReleased:
				if (event.key.code == sf::Keyboard::Key::Escape)
					window.close();
				break;
			}
		}

		// update scene
		// player rect is always moving right
		playerRect.move(0.2, 0);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			playerRect.move(0, 1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			playerRect.move(0, -1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            playerRect.move(1, 0);

		if (playerRect.getGlobalBounds().intersects(targetRect.getGlobalBounds()))
			window.close();
		if (playerRect.getGlobalBounds().intersects(badRect.getGlobalBounds()))
			playerRect.setPosition(startPos);

        // render cycle
        window.clear(sf::Color::Black);

        // draw all the objects
        window.draw(playerRect);
        window.draw(targetRect);
		window.draw(badRect);

        window.display();
	}
    return 0;
}