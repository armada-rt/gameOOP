#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <string>
using namespace sf;
using namespace std;

Bullet::Bullet() {
	// bullet shape made rectangular with length 10 and width 5
	bullet = new sf::RectangleShape(sf::Vector2f(10,5));
	// set colour
	bullet->setFillColor(sf::Color::Red);
	// set position to initially be offscreen
	bullet->setPosition(-1,-1);
	// for new bullet, initialise fired to false since it hasnt been used yet
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
	bullet->move(0.5,0);
}

bool Bullet::isFired() {return fired;}

void Bullet::use(sf::Vector2f position) {
	// set position to the position of the player
	bullet->setPosition(position);
	// changes to true since the bullet is now fired
	fired = true;
}

Bullet::~Bullet() {

}