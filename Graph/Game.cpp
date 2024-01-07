#include "Game.h"

// Private methods

void Game::initializeVariables() {
	this->window = nullptr;
}

void Game::initializeWindow() {
	this->videoMode.width = 1240;
	this->videoMode.height = 720;

	this->window = new sf::RenderWindow(this->videoMode, "asd");
}


// Constructor | Destructor

Game::Game() {
	this->initializeVariables();
	this->initializeWindow();
}

Game::~Game() {
	delete this->window;
}

// Accessors

const bool Game::running() const {
	return this->window->isOpen();
}

// Public methods

void Game::pollEvents() {
	// Event polling
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type) {
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				if (this->event.key.code == sf::Keyboard::Escape) {
					this->window->close();
				}
				break;
		}
	}
}

void Game::update() {
	this->pollEvents();
}

void Game::render() {
	/*
		- clear the old frame
		- display new frame
		Render the game objects.
	*/
	this->window->clear();
	this->window->display();
}