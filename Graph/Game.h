#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game {
private:
	// Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	// Private methods
	void initializeVariables();
	void initializeWindow();

public:
	// Constructor | Destructor
	Game();
	~Game();

	// Accessors
	const bool running() const;

	// Public methods
	void pollEvents();
	void update();
	void render();
};