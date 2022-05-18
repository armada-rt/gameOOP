#include <SFML/Graphics.hpp>
#include "CommonFunctions.h"
#include <cmath>

void CommonFunctions::draw(sf::RenderWindow* window) {
	window->draw(*body);
}

int CommonFunctions::get_current_x() {
	return body->getPosition().x;
}

int CommonFunctions::get_current_y() {
	return body->getPosition().y;
}

int CommonFunctions::get_radius() {
	return _radius;
}

void CommonFunctions::set_position(sf::Vector2f position) {
	body->setPosition(position);
}

bool CommonFunctions::collision(int target_x, int target_y, int target_radius) {
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
		// "hit" si true meaning they collided
		hit = true;
	}
	return hit;
}