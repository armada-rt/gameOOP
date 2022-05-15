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
	// set colour of bullet
	bullet->setFillColor(sf::Color::Red);
	// set centre of bullet
	bullet->setOrigin(radius/2, radius/2);
	bullet->setPosition(10,10);
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


Bullet::~Bullet() {
	delete this->bullet;
}