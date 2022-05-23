#include <SFML/Graphics.hpp>
#include "Entities.h"
#include <cmath>

void Entities::draw(sf::RenderWindow* window) {
	window->draw(*body);
}

int Entities::get_current_x() {
	return body->getPosition().x;
}

int Entities::get_current_y() {
	return body->getPosition().y;
}

int Entities::get_radius() {
	return _radius;
}

void Entities::set_position(sf::Vector2f position) {
	body->setPosition(position);
}

bool Entities::collision(int target_x, int target_y, int target_radius) {
	// make "hit" false meaning no collision
	bool hit = false;
	// set x to the current x coord
	int x = get_current_x();
	// set y to the current y coord
	int y = get_current_y();
	// maths to find the distance between two objects
	float distance = sqrt((x - target_x)*(x - target_x) + (y - target_y)*(y - target_y));
	// if distance is less than the sum of the radii of the two objects being checked ...
	if (distance < (_radius + target_radius)) {
		// ... "hit" is true meaning they collided
		hit = true;
	}
	return hit;
}