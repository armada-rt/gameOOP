#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <iostream>
#include "GameWindow.h"
using namespace std;

class Menu {
	private:
		std::string header;
		std::vector<std::string> options;
		int choice;
	public:
		Menu (std::string header, const std::vector<std::string> &options);
		void present();
		void Choice();
		int getChoice();
		void controls();
		~Menu();
};

#endif	// MENU_H