#include <SFML/Graphics.hpp>
#include "Ship.h"

// note: when I write ship, it means shape, also means body, and vice versa.

Ship::Ship(int radius, int x, int y, int aMagSize) {
	// create circle shape for the ship
	shipBody = new sf::CircleShape();
	// set the radius of the circle/ship
	shipBody->setRadius(radius);
	// set spawn position
	shipBody->setPosition(x,y);
	// set colour of ship
	shipBody->setFillColor(sf::Color::Cyan);
	// set centre of ship
	shipBody->setOrigin(radius/2, radius/2);
	// set mag size
	magSize = aMagSize;
	// make array of bullets
	mag = new Bullet[10];
	// setting travel speed
	speed = 4;
}

void Ship::draw(sf::RenderWindow* window) {
	window->draw(*shipBody);
	// draw all the bullets
	for (int i = 0; i < magSize; i++) {
		if (mag[i].isFired()) {
			mag[i].move();
			mag[i].draw(window);
		}
	}
}

void Ship::move_up() {
	// positive y is down therefore make speed -ve to move up
	shipBody->move(0, -speed);
}

void Ship::move_down() {
	// positive y is down therefore make speed +ve to move down
	shipBody->move(0, speed);
}

void Ship::move_left() {
	// positive x is right therefore make speed -ve to move left
	shipBody->move(-speed, 0);
}

void Ship::move_right() {
	// positive x is right therefore make speed +ve to move right
 	shipBody->move(speed, 0);
}

void Ship::fire() {
	for (int i = 0; i < magSize; i++) {
		// if first bullet is not fired, then use that one
		if (!mag[i].isFired()) {
			mag[i].use(shipBody->getPosition());
			break;
		}
	}
}

void Ship::reload() {
	// iterating over all the bullets
	for (int i = 0; i < magSize; i++) {
		// if bullet is fired
		if (mag[i].isFired()) {
			// call reload on it
			mag[i].reload();
		}
	}
}

Ship::~Ship() {
	delete this->shipBody;
	delete [] this->mag;
}