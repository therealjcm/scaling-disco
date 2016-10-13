//
// Created by jasonm on 10/12/2016.
//

#include <SFML/Window.hpp>
#include <iostream>


int main()
{
    sf::Window window(sf::VideoMode(300, 200), "the title");
	while (window.isOpen())
	{
		// handle input
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				window.close();
			}
		}

		// update frame - update objects in the scene

		// render frame - render objects from the scene into the window
	}
    return 0;
}