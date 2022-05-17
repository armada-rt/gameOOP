#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Collision.h"
#include <string>
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
	_lives = 3;
	if (!font.loadFromFile("./font01.ttf")) {
		std::cout << "Font not found\n";
		exit(0);
	}
	info.setFont(font);
	info.setFillColor(sf::Color::Red);
	info.setCharacterSize(25);
}

void GameWindow::draw_frame() {
		// for instance, you could have a function that handles the
		// printing on the frame
		std::string msg;
		msg = "LIVES: " + std::to_string(_lives) + " ";
		info.setString(msg);
		window->draw(info);
}

// void GameWindow::check_lives() {
// 	// COLLISION CHECK BETWEEN SHIP & ASTEROID
// 	for (int i = 0; i < _numAsteroids; i++) {
// 		if (asteroid[i].)
// 			if (collisionDetect(ship->get_radius(),ship->get_current_x(),ship->get_current_y(),asteroid[i].get_radius(),asteroid[i].get_current_x(),asteroid[i].get_current_y()) == true) {
// 				_lives--;
// 				asteroid[i].spawn(window);
// 			}
// 	}
// }

// function to run the loop
void GameWindow::run() {
	// check the window is open
	while (window->isOpen()) {
		// if window is open...
		Event e;
		// event loop
		while (window->pollEvent(e)) {
			// check if event of type Closed, then close the window
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
		ship->draw(window);
		for (int i = 0; i < _numAsteroids; i++) {
			asteroid[i].draw(window);
		}
		draw_frame();
		// display
		window->display();
	}
}

GameWindow::~GameWindow() {
	delete ship;
	delete window;
	delete asteroid;
}