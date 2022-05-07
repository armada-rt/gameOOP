#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
	private:
		sf::RectangleShape* bullet;
		// data memeber to tell if bullet is fired or not
		bool fired;
	public:
		// constructor:
		Bullet();
		// drawing bullet
		void draw(sf::RenderWindow* window);
		// set position
		void setPosition(sf::Vector2f position);
		// move bullet
		void move();
		// check if bullet is fired
		bool isFired();
		// use bullet
		void use(sf::Vector2f position);
		// destructor
		~Bullet();
};

#endif // BULLET_H