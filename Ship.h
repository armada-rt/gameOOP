#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Entities.h"

class Ship : public Entities {
	private:
		// array of bullets
		Bullet* mag;
		int magSize;
		float speed;
		int countBulletsUsed;
	public:
		// constructor: builds the ship with certain radius, intial spawn position an amount of bullets
		Ship(int radius, int x, int y, int aMagSize);
		// void function returning nothing to draw the ship, taking care of window wrapping as well as bullet firing
		void draw(sf::RenderWindow* window);
		// moving ship up by given offset, returns nothing
		void move_up();
		// moving ship down by given offset, returns nothing
		void move_down();
		// moving ship left by given offset, retuns nothing
		void move_left();
		// moving ship right by given offset, returns nothing
		void move_right();
		// firing bullets, giving the bullet the players position, and the firing direction, and returns nothing
		void fire(sf::Vector2f mousePosition);
		// reloading funtion, returning nothing
		void reload();
		// collision detection, returning boolean variable to check if coolission has occured
		bool collision(int target_x, int target_y, int target_radius);
		~Ship();
};

#endif // SHIP_H