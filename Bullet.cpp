#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Entities.h"
#include <string>
#include <cmath>
using namespace sf;
using namespace std;

Bullet::Bullet() {
	int radius;
	// bullet shape made circular
	body = new sf::CircleShape();
	// set radius
	radius = 2.5;
	// _radius for collision
	_radius = radius;
	// set radius
	body->setRadius(radius);
	// set spawn position, set position to initially be offscreen
	body->setPosition(-1,-1);
	// set colour of bullet
	body->setFillColor(sf::Color::Red);
	// set centre of bullet
	body->setOrigin(radius/2, radius/2);
	// make fired false since it hasn't been used yet
	fired = false;
}

void Bullet::move() {
	// offsets x value by 0.5 every time the function is called
	body->move(0.35,0);
}

bool Bullet::isFired() {return fired;}

void Bullet::reload() {
	// set fire to false so we can use it through the use() function below
	fired = false;
}

void Bullet::use(sf::Vector2f position) {
	// set position to the position of the player
	body->setPosition(position);
	// changes to true since the bullet is now fired
	fired = true;
}

Bullet::~Bullet() {
	delete this->body;
}