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
	cosine_angle = cos(angle);
	sine_angle = sin(angle);
}

void Asteroid::spawn(int x, int y) {
	direction();
	// random number chosen. 0 or 1
	axes_spawn_choice = rand() % 2;
	switch (axes_spawn_choice) {
		case 0:
			x_spawn_coord = (float)rand() / x + 1;
			y_spawn_coord = 0;
			cout << "x axis spawn" << x_spawn_coord << " " << y_spawn_coord << endl;
			// spawn on x-axis
			asteroid->setPosition(x_spawn_coord, y_spawn_coord);
			// std::cout << "spawned @ (" << rand_x << "," << axis << ")" << std::endl;
		break;
		case 1:
			y_spawn_coord = (float)rand() / y + 1;
			x_spawn_coord = 0;
			cout << "y axis spawn" << x_spawn_coord << " " << y_spawn_coord << endl;
			// spawn on y-axis
			asteroid->setPosition(x_spawn_coord, y_spawn_coord);
			// std::cout << "spawned @ (" << axis << "," << rand_y << ")" << std::endl;
		break;
	}
	alive = true;
}

void Asteroid::draw(sf::RenderWindow* window) {
	// check if alive
	if (this->alive) {
		asteroid->move(cosine_angle/20, sine_angle/20);
		window->draw(*asteroid);
	
		// window wrapping
		float ox;
		float oy;
		ox = asteroid->getPosition().x;
		oy = asteroid->getPosition().y;
		if (asteroid->getPosition().x < 0.0f) {ox = asteroid->getPosition().x + (float)(window->getSize().x);}
		if (asteroid->getPosition().x >= (float)window->getSize().x) {ox = asteroid->getPosition().x - (float)(window->getSize().x);}
		if (asteroid->getPosition().y < 0.0f) {oy = asteroid->getPosition().y + (float)(window->getSize().y);}
		if (asteroid->getPosition().y >= (float)window->getSize().y) {oy = asteroid->getPosition().y - (float)(window->getSize().y);}

		asteroid->setPosition(ox,oy);

		// ox = ix;
		// oy = iy;
		// if (ix < 0.0f) {
		// 	ox = ix + (float)(window->getSize().x);
		// }
		// if (ix >= (float)window->getSize().x) {
		// 	ox = ix - (float)(window->getSize().x);
		// }
		// if (iy < 0.0f) {
		// 	oy = iy + (float)(window->getSize().y);
		// }
		// if (iy >= (float)window->getSize().y) {
		// 	oy = iy - (float)(window->getSize().y);
		// }
	}
}

Asteroid::~Asteroid() {
	
}