#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace sf;
using namespace std;

// class for the game
class Asteroid {
	private:
		// shape of asteroid as circle for simplicity
		sf::CircleShape* asteroid;
		// want to know if asteroid is "dead" or "alive"
		bool alive;
		int directionChoice;
		int radius;
	public:
		// constructor
		Asteroid();
		// spawn asteroid
		void spawn(int x, int y);
		// draw/spawns asteroids
		void draw(sf::RenderWindow* window);
		~Asteroid();
};

#endif // ASTEROID_H