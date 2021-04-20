#ifndef PARTICLES_H
#define PARTICLES_H

#include <SFML/Graphics.hpp>

class Particles
{
private:
	sf::RenderWindow &window;

	sf::VertexArray display;

	std::vector<sf::Vector2f> velocities;

	int amount;

	sf::Vector2f velocity = sf::Vector2f(0, 0);

public:
	Particles(sf::RenderWindow &window, int amount);

	void update(sf::Time deltaTime);
	
	void render();
};

#endif
