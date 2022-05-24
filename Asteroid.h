#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include "Entities.h"
using namespace sf;
using namespace std;

class Asteroid : public Entities {
	private:
		// bool variable to keep track of whether the asteroid is "dead" or "alive"
		bool alive;
		// variable to hold the angle at which the asteroid is travelling
		float angle;
		// variable for the spawning x coordinate
		float x_spawn_coord;
		// variable for the spawning y coordinate
		float y_spawn_coord;
		// number to choose option. spawn on x or y axis
		int axes_spawn_choice;
		// variable to hold the radius of the asteroid
		int radius = 24;

		// variable to determine which asteroid TYPE it is; values 1-3 where 3 is large and 1 is smallest
		int state = 3;
		// speed of asteroid
		float velocity = 5;


	public:
		// constructor
		Asteroid();
		// OVERRIDDEN constructor for asteroids spawned due to destruction:
		Asteroid(int state);

		/* void function returning nothing, calculates a random number between 0 and 2Pi storing it in 'angle' and returns nothing */
		void direction();
		// boolean function returns the variable 'alive' as true
		bool is_Alive();
		// void function returning nothing and making 'alive' as false;
		void die();
		
		/* void function returning nothing but choosing a random spawn axis and randomising the necessary coordinates, as well
		as setting the spawn position of the asteroid */
		void spawn(sf::RenderWindow* window);

		//OVERRIDEN version 

		/* void function returning nothing, but draws the asteroid and moves it with certain offset depending on 'angle' as well 
		as controlling the window wrap for all the asteroids */
		void draw(sf::RenderWindow* window);
		~Asteroid();
};

#endif // ASTEROID_H