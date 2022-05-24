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
	/* offsetes position by a distance of 1 in the provided direction (usign direction vector)
	every time the function is called */
	body->move(0.3*fire_dir.x,0.3*fire_dir.y);
}

bool Bullet::isFired() {return fired;}

void Bullet::reload() {
	// set fire to false so we can use it through the use() function below
	fired = false;
}

void Bullet::use(sf::Vector2f shipPosition, sf::Vector2f mousePosition) {
	// set position to the position of the player
	body->setPosition(shipPosition);
	// changes to true since the bullet is now fired
	fired = true;
	// calculating distance in the x direction between mousePosition and shipPosition
	float dist_x = mousePosition.x - shipPosition.x;
	// calculating distance in the y direction between mousePosition and shipPosition
	float dist_y = mousePosition.y - shipPosition.y;
	// total distance (resultant vector V from V_x and V_y)
	float distance = sqrt(dist_x*dist_x + dist_y*dist_y);
	
	// normalising
	fire_dir.x = dist_x/distance;
	fire_dir.y = dist_y/distance;
}

Bullet::~Bullet() {
	delete this->body;
}