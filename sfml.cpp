# include <SFML/Graphics.hpp>
# include "main_menu.h"

using namespace sf;

void main()
{
    RenderWindow MENU(VideoMode(900,720),"Main Menu",Style::Default);
    main_menu mainMenu(MENU.getsize().x MENU.getsize().y);

    //background 
    RectangleShape Pbackground;
    Pbackground.setSize(vector2f(960,720));
    Texture Maintexture;
    //WHERE XXXX IS THE NAME OF THE FILE
    Maintexture.loadFromFile("xxxx");
    Pbackground.setTexture(&Maintexture);

    //background how to play
    RectangleShape Obackground;
    Obackground.setSize(vector2f(960,720));
    Texture Optiontexture;
    //WHERE XXXX IS THE NAME OF THE FILE
    Optiontexture.loadFromFile("xxxx");
    Obackground.setTexture(&Optiontexture);


while (MENU.isOpen())
{
    Event event;
    while(MENU.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            MENU.close();
        }
        if (event.type == Event::KeyReleased)
        {
            if (event.key.code == keyboard::up)
            {
                mainMenu.MoveUp();
                break;
            }
            if (event.key.code == keyboard::down)
            {
                mainMenu.MoveDown();
                break;
            }
            if (event.key.code == keyboard::Return)
            {
                RenderWindow Play(VideoMode(960,720),"game_name");
                RenderWindow howtoplay(VideoMode(960,720),"How to play");

                int x == mainMenu.main_menuPressed();
                if (x == 0)
                {
                    while (Play.isOpen())
                    {
                        Event aevent;
                        while (Play.pollEvent(aevent))
                        {
                            if (aevent.type == Event::Closed)
                            {
                                Play.isClose();
                            }
                            if (aevent.type == Event::KeyPressed)
                            {
                                if (aevent.key.code == keyboard::Escape)
                                {
                                    Play.close();
                                }
                            }
                        }
                        play.close();
                        Play.clear();
                        play.draw(background);
                        Play.display();
                    }
                }
                if (x == 1)
                {
                    while (howtoplay.isOpen())
                    {
                        Event aevent;
                        while (howtoplay.pollEvent(aevent))
                        {
                            if (aevent.type == Event::Closed)
                            {
                                howtoplay.Close();
                            }
                            if (aevent.type == Event::KeyPressed)
                            {
                                if (aevent.key.code == Keyboard::Escape)
                                {
                                    howtoplay.close();
                                }
                            }
                        }
                        Play.close();
                        howtoplay.clear();
                        howtoplay.draw(background);
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
    MENU.draw(background);
    mainMenu.draw(MENU);
    MENU.display();
}
}