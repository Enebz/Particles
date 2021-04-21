#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Particles.h"

class Game
{
private:
	sf::RenderWindow window;
	sf::Vector2u view;

    sf::Clock deltaClock;
    sf::Time deltaTime;
    
    Particles particles = Particles(window, 50000);

public:

    Game(std::string title);

    void run();

    void init();

    void update(sf::Time deltaTime);

    void render();
};

#endif