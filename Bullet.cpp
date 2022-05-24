#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Entities.h"
#include <string>
#include <cmath>
using namespace sf;
using namespace std;

Bullet::Bullet() {
	// bullet shape made circular
	body = new sf::CircleShape();

	// _radius for collision and size
	int radius = 2.5;
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
	// travels a distance of 1 in provided direction (using direction vector) every time the function is called
	body->move(1*fire_dir.x,1*fire_dir.y);
}

bool Bullet::isFired() {return fired;}

void Bullet::reload() {
	// set fire to false so we can use it through the use() function below
	fired = false;
}

void Bullet::use(sf::Vector2f shipPos,sf::Vector2f mousePos) {
	// set position to the position of the player
	body->setPosition(shipPos);
	// changes to true since the bullet is now fired
	fired = true;

	// calculates distance between mousePos and shipPos
	float dist_x = mousePos.x - shipPos.x;
	float dist_y = mousePos.y - shipPos.y;
	float distance = sqrt(dist_x*dist_x + dist_y*dist_y);
	
	// normalising 
	fire_dir.x = dist_x/distance;
	fire_dir.y = dist_y/distance;

}

Bullet::~Bullet() {
	delete this->body;
}