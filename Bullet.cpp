#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <string>
using namespace sf;
using namespace std;

Bullet::Bullet() {
	// bullet shape made circular
	bullet = new sf::CircleShape();
	radius = 2.5;
	bullet->setRadius(radius);
	// set spawn position, set position to initially be offscreen
	bullet->setPosition(-1,-1);
	// set colour of bullet
	bullet->setFillColor(sf::Color::Red);
	// set centre of bullet
	bullet->setOrigin(radius/2, radius/2);
	fired = false;
}

void Bullet::draw(sf::RenderWindow* window) {
	window->draw(*bullet);
}

void Bullet::setPosition(sf::Vector2f position) {
	bullet->setPosition(position);
}

void Bullet::move() {
	// offsets x value by 0.5 every time the function is called
	bullet->move(0.20,0);
}

bool Bullet::isFired() {return fired;}

void Bullet::reload() {
	// set fire to false so we can use it through the use() function below
	fired = false;
}

void Bullet::use(sf::Vector2f position) {
	// set position to the position of the player
	bullet->setPosition(position);
	// changes to true since the bullet is now fired
	fired = true;
}

Bullet::~Bullet() {
	delete this->bullet;
}