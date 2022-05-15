#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"

// note: when I write ship, it means shape, also means body, and vice versa.

class Ship {
	private:
		sf::CircleShape* shipBody;
		// array of bullets
		Bullet* bullet;
		int speed;
	public:
		// constructor: builds the ship
		Ship(int radius, int x, int y);
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
		void fire(sf::RenderWindow* window);
		// reload
		void reload();
		~Ship();
};

#endif // SHIP_H