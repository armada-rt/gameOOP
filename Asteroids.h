#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace sf;
using namespace std;

// class for the game
class Asteroids {
	private:
		// window for the game as pointer
		sf::RenderWindow* window;
	public:
		// constructor
		Asteroids(int size, string title);
		// function to run the loop
		void run();
		// destructor
		~Asteroids();
};

#endif // ASTEROIDS_H