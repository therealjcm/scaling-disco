//
// Created by jasonm on 10/12/2016.
//

#include <SFML/Graphics.hpp>
#include "AssetManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "sprite is here");
    AssetManager the_manager;
    window.setFramerateLimit(60);

    sf::Texture bgTexture = AssetManager::GetTexture("iso_tile1.png");
    bgTexture.setRepeated(true);

    sf::RectangleShape background(sf::Vector2f(800, 600));
    background.setTextureRect(sf::IntRect(0, 0, 800, 600));
    background.setTexture(&bgTexture);

    sf::Sprite playerSprite = sf::Sprite(AssetManager::GetTexture("80x80@.png"));
    sf::Sprite treasureSprite = sf::Sprite(AssetManager::GetTexture("spritesheet-jittery-a.png"));
    sf::Sprite playerSprite2 = sf::Sprite(AssetManager::GetTexture("80x80@.png"));

    sf::Vector2i spriteSize(32, 32);
    treasureSprite.setTextureRect(sf::IntRect(0, 0, spriteSize.x, spriteSize.y));
    int nSpriteFrames = 8;
    float animDuration = 1.0f;

    sf::Time deltaTime, elapsedTime;
    sf::Clock clock;

	while (window.isOpen())
	{
        deltaTime = clock.restart();
        elapsedTime += deltaTime;
        float etSeconds = elapsedTime.asSeconds();
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

        int frame = static_cast<int>((etSeconds / animDuration) * nSpriteFrames) % nSpriteFrames;
        treasureSprite.setTextureRect(sf::IntRect(frame * spriteSize.x, 0, spriteSize.x, spriteSize.y));

        float speed = 30.0f * deltaTime.asSeconds();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
            speed *= 2;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            playerSprite.move(0, -1 * speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            playerSprite.move(0, speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            playerSprite.move(-1 * speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            playerSprite.move(speed, 0);

        // render cycle
        window.clear(sf::Color::Black);

        // draw all the objects
        window.draw(background);
        window.draw(playerSprite);
        window.draw(treasureSprite);

        window.display();
	}
    return 0;
}