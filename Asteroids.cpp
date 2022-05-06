#include <SFML/Graphics.hpp>
#include "Asteroids.h"
#include <string>
using namespace sf;
using namespace std;


Asteroids::Asteroids(int size, string title) {
	// create an object of RenderWindow and put its address in the variable/data member
	window = new sf::RenderWindow(sf::VideoMode(size,size),title);
}
// function to run the loop
void Asteroids::run() {
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
		}
		// clear
		window->clear();
		// display
		window->display();
	}
}
Asteroids::~Asteroids() {

}