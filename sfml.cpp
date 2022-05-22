#include <SFML/Graphics.hpp>
#include "main_menu.h"

using namespace sf;

int main() {
    RenderWindow MENU(VideoMode(900,720),"Main Menu",Style::Default);
    main_menu mainMenu(MENU.getSize().x, MENU.getSize().y);

    //background 
    RectangleShape Pbackground;
    Pbackground.setSize(Vector2f(960,720));
    Texture Maintexture;
    //WHERE XXXX IS THE NAME OF THE FILE
    Maintexture.loadFromFile("XXXX");
    Pbackground.setTexture(&Maintexture);

    //background how to play
    RectangleShape Obackground;
    Obackground.setSize(Vector2f(960,720));
    Texture Optiontexture;
    //WHERE XXXX IS THE NAME OF THE FILE
    Optiontexture.loadFromFile("XXXX");
    Obackground.setTexture(&Optiontexture);
    
    while (MENU.isOpen()) {
        Event event;
        while(MENU.pollEvent(event)) {
            if (event.type == Event::Closed) {
                MENU.close();
            }
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::isKeyPressed(Keyboard::Up)) {
                    mainMenu.MoveUp();
                    break;
                }
                if (event.key.code == Keyboard::isKeyPressed(Keyboard::Down)) {
                    mainMenu.MoveDown();
                    break;
                }
                if (event.key.code == Keyboard::isKeyPressed(Keyboard::Return)) {
                    RenderWindow Play(VideoMode(960,720),"game_name");
                    RenderWindow howtoplay(VideoMode(960,720),"How to play");

                    int x = mainMenu.main_menuPressed();
                    if (x == 0) {
                        while (Play.isOpen()) {
                            Event aevent;
                            while (Play.pollEvent(aevent)) {
                                if (aevent.type == Event::Closed) {
                                    Play.close();
                                }
                                if (aevent.type == Event::KeyPressed) {
                                    if (aevent.key.code == Keyboard::isKeyPressed(Keyboard::Escape)) {
                                        Play.close();
                                    }
                                }
                            }
                            Play.close();
                            Play.clear();
                            Play.draw(Pbackground);
                            Play.display();
                        }
                    }
                    if (x == 1) {
                        while (howtoplay.isOpen()) {
                            Event aevent;
                            while (howtoplay.pollEvent(aevent)) {
                                if (aevent.type == Event::Closed) {
                                    howtoplay.close();
                                }
                                if (aevent.type == Event::KeyPressed) {
                                    if (aevent.key.code == Keyboard::Escape) {
                                        howtoplay.close();
                                    }
                                }
                            }
                            Play.close();
                            howtoplay.clear();
                            howtoplay.draw(Obackground);
                            howtoplay.display();
                        }
                    }
                    if ( x == 2)
                        MENU.close();
                        break;
                }
            }
        }
        MENU.clear();
        MENU.draw(Obackground);
        mainMenu.draw(MENU);
        MENU.display();
    }

    return 0;
}