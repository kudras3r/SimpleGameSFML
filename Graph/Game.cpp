#include "Game.h"

// Private methods

void Game::initializeVariables() {
	this->window = nullptr;
	this->points = 0;
	this->enemySpawnTimerMax = 3.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 6;
	this->enemySpeed = 1.0f;
	this->mouseHeld = false;
}

void Game::initializeWindow() {
	this->videoMode.width = 1240;
	this->videoMode.height = 720;

	this->window = new sf::RenderWindow(this->videoMode, "asd");

	this->window->setFramerateLimit(60);
}

void Game::initializeEnemy() {
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setFillColor(sf::Color::Red);
}

// Constructor | Destructor

Game::Game() {
	this->initializeVariables();
	this->initializeWindow();
	this->initializeEnemy();
}

Game::~Game() {
	delete this->window;
}

// Accessors

const bool Game::running() const {
	return this->window->isOpen();
}

// Public methods

void Game::spawnEnemy() {
	/*
		- Spawn enemy
		- Set random position
		- Add enemy to enemies vector
	*/
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
	);
	this->enemy.setFillColor(sf::Color::Red);
	this->enemies.push_back(this->enemy);
}

void Game::renderEnemies() {
	for (auto& e : this->enemies) {
		this->window->draw(e);
	}
}

void Game::updateEnemies() {
	/*
		Updating spawn times and spawn enemies
	*/
	if (this->enemies.size() < this->maxEnemies) {
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else {
			this->enemySpawnTimer += 1.f;
		}
	}

	// Move enemies
	for (unsigned i = 0; i < this->enemies.size(); i++) {
		this->enemies[i].move(0.f, enemySpeed);
		// Check click
		if (this->enemies[i].getPosition().y > this->window->getSize().y) {
			this->enemies.erase(this->enemies.begin() + i);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (this->enemies[i].getGlobalBounds().contains(this->mousePositionView)) {
				this->enemies.erase(this->enemies.begin() + i);
				points++;
				if (points % 10 == 0) {
					this->enemySpeed += 1.f;
				}				
		    }
		}
	}
}

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

void Game::updateMousePosition() {
	this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
	this->mousePositionView = this->window->mapPixelToCoords(this->mousePositionWindow);
}

void Game::update() {
	this->pollEvents();
	this->updateMousePosition();
	this->updateEnemies();
}

void Game::render() {
	/*
		- clear the old frame
		- display new frame
		Render the game objects.
	*/
	this->window->clear();
	
	// Draw game 
	this->renderEnemies();

	this->window->display();
}