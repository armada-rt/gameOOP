// ASTEROIDS
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include "Menu.h"


int main() {

	// making a menu object with name/header MENU and options 
	Menu firstMenu("MENU", {"Play", "Controls", "Quit"});
	// showing the menu and allowign for user input for selections
	firstMenu.present();
	firstMenu.Choice();

	return 0;
}