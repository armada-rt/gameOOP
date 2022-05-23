#include "GameWindow.h"
#include "Ship.h"
#include "Asteroid.h"
#include "CommonFunctions.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

GameWindow::GameWindow(int size, string title, int magSize, int numAsteroids) {
	// create an object of RenderWindow and put its address in the variable/data member
	window = new sf::RenderWindow(sf::VideoMode(size, size), title);
	// fill ship pointer with an object
	ship = new Ship(10,400,400, magSize);
	// having asteroids
	asteroid = new Asteroid[numAsteroids];
	this->_numAsteroids = numAsteroids;
	this->_magSize = magSize;
	// for lives
	_lives = 3.0;
	// having text for live count
	if (!font.loadFromFile("./font01.ttf")) {
		std::cout << "Font not found\n";
		exit(0);
	}
	info.setFont(font);
	info.setFillColor(sf::Color::Red);
	info.setCharacterSize(25);
}

void GameWindow::draw_frame() {
	// draw ship
	ship->draw(window);
	// draw asteroids
	for (int i = 0; i < _numAsteroids; i++) {
		asteroid[i].draw(window);
	}
	// live count
	std::string msg;
	msg = "LIVES: " + std::to_string(_lives) + " ";
	info.setString(msg);
	window->draw(info);
}

void GameWindow::check_lives() {
	// COLLISION CHECK BETWEEN SHIP & ASTEROID
	for (int i = 0; i < _numAsteroids; i++) {
		// as long as the asteroid is "alive"
		if (asteroid[i].is_Alive()){
			// if ship collides with asteroid
			if (asteroid[i].collision(ship->get_current_x(), ship->get_current_y(), ship->get_radius())) {
				// if asteroid collides with the ship, decrease lives by 1
				_lives--;
				// "kill"/destroy the asteroid ...
				asteroid[i].die();
				// ... and  respawn
				asteroid[i].spawn(window);
			}
			// if asteroid collides with ship
			if (ship->collision(asteroid[i].get_current_x(), asteroid[i].get_current_y(), asteroid[i].get_radius())) {
				// if ship bullet hits asteroid, increase lives by 0.2 lives and ...
				_lives = _lives + 0.2;
				// ... "kill"/destroy the asteroid
				asteroid[i].die();
			}
		}
	}
}

void GameWindow::UpdateMousePositions() {
	//Sets the value of mouse position according to the mouse's window location
    this->mousePosWindow = Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);

	ship->get_current_x();
	float distance = 0.0; 

}

// function to run the loop
void GameWindow::run() {
	// check the window is open
	while (window->isOpen()) {
		// if window is open...
		Event e;
		// Event loop

		//Updating Mouse Position
		UpdateMousePositions();

		// Movement Loops
		if (e.type == Event::Closed) {
			window->close();
		}
		// moving the ship:
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			// move up
			ship->move_up();
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			// move down
			ship->move_down();
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			// move left
			ship->move_left();
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			// move right
			ship->move_right();
		}

		while (window->pollEvent(e)) {
			// check if event of type Closed, then close the window
			// shooting bullet
			if (Mouse::isButtonPressed(Mouse::Left)) {
				ship->fire();
			}
			// reloading
			if (Mouse::isButtonPressed(Mouse::Right)) {
				ship->reload();
			}
			// spawn asteroids
			if (Keyboard::isKeyPressed(Keyboard::P)) {
				for (int i = 0; i < _numAsteroids; i++) {
					asteroid[i].spawn(window);
				}
			}
		}
		// clear
		window->clear();
		check_lives();
		// if lives is <= 0 close game
		if (_lives <= 0) {
			break;
		}
		draw_frame();
		// display
		window->display();
	}
}

GameWindow::~GameWindow() {
	delete ship;
	delete window;
	delete [] asteroid;
}