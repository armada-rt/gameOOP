#include <SFML/Graphics.hpp>
#include "Asteroid.h"
#include <random>
#include <time.h>

Asteroid::Asteroid() {
	asteroid = new sf::CircleShape();
	radius = 6;
	asteroid->setRadius(radius);
	// set spawn position
	asteroid->setPosition(-1,-1);
	// set colour of asteroids
	asteroid->setFillColor(sf::Color::White);
	// set centre of asteroid
	asteroid->setOrigin(radius/2, radius/2);
	alive = false;
	// if you don't seed the random number generator, everytime the game is run
	// we will get the same asteroid sequence
	srand(time(0));
}

void Asteroid::spawn(int x, int y) {
	int rand_x = rand() % x + 1;
	int rand_y = rand() % y + 1;
	asteroid->setPosition(rand_x, rand_y);
	alive = true;
}

void Asteroid::draw(sf::RenderWindow* window) {
	// check if alive
	if (this->alive) {
		// offset of x direction every time function is called
		asteroid->move(-0.01,0);
		window->draw(*asteroid);
		// checking if asteroid goes outside of window
		if (asteroid->getPosition().x < 0) {
			// respawn at another random position
			this->spawn(window->getSize().x-10, window->getSize().y);
		}
	}
}

Asteroid::~Asteroid() {
	
}