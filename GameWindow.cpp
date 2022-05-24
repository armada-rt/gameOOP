#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Entities.h"
#include <string>
#include <iostream>
using namespace sf;

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
	// intialising number of asteroids destroyed, obviously to 0
	countAsteroidsDestroyed = 0;
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
				// increases number of asteroids destroyed by 1
				countAsteroidsDestroyed++;
				// ... "kill"/destroy the asteroid
				if (asteroid[i].getState() != 1) {
					asteroid[i].die(asteroid[i].getState());
				} else {
					asteroid[i].die();
				}
			}
		}
	}
}

// function to run the loop
void GameWindow::run() {
	// check the window is open
	while (window->isOpen()) {
		// if window is open...
		Event e;
		// updating mouse position
		UpdateMousePositions();
		// SHIP MOVEMENT:
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
		// spawn asteroids
		if (spawn == false) {
			spawn = true;
			for (int i = 0; i < _numAsteroids; i++) {
				asteroid[i].spawn(window);
			}
		}
		// event loop
		while (window->pollEvent(e)) {
			// check if event of type Closed, then close the window
			if (e.type == Event::Closed) {
				window->close();
			}
			// shooting bullet
			if (Mouse::isButtonPressed(Mouse::Left)) {
				ship->fire(mousePos());
			}
			// reloading
			if (Mouse::isButtonPressed(Mouse::Right)) {
				ship->reload();
			}
		}
		// clear
		window->clear();
		check_lives();
		// if lives is <= 0 close game
		if (_lives <= 0) {
			cout << "GAME OVER" << endl;
			break;
		}
		if (countAsteroidsDestroyed == 3*_numAsteroids) {
			cout << "CONGRATULATIONS! YOU HAVE WON" << endl;
			break;
		}
		draw_frame();
		// display
		window->display();
	}
}

void GameWindow::UpdateMousePositions() {
	// Sets the value of mouse position according to the mouse's window location
    this->mousePosWindow = Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

Vector2f GameWindow::mousePos() {return mousePosView;}

GameWindow::~GameWindow() {
	delete ship;
	delete window;
	delete [] asteroid;
}