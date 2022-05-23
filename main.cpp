// ASTEROIDS
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include "Menu.h"


int main() {

	// making a menu object with name/header MENU and options 
	Menu firstMenu("MENU", {"Play", "Controls", "Quit"});
	firstMenu.present();
	firstMenu.Choice();

	return 0;
}