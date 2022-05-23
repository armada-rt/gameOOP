#include "Menu.h"
#include "GameWindow.h"
#include <iostream>
#include <string>
using namespace std;

Menu::Menu(std::string header, const std::vector<std::string> &options) {
	// set this header to the argument header
	this->header = header;
	// set these option to the options given in the argument
	this->options = options;
}

void Menu::present() {
	// print the header ...
	std::cout << header << std::endl << std::endl;
	 // ... followed by the various options available
	for (int i = 0; i < options.size(); i ++) {
		std::cout << i + 1 << ": " << options[i] << std::endl;
	}
}

void Menu::Choice() {
	// get input from user for choice ... to navigate through menu
	cin >> choice;
	// validating input...
	if (choice == 1) {
		// ... create the game and run it
		GameWindow g(800,"ASTEROIDS", 10, 5);
		g.run();
	} else if (choice == 2) {
		/* ... call various functions to print the controls, show the menu again and get user input
		again for navigation, respsectively */
		controls();
		present();
		Choice();
	} else if (choice == 3) {
		// ... doesnt do anything but continues to run the main function and stops the program... no game is loaded
		cout << "Game Quit" << endl;
	} else {
		// for any other input...
		// ... else, get another input from user
		cout << "enter a valid option: ";
		// clears the previous input
		cin.clear();
		// discards the previous input
		cin.ignore(123,'\n');
		// re-run the function to get another input
		Choice();
	}
}

void Menu::controls() {
	// just print the controls and what they do
	cout << endl << "W: move up" << endl;
	cout << "A: move left" << endl;
	cout << "S: move down" << endl;
	cout << "D: move right" << endl;
	cout << "LEFT CLICK: shoot" << endl;
	cout << "RIGHT CLICK: reload" << endl;
}

Menu::~Menu() {

}