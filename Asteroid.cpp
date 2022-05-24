#include <SFML/Graphics.hpp>
#include "Asteroid.h"
#include "Entities.h"
#include <random>
#include <time.h>

Asteroid::Asteroid() {
	body = new sf::CircleShape();
	// radius = 6;
	// radius for Entities
	_radius = radius;
	// set radius
	body->setRadius(radius);
	// set spawn position
	body->setPosition(-1,-1);
	// set colour of asteroids
	body->setFillColor(sf::Color::White);
	// set centre of asteroid
	body->setOrigin(radius/2, radius/2);
	// make 'alive' false meaning it hasnt been spawn yet
	alive = false;
	// if you don't seed the random number generator, everytime the game is run we will get the same asteroid sequence
	srand(time(0));
	// Randomises velocities
	velocity = rand() % 3 + 4;

}

void Asteroid::direction() {
	// generate number betweeen 0 and 1 and multiply by 2Pi
	angle = 2*M_PI * ((float) rand() / RAND_MAX);
}

bool Asteroid::is_Alive() {return alive;}

int Asteroid::getState() {return state;}

void Asteroid::die() {alive = false;}

void Asteroid::die(int inputState) {
	state = inputState - 1;
	radius = radius - 10;
	_radius = radius;
	body->setRadius(_radius);
	direction();
	velocity = velocity + 2;
}

void Asteroid::spawn(sf::RenderWindow* window) {
	direction();
	// random number chosen. 0 or 1. For switch statement below
	axes_spawn_choice = rand() % 2;
	switch (axes_spawn_choice) {
		// case 0: spawns on the x-axis
		case 0:
			// randomise x-coord between 0 and window size (see main.cpp for window size but it should be 800)
			x_spawn_coord = (float)rand() / (float)(RAND_MAX/(window->getSize().x));
			// set y to 0 since x-axis spawn
			y_spawn_coord = 0;
			// set the spawn coords
			body->setPosition(x_spawn_coord, y_spawn_coord);
		break;
		// case 1: spawns on the y-axis
		case 1:
			// randomise y-coord between 0 and window size (see main.cpp for window size but it should be 800)
			y_spawn_coord = (float)rand() / (float)(RAND_MAX/(window->getSize().x));
			// set x to 0 since y-axis spawn
			x_spawn_coord = 0;
			// set the spawn coords
			body->setPosition(x_spawn_coord, y_spawn_coord);
		break;
	}
	this->alive = true;
}

void Asteroid::draw(sf::RenderWindow* window) {
	// check if alive
	if (this->alive) {
		// setting 
		body->move(velocity*cos(angle)/40, velocity*sin(angle)/40);
		window->draw(*body);
	
		// WINDOW WRAPPING
		// new x-coord (output x)
		float new_x;
		// new y-coord (output y)
		float new_y;
		// set output x to current x position
		new_x = body->getPosition().x;
		// set output y to current y position
		new_y = body->getPosition().y;
		/* if x-coord < 0, set the new x-coord ox to current x-coord + window size
		i.e. moves from left side of window to right side of window */
		if (body->getPosition().x <= 0.0f) {new_x = body->getPosition().x + (float)(window->getSize().x);}
		/* if x-coord >= size of window, set the new x-coord ox to the current x-coord - window size
		i.e. move from right side of window to left side of window */
		if (body->getPosition().x >= (float)window->getSize().x) {new_x = body->getPosition().x - (float)(window->getSize().x);}
		/* if y-coord < 0, set the new y-coord oy to current y-coord + window size
		i.e. move from top of window to bottom of window */
		if (body->getPosition().y <= 0.0f) {new_y = body->getPosition().y + (float)(window->getSize().y);}
		/* if y-coord is >= window size, set the new y-coord oy to the current y-coord - window size
		i.e move from bottom of window to top of window */
		if (body->getPosition().y >= (float)window->getSize().y) {new_y = body->getPosition().y - (float)(window->getSize().y);}
		// give the new ox and oy to the asteroid position
		body->setPosition(new_x,new_y);
	}
}

Asteroid::~Asteroid() {
	delete body;
}