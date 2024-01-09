#pragma once

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game {
private:
	// Variables
	float enemySpeed;
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Vector2i mousePositionWindow;
	sf::Vector2f mousePositionView;
	sf::Event event;

	// Game logic
	unsigned points;
	double enemySpawnTimerMax;
	double enemySpawnTimer;
	int maxEnemies;
	bool mouseHeld;

	// Game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	// Private methods
	void initializeVariables();
	void initializeWindow();
	void initializeEnemy();

public:
	// Constructor | Destructor
	Game();
	~Game();

	// Accessors
	const bool running() const;

	// Public methods
	void spawnEnemy();
	void renderEnemies();
	void updateEnemies();

	void pollEvents();
	void updateMousePosition();
	void update();
	void render();
};