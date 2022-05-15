#include <SFML/Graphics.hpp>
#include "Ship.h"

// note: when I write ship, it means shape, also means body, and vice versa.

Ship::Ship(int radius, int x, int y) {
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
	// setting travel speed
	speed = 4;
}

void Ship::draw(sf::RenderWindow* window) {
	window->draw(*shipBody);


	// WINDOW WRAPPING
	// new x-coord (output x)
	float new_x;
	// new y-coord (output y)
	float new_y;
	// set output x to current x position
	new_x = shipBody->getPosition().x;
	// set output y to current y position
	new_y = shipBody->getPosition().y;
	// if x-coord < 0, set the new x-coord ox to current x-coord + window size
	// i.e. moves from left side of window to right side of window
	if (shipBody->getPosition().x < 0.0f) {new_x = shipBody->getPosition().x + (float)(window->getSize().x);}
	// if x-coord >= size of window, set the new x-coord ox to the current x-coord - window size
	// i.e. move from right side of window to left side of window
	if (shipBody->getPosition().x >= (float)window->getSize().x) {new_x = shipBody->getPosition().x - (float)(window->getSize().x);}
	// if y-coord < 0, set the new y-coord oy to current y-coord + window size
	// i.e. move from top of window to bottom of window
	if (shipBody->getPosition().y < 0.0f) {new_y = shipBody->getPosition().y + (float)(window->getSize().y);}
	// if y-coord is >= window size, set the new y-coord oy to the current y-coord - window size
	// i.e move from bottom of window to top of window
	if (shipBody->getPosition().y >= (float)window->getSize().y) {new_y = shipBody->getPosition().y - (float)(window->getSize().y);}
	// give the new ox and oy to the shipBody position
	shipBody->setPosition(new_x,new_y);

	// // WINDOW ENCLOSEMENT
	// if (shipBody->getPosition().x <= 0.0f) {new_x = 0;}
	// // if x-coord >= size of window, set the new x-coord ox to the current x-coord - window size
	// // i.e. move from right side of window to left side of window
	// if (shipBody->getPosition().x >= (float)window->getSize().x) {new_x = (float)window->getSize().x;}
	// // if y-coord < 0, set the new y-coord oy to current y-coord + window size
	// // i.e. move from top of window to bottom of window
	// if (shipBody->getPosition().y <= 0.0f) {new_y = 0;}
	// // if y-coord is >= window size, set the new y-coord oy to the current y-coord - window size
	// // i.e move from bottom of window to top of window
	// if (shipBody->getPosition().y >= (float)window->getSize().y) {new_y = (float)window->getSize().y;}
	// // give the new ox and oy to the shipBody position
	// shipBody->setPosition(new_x,new_y);

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

void Ship::fire(sf::RenderWindow* window) {
	bullet = new Bullet;
	bullet->draw(window);
	bullet->setPosition(shipBody->getPosition());
	bullet->move();
}

Ship::~Ship() {
	delete this->shipBody;
	delete [] this->bullet;
}