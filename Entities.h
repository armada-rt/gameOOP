#ifndef ENTITIES_H
#define ENTITIES_H

#include <SFML/Graphics.hpp>
#include <cmath>

/* Entities has common functions (known as entities) used by multiple objects with similar
or the same fucntionality */
class Entities {
	protected:
		// same body for all things in the game
		sf::CircleShape* body;
		// _radius used in collision
		int _radius;
	public:
		// void function returning nothing and drawing the object in the window
		void draw(sf::RenderWindow* window);
		// function returning the integer value of the current x coordinate
		int get_current_x();
		// function returning the integer value of the current y coordinate
		int get_current_y();
		// function returning an integer value of the radius of the object
		int get_radius();
		// void function returning nothing and setting the position of an object
		void set_position(sf::Vector2f position);
		/* function returning a boolean to check if a coolision has occured. IF return is true then collision
		has occured and false for no collision */
		bool collision(int target_x, int target_y, int target_radius);
};

#endif // ENTITIES_H