#include <SFML/Graphics.hpp>
#include "Ship.h"

Ship::Ship(int radius, int x, int y, int aMagSize) {
	// create circle shape for the ship
	body = new sf::CircleShape();
	// set the radius of the circle/ship
	body->setRadius(radius);
	// set spawn position
	body->setPosition(x,y);
	// set colour of ship
	body->setFillColor(sf::Color::Cyan);
	// set centre of ship
	body->setOrigin(radius/2, radius/2);
	// set mag size
	magSize = aMagSize;
	// make array of bullets
	mag = new Bullet[magSize];
	// setting travel speed
	speed = 0.1;
	// _radius for collision
	_radius = radius;
	// sets intial bullets used to 0
	countBulletsUsed = 0;
}

void Ship::draw(sf::RenderWindow* window) {
	window->draw(*body);
	// draw all the bullets
	for (int i = 0; i < magSize; i++) {
		// if bullet is fired ...
		if (mag[i].isFired()) {
			// move the bullet in the direction
			mag[i].move();
			// draw the bullet
			mag[i].draw(window);
		}
	}

	// WINDOW WRAPPING
	// new x-coord (output x)
	float new_x;
	// new y-coord (output y)
	float new_y;
	// set output x to current x position
	new_x = body->getPosition().x;
	// set output y to current y position
	new_y = body->getPosition().y;
	/* if x-coord < 0, set the new x-coord ox to current x-coord + window size
	i.e. moves from left side of window to right side of window */
	if (body->getPosition().x < 0.0f) {new_x = body->getPosition().x + (float)(window->getSize().x);}
	/* if x-coord >= size of window, set the new x-coord ox to the current x-coord - window size
	i.e. move from right side of window to left side of window */
	if (body->getPosition().x >= (float)window->getSize().x) {new_x = body->getPosition().x - (float)(window->getSize().x);}
	/* if y-coord < 0, set the new y-coord oy to current y-coord + window size
	i.e. move from top of window to bottom of window */
	if (body->getPosition().y < 0.0f) {new_y = body->getPosition().y + (float)(window->getSize().y);}
	/* if y-coord is >= window size, set the new y-coord oy to the current y-coord - window size
	i.e move from bottom of window to top of window */
	if (body->getPosition().y >= (float)window->getSize().y) {new_y = body->getPosition().y - (float)(window->getSize().y);}
	// give the new ox and oy to the shipBody position
	body->setPosition(new_x,new_y);
}

void Ship::move_up() {
	// positive y is down therefore make speed -ve to move up
	body->move(0, -speed);
}

void Ship::move_down() {
	// positive y is down therefore make speed +ve to move down
	body->move(0, speed);
}

void Ship::move_left() {
	// positive x is right therefore make speed -ve to move left
	body->move(-speed, 0);
}

void Ship::move_right() {
	// positive x is right therefore make speed +ve to move right
 	body->move(speed, 0);
}

void Ship::fire() {
	for (int i = 0; i < magSize; i++) {
		// if first bullet is not fired, then use that one
		if (!mag[i].isFired()) {
			mag[i].use(body->getPosition());
			// keeps track of how many bullets have been used
			countBulletsUsed++;
			break;
		}
	}
}

void Ship::reload() {
	// only if you have used all the bullets can you reloads
	if (countBulletsUsed == magSize) {
		// reset count of bullets used since now none of them have been used
		countBulletsUsed = 0;
		// iterating over all the bullets
		for (int i = 0; i < magSize; i++) {
			// if bullet is fired
			if (mag[i].isFired()) {
				// call reload on it
				mag[i].reload();
			}
		}
	}
}

bool Ship::collision(int target_x, int target_y, int target_radius) {
	// make "hit" false meaning not collision
	bool hit = false;
	// go through each bullet
	for (int i = 0; i < magSize; i++) {
		// if bullet is fired ...
		if (mag[i].isFired()) {
			// if bullet colldies with "target"/asteroid ...
			if (mag[i].collision(target_x, target_y, target_radius)) {
				// make "hit" true meaning is colliding
				hit = true;
				return hit;
			}
		}
	}
	return hit;
}

Ship::~Ship() {
	delete this->body;
	delete [] this->mag;
}