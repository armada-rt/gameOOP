#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <iostream>
#include "GameWindow.h"
using namespace std;

class Menu {
	private:
		// string variable for the header of the menu
		std::string header;
		// vector of string for the options given, play, controls, quit
		std::vector<std::string> options;
		// int for navigating around the menu
		int choice;
	public:
		// constructor taking the header/name and list of options
		Menu(std::string header, const std::vector<std::string> &options);
		// void function returning nothign and showing the menu, i.e. the options play, controls, quit
		void present();
		// void fucntion returning nothing and performing various tasks depending on what the user inputs
		void Choice();
		// void function returning nothing that prints the controls when called
		void controls();
		~Menu();
};

#endif	// MENU_H