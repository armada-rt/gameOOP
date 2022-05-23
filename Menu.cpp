#include "Menu.h"
#include "GameWindow.h"
#include <iostream>
#include <string>
using namespace std;

Menu::Menu(std::string header, const std::vector<std::string> &options) {
	this->header = header;
	this->options = options;
}

void Menu::present() {
	std::cout << header << std::endl << std::endl;
	for (int i = 0; i < options.size(); i ++) {
		std::cout << i + 1 << ": " << options[i] << std::endl;
	}
}

void Menu::Choice() {
	cin >> choice;
	// validating input... if choice is 1, 2 or 3, run as normal ...
	if (choice == 1) {
		GameWindow g(800,"ASTEROIDS", 10, 5);
		g.run();
	} else if (choice == 2) {
		controls();
		present();
		Choice();
	} else if (choice == 3) {
		cout << "Game Quit" << endl;
	} else {
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

int Menu::getChoice() {return choice;}

void Menu::controls() {
	cout << endl << "W: move up" << endl;
	cout << "A: move left" << endl;
	cout << "S: move down" << endl;
	cout << "D: move right" << endl;
	cout << "LEFT CLICK: shoot" << endl;
	cout << "RIGHT CLICK: reload" << endl;
}

Menu::~Menu() {

}