#include "main_menu.h"

main_menu::main_menu(float width, float height)
{
    //where xxxx is the file name eg calibri.ttf
    if (!font.loadFromFile("font01.ttf"))
    {
        cout << "no font is here\n";
    }

    // double check line 18 to ensure it is what u intend it to be 
    // also double check 17 to ensure it is correct font size 

    // play 
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(sf::Color::Yellow);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(70);
    mainMenu[0].setPosition(400,200);

    // how to play 
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(sf::Color::Yellow);
    mainMenu[1].setString("How to play");
    mainMenu[1].setCharacterSize(70);
    mainMenu[1].setPosition(400,200);

    // exist 
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(sf::Color::Yellow);
    mainMenu[2].setString("Exist");
    mainMenu[2].setCharacterSize(70);
    mainMenu[2].setPosition(400,200);

    main_menuSelected = -1;
}

main_menu::~main_menu()
{

}

// draw main menue
void main_menu::draw(RenderWindow& window)
{
    for (int i = 0; i < Max_main_menu; i++)
    {
        window.draw(mainMenu[i]);
    }
}

// move up
void main_menu::MoveUp()
{
    if (main_menuSelected - 1 >= 0)
    {
        mainMenu[main_menuSelected].setFillColor(Color::White);

        main_menuSelected--;
        
        if (main_menuSelected == -1)
        {
            main_menuSelected = 2;
        }

        mainMenu[main_menuSelected].setFillColor(Color::Blue);

    }
}

// move down 
void main_menu::MoveDown()
{
    if (main_menuSelected + 1 <= Max_main_menu)
    {
        mainMenu[main_menuSelected].setFillColor(Color::White);
        main_menuSelected++;

        if(main_menuSelected == 4)
        {
            main_menuSelected == 0;
        }
        mainMenu[main_menuSelected].setFillColor(Color::Blue);
    }
}