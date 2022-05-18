#ifndef COMMONFUNCTIONS_H
#define COMMONFUNCTIONS_H

#include <SFML/Graphics.hpp>
#include <cmath>

class CommonFunctions {
	protected:
		// same body for all things in the game
		sf::CircleShape* body;
		// _radius used in collision
		int _radius;
	public:
		// drawing in the window
		void draw(sf::RenderWindow* window);
		// returns x
		int get_current_x();
		// returns y
		int get_current_y();
		// returns radius
		int get_radius();
		// sets position
		void set_position(sf::Vector2f position);
		// collision check
		bool collision(int target_x, int target_y, int target_radius);
};

#endif // SHIP_H