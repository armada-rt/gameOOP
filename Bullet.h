#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include "CommonFunctions.h"
#include <cmath>

class Bullet : public CommonFunctions {
	private:
		// data memeber to tell if bullet is fired or not
		bool fired;
	public:
		// constructor:
		Bullet();
		// move bullet
		void move();
		// check if bullet is fired
		bool isFired();
		// reload
		void reload();
		// use bullet
		void use(sf::Vector2f position);
		// destructor
		~Bullet();
};

#endif // BULLET_H