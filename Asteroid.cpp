#include <SFML/Graphics.hpp>
#include "Asteroid.h"
#include <random>
#include <time.h>
#include <iostream>

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
	directionChoice = rand() % 23 + 1;
	alive = true;
}

void Asteroid::draw(sf::RenderWindow* window) {
	// check if alive
	if (this->alive) {
		// int directionChoice;
		// directionChoice = rand() % 23 + 1;
		std::cout << "case: " << directionChoice << std::endl;
		switch (directionChoice) {
			// offsets of x and y directions every time function is called
			// should be chosen at random
			case 0: /* 0 deg */
				asteroid->move(0.1, 0);
				window->draw(*asteroid);
				break;
			case 1: /* 15 deg */
				asteroid->move(0.0966, 0.0259);
				window->draw(*asteroid);
				break;
			case 2: /* 30 deg */
				asteroid->move(0.0866, 0.0500);
				window->draw(*asteroid);
				break;
			case 3: /* 45 deg */
				asteroid->move(0.0707, 0.0707);
				window->draw(*asteroid);
				break;
			case 4: /* 60 deg */
				asteroid->move(0.0500, 0.0866);
				window->draw(*asteroid);
				break;
			case 5: /* 75 deg */
				asteroid->move(0.0259, 0.0966);
				window->draw(*asteroid);
				break;
			case 6: /* 90 deg */
				asteroid->move(0, 0.1);
				window->draw(*asteroid);
				break;
			case 7: /* 105 deg */
				asteroid->move(-0.0259, 0.0966);
				window->draw(*asteroid);
				break;
			case 8: /* 120 deg */
				asteroid->move(-0.0500, 0.0866);
				window->draw(*asteroid);
				break;
			case 9: /* 135 deg */
				asteroid->move(-0.0707, 0.0707);
				window->draw(*asteroid);
				break;
			case 10: /* 150 deg */
				asteroid->move(-0.0866, 0.0500);
				window->draw(*asteroid);
				break;
			case 11: /* 165 deg */
				asteroid->move(-0.0966, 0.0259);
				window->draw(*asteroid);
				break;
			case 12: /* 180 deg */
				asteroid->move(-0.1, 0);
				window->draw(*asteroid);
				break;
			case 13: /* 195 deg */
				asteroid->move(-0.0966, -0.0259);
				window->draw(*asteroid);
				break;
			case 14: /* 210 deg */
				asteroid->move(-0.0866, -0.0500);
				window->draw(*asteroid);
				break;
			case 15: /* 225 deg */
				asteroid->move(-0.0707, -0.0707);
				window->draw(*asteroid);
				break;
			case 16: /* 240 deg */
				asteroid->move(-0.0500, -0.0866);
				window->draw(*asteroid);
				break;
			case 17: /* 255 deg */
				asteroid->move(-0.0259, -0.0966);
				window->draw(*asteroid);
				break;
			case 18: /* 270 deg */
				asteroid->move(0, -0.1);
				window->draw(*asteroid);
				break;
			case 19: /* 285 deg */
				asteroid->move(0.0259, -0.0966);
				window->draw(*asteroid);
				break;
			case 20: /* 300 deg */
				asteroid->move(0.0500, -0.0866);
				window->draw(*asteroid);
				break;
			case 21: /* 315 deg */
				asteroid->move(0.0707, -0.0707);
				window->draw(*asteroid);
				break;
			case 22: /* 330 deg */
				asteroid->move(0.0866, -0.0500);
				window->draw(*asteroid);
				break;
			case 23: /* 345 deg */
				asteroid->move(0.0966, -0.0259);
				window->draw(*asteroid);
				break;
			// default:
			// 	break;
		}
		// offset of x direction every time function is called
		// asteroid->move(-0.01, 0.01);
		// CHANGE THE ABOVE TO MOVE IN A SING RANDOM DIRECTION
		// MAYBE USE UNIT CIRCLE AND THE FOLLOWING ANGLES AS DIRECTIONS
		// 0,15,30,45,60,75,90.... ALL THE WAY TO 360.
		// window->draw(*asteroid);
		// checking if asteroid goes outside of window
		if (asteroid->getPosition().x < 0) {
			// respawn at another random position
			this->spawn(window->getSize().x, window->getSize().y);
		} else if (asteroid->getPosition().x > 800) {
			this->spawn(window->getSize().x, window->getSize().y);
		} else if (asteroid->getPosition().y > 800) {
			this->spawn(window->getSize().x, window->getSize().y);
		} else if (asteroid->getPosition().y < 0) {
			this->spawn(window->getSize().x, window->getSize().y);
		}
	}
}

Asteroid::~Asteroid() {
	
}