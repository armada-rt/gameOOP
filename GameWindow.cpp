#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include "Ship.h"
#include <string>
using namespace sf;
using namespace std;


GameWindow::GameWindow(int size, string title) {
	// create an object of RenderWindow and put its address in the variable/data member
	window = new sf::RenderWindow(sf::VideoMode(size, size), title);
	// fill ship pointer with an object
	ship = new Ship(10,400,400, 10);
}

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
				ship->move_up(5);
			} else if (Keyboard::isKeyPressed(Keyboard::S)) {
				// move down
				ship->move_down(5);
			} else if (Keyboard::isKeyPressed(Keyboard::A)) {
				// move left
				ship->move_left(5);
			} else if (Keyboard::isKeyPressed(Keyboard::D)) {
				// move right
				ship->move_right(5);
			}
			// shooting bullet
			if (e.type == sf::Event::MouseButtonPressed) {
				ship->fire();
			}
		}
		// clear
		window->clear();
		ship->draw(window);
		// display
		window->display();
	}
}

GameWindow::~GameWindow() {

}