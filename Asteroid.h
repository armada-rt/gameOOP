#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include "CommonFunctions.h"
using namespace sf;
using namespace std;

// class for the game
class Asteroid : public CommonFunctions {
	private:
		// want to know if asteroid is "dead" or "alive"
		bool alive;
		float angle;
		// spawning x coordinate
		float x_spawn_coord;
		// spawning y coordinate
		float y_spawn_coord;
		// number to choose option. spawn on x or y axis
		int axes_spawn_choice;
		int radius;
	public:
		// constructor
		Asteroid();
		// calculate direction of asteroid
		void direction();
		// returns that it is alive
		bool is_Alive();
		// make alive = false;
		void die();
		// spawn asteroid
		void spawn(sf::RenderWindow* window);
		// draw/spawns asteroids
		void draw(sf::RenderWindow* window);
		~Asteroid();
};

#endif // ASTEROID_H