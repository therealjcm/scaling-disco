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
    sf::RenderWindow window(sf::VideoMode(800, 600), "cliping texture on convex surface");
    window.setFramerateLimit(60);

    sf::Texture texture;
    texture.loadFromFile("iso_tile1.png");
    sf::Vector2u textureSize = texture.getSize();
    texture.setRepeated(true);

//    float textureW = static_cast<float>(textureSize.x);
//    float textureH = static_cast<float>(textureSize.y);

//    sf::RectangleShape rectangleShape(sf::Vector2f(textureW * 3, textureH * 2));
//    rectangleShape.setTextureRect(sf::IntRect(0, 0, textureW * 3, textureH * 2));

    sf::RectangleShape rectangleShape(sf::Vector2f(800, 600));
    rectangleShape.setTextureRect(sf::IntRect(0, 0, 800, 600));
    rectangleShape.setTexture(&texture);

    sf::Texture shapeTexture;
    shapeTexture.loadFromFile("80x80@.png");

	sf::ConvexShape shape(5);
	shape.setPoint(0, sf::Vector2f(0, 0));
	shape.setPoint(1, sf::Vector2f(200, 0));
	shape.setPoint(2, sf::Vector2f(180, 120));
	shape.setPoint(3, sf::Vector2f(100, 200));
	shape.setPoint(4, sf::Vector2f(20, 120));

	shape.setTexture(&shapeTexture);
	shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color::Red);
	shape.move(20, 20);

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

        // render cycle
        window.clear(sf::Color::Black);

        // draw all the objects
        window.draw(rectangleShape);
        window.draw(shape);

        window.display();
	}
    return 0;
}