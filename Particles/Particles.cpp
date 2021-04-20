#include "Particles.h"
#include <iostream>

Particles::Particles(sf::RenderWindow &window, int amount)
	:	window(window)
{
	this->amount = amount;
	this->display = sf::VertexArray(sf::PrimitiveType::Points, this->amount);

	this->velocities.resize(amount);

	for (int i = 0; i < this->amount; i++) {
		this->display[i].position = sf::Vector2f(std::rand() % 513, std::rand() % 513);
		this->display[i].color = sf::Color(255, 0, 0);
		//this->velocities[i] = sf::Vector2f(std::rand() % 100, std::rand() % 100);
		this->velocities[i] = sf::Vector2f(0,0);
	}
}

void Particles::update(sf::Time deltaTime) {

	sf::Vector2i mousePos = sf::Mouse::getPosition(this->window);
	// sf::Vector2i mousePos = sf::Vector2i(256, 256);

	for (int i = 0; i < this->amount; i++) {

		sf::Vertex vertex = this->display[i];
		sf::Vector2f &velocity = this->velocities.at(i);

		float distance = std::sqrt(std::pow(vertex.position.x - mousePos.x, 2) + std::pow(vertex.position.y - mousePos.y, 2));

		sf::Vector2f unit_direction_to_pointer = sf::Vector2f(
			(vertex.position.x - mousePos.x) / distance,
			(vertex.position.y - mousePos.y) / distance
		);

		float velocity_towards_pointer = 5;
		velocity -= unit_direction_to_pointer * velocity_towards_pointer;


		this->display[i].color = sf::Color(150, 30, 245);
		this->display[i].position.x += velocity.x * deltaTime.asSeconds();
		this->display[i].position.y += velocity.y * deltaTime.asSeconds();
	}

}

void Particles::render() {
	this->window.draw(this->display);
}