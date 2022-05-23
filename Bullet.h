#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include "Entities.h"
#include <cmath>

class Bullet : public Entities {
	private:
		// data memeber to tell if bullet is fired or not
		bool fired;
		sf::Vector2f fire_dir;
	public:
		// constructor
		Bullet();
		// void function returning nothing and move bullet by a given offset
		void move();
		// retruns boolean varibale 'fired' = true since the bullet has now being used
		bool isFired();
		// void function returning nothing and simply makes 'fired' = false so that the bullet may be used again
		void reload();
		/* void function returning nothing. Sets the position to the position at which the body is at time of
		execution and make 'fired' = true since the bullet has no been used */
		void use(sf::Vector2f shipPosition, sf::Vector2f mousePos);
		// destructor
		~Bullet();
};

#endif // BULLET_H