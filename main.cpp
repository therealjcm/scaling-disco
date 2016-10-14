//
// Created by jasonm on 10/12/2016.
//

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "sprite is here");
    window.setFramerateLimit(60);

    sf::Texture bgTexture;
    bgTexture.loadFromFile("iso_tile1.png");
    bgTexture.setRepeated(true);

    sf::RectangleShape background(sf::Vector2f(800, 600));
    background.setTextureRect(sf::IntRect(0, 0, 800, 600));
    background.setTexture(&bgTexture);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("80x80@.png");
    sf::Sprite playerSprite(playerTexture);

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            playerSprite.move(0, -1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            playerSprite.move(0, 1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            playerSprite.move(-1, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            playerSprite.move(1, 0);

        // render cycle
        window.clear(sf::Color::Black);

        // draw all the objects
        window.draw(background);
        window.draw(playerSprite);

        window.display();
	}
    return 0;
}