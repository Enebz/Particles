#include "Game.h"

Game::Game(std::string title)
{
    // Create window
    view = sf::Vector2u(512, 512);
    window.create(sf::VideoMode(view.x, view.y), title, sf::Style::Default);

}

void Game::run() {
    init();
    while (window.isOpen()) {
        this->deltaTime = deltaClock.restart();
        update(deltaTime);
        render();
    }
}

void Game::init()
{

}

void Game::update(sf::Time deltaTime) {
    // Window poll events
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;

        case sf::Event::Resized:
            sf::FloatRect visibleArea(0, 0, (float)event.size.width, (float)event.size.height);
            window.setView(sf::View(visibleArea));
            break;
        }

    }

    particles.update(deltaTime);
}

void Game::render() {
    window.clear(sf::Color(0, 0, 0));

    particles.render();

    window.display();
}