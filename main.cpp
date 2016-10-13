//
// Created by jasonm on 10/12/2016.
//

#include <SFML/Window.hpp>
#include <iostream>


int main()
{
    sf::Window window(sf::VideoMode(300, 200), "the title");
    std::cin.get();
    window.close();
    return 0;
}