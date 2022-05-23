#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "CommonFunctions.h"

class Ship : public CommonFunctions {
	private:
		// array of bullets
		Bullet* mag;
		int magSize;
		int speed;
	public:
		// constructor: builds the ship
		Ship(int radius, int x, int y, int aMagSize);
		// function to draw the ship
		void draw(sf::RenderWindow* window);
		// moving ship up
		void move_up();
		// moving ship down
		void move_down();
		// moving ship left
		void move_left();
		// moving ship right
		void move_right();
		// firing bullets
		void fire();
		// reload
		void reload();
		// collision
		bool collision(int target_x, int target_y, int target_radius);
		~Ship();
};

#endif // SHIP_H