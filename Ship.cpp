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

void Ship::move_up(int speed_up) {
	// positive y is down therefore make speed -ve to move up
	shipBody->move(0, -speed_up);
}

void Ship::move_down(int speed_down) {
	// positive y is down therefore make speed +ve to move down
	shipBody->move(0, speed_down);
}

void Ship::move_left(int speed_left) {
	// positive x is right therefore make speed -ve to move left
	shipBody->move(-speed_left, 0);
}

void Ship::move_right(int speed_right) {
	// positive x is right therefore make speed +ve to move right
 	shipBody->move(speed_right, 0);
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

Ship::~Ship() {

}