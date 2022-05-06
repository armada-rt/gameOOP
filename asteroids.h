#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace sf;
using namespace std;

// class for the game
class asteroids {
	private:
		// window for the game as pointer
		sf::RenderWindow* window;
	public:
		// constructor
		asteroids(int size, string title);
		// function to run the loop
		void run();
		// destructor
		~asteroids();
};

#endif // ASTEROIDS_H