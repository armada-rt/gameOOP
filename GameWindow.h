#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "Asteroid.h"
using namespace sf;

class GameWindow {
	private:
		// window for the game as pointer
		sf::RenderWindow* window;
		// add ship as data member in class GameWindow
		Ship* ship;
		// add asteroid as data member in class GameWindow
		Asteroid* asteroid;
		// mag size (how many bullets you have before you have to reload)
		int _magSize;
		// number of asteroids (... that will spawn)
		int _numAsteroids;
		// number of lives (... that the player has)
		float _lives;
		// to check if asteroids have been spawned yet or not
		bool spawn = false;
		// variable for the position of the mouse relative to the window
		Vector2i mousePosWindow;
		Vector2f mousePosView;
		// count to keep track of how many asteroids have been destroyed
		int countAsteroidsDestroyed;
		// things for text for live count
		sf::Text info;
		sf::Font font;
	public:
		/* constructor. Takes in the window size, title, nubmer of bullets given to the player, and number
		of asteroids that will be spawned */
		GameWindow(int size, string title, int magSize, int numAsteroids);
		// draws the frame of the game without returning anything
		void draw_frame();
		// vodi function returning nothing that goes throuhg the collision detection
		void check_lives();
		// function to run the loop while returning nothing
		void run();
		/* function returning nothing, updates the mouse position setting the mouse position according
		to the position in the window */
		void UpdateMousePositions();
		// function to return the position of the mouse as a float vector
		Vector2f mousePos();

		// destructor
		~GameWindow();
};

#endif // GAMEWINDOW_H