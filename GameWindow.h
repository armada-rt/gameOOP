#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "Asteroid.h"
using namespace sf;

// class for the game
class GameWindow {
	private:
		// window for the game as pointer
		sf::RenderWindow* window;
		// add ship as data member in class GameWindow
		Ship* ship;
		// add asteroid as data member in class GameWindow
		Asteroid* asteroid;
		// mag size
		int _magSize;
		// number of asteroids
		int _numAsteroids;
		// number of lives
		float _lives;
		float _score;
		// things for text for live count
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