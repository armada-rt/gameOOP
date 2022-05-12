#include <SFML/Graphics.hpp>
#include "Asteroid.h"
#include <random>
#include <time.h>
#include <iostream>

Asteroid::Asteroid() {
	asteroid = new sf::CircleShape();
	radius = 6;
	asteroid->setRadius(radius);
	// set spawn position
	asteroid->setPosition(-1,-1);
	// set colour of asteroids
	asteroid->setFillColor(sf::Color::White);
	// set centre of asteroid
	asteroid->setOrigin(radius/2, radius/2);
	alive = false;
	// if you don't seed the random number generator, everytime the game is run
	// we will get the same asteroid sequence
	srand(time(0));
}

void Asteroid::direction() {
	// generate number betweeen 0 and 1 and multiply by 2Pi
	angle = 2*M_PI * ((float) rand() / RAND_MAX);
	// get values of cosine and sine
	cosine_angle = cos(angle);
	sine_angle = sin(angle);
}

void Asteroid::spawn(int x, int y) {
	direction();
	// random number chosen. 0 or 1. For switch statement below
	axes_spawn_choice = rand() % 2;
	switch (axes_spawn_choice) {
		// case 0: spawns on the x-axis
		case 0:
			// randomise x-coord between 0 and window size
			x_spawn_coord = (float)rand() / (float)(RAND_MAX/800);
			// set y to 0 since x-axis spawn
			y_spawn_coord = 0;
			// cout << "x axis spawn" << x_spawn_coord << " " << y_spawn_coord << endl;
			// set the spawn coords
			asteroid->setPosition(x_spawn_coord, y_spawn_coord);
			// std::cout << "spawned @ (" << rand_x << "," << axis << ")" << std::endl;
		break;
		// case 1: spawns on the y-axis
		case 1:
			// randomise y-coord between 0 and window size
			y_spawn_coord = (float)rand() / (float)(RAND_MAX/800);
			// set x to 0 since y-axis spawn
			x_spawn_coord = 0;
			// cout << "y axis spawn" << x_spawn_coord << " " << y_spawn_coord << endl;
			// set the spawn coords
			asteroid->setPosition(x_spawn_coord, y_spawn_coord);
			// std::cout << "spawned @ (" << axis << "," << rand_y << ")" << std::endl;
		break;
	}
	alive = true;
}

void Asteroid::draw(sf::RenderWindow* window) {
	// check if alive
	if (this->alive) {
		// setting 
		asteroid->move(cosine_angle/20, sine_angle/20);
		window->draw(*asteroid);
	
		// WINDOW WRAPPING
		// new x-coord (output x)
		float ox;
		// new y-coord (output y)
		float oy;
		// set output x to current x position
		ox = asteroid->getPosition().x;
		// set output y to current y position
		oy = asteroid->getPosition().y;
		// if x-coord < 0, set the new x-coord ox to current x-coord + window size
		// i.e. moves from left side of window to right side of window
		if (asteroid->getPosition().x < 0.0f) {ox = asteroid->getPosition().x + (float)(window->getSize().x);}
		// if x-coord >= size of window, set the new x-coord ox to the current x-coord - window size
		// i.e. move from right side of window to left side of window
		if (asteroid->getPosition().x >= (float)window->getSize().x) {ox = asteroid->getPosition().x - (float)(window->getSize().x);}
		// if y-coord < 0, set the new y-coord oy to current y-coord + window size
		// i.e. move from top of window to bottom of window
		if (asteroid->getPosition().y < 0.0f) {oy = asteroid->getPosition().y + (float)(window->getSize().y);}
		// if y-coord is >= window size, set the new y-coord oy to the current y-coord - window size
		// i.e move from bottom of window to top of window
		if (asteroid->getPosition().y >= (float)window->getSize().y) {oy = asteroid->getPosition().y - (float)(window->getSize().y);}
		// give the new ox and oy to the asteroid position
		asteroid->setPosition(ox,oy);
	}
}

Asteroid::~Asteroid() {
	
}