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

		sf::Vertex &vertex = this->display[i];
		sf::Vector2f &velocity = this->velocities.at(i);

		float distance = std::sqrt(std::pow(vertex.position.x - mousePos.x, 2) + std::pow(vertex.position.y - mousePos.y, 2));

		sf::Vector2f unit_direction_to_pointer = sf::Vector2f(
			(vertex.position.x - mousePos.x) / distance,
			(vertex.position.y - mousePos.y) / distance
		);

		float velocity_towards_pointer;

		velocity_towards_pointer = std::sqrt(distance);
		
		velocity -= unit_direction_to_pointer * velocity_towards_pointer;

		float vel_sum = std::abs(velocity.x + velocity.y);

		float r, g, b;
		
		b = 0;
		r = 255;

		if (vel_sum > 500) {
			g = 0;
		}
		else {
			g = 175 - (vel_sum / 500) * 175;
		}

		vertex.color = sf::Color(r, g, b);
		vertex.position.x += velocity.x * deltaTime.asSeconds();
		vertex.position.y += velocity.y * deltaTime.asSeconds();

		sf::Vector2u window_size = this->window.getSize();
	}

}

void Particles::render() {
	this->window.draw(this->display);
}