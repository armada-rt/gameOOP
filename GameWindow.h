#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Ship.h"
#include "Asteroid.h"
#include "Collision.h"
using namespace sf;
using namespace std;

// class for the game
class GameWindow : public Collision {
	private:
		// window for the game as pointer
		sf::RenderWindow* window;
		// add ship as data member in class GameWindow
		Ship* ship;
		// add asteroid as data member in class GameWindow
		Asteroid* asteroid;
		int _magSize;
		int _numAsteroids;
		int _lives;
		sf::Text info;
		sf::Font font;
	public:
		// constructor
		GameWindow(int size, string title, int magSize, int numAsteroids);
		void draw_frame();
		// check lives
		void check_lives();
		// function to run the loop
		void run();
		// destructor
		~GameWindow();
};

#endif // WINDOW_H