# include <sfml/Graphics.hpp>
# include <iostream>
using namespace std;
using namespace sf;

#define Max_main_menu 4

class main_menu
{
    public:
    main_menu(float width, float height);

    void draw(RenderWindow& window);
    void MoveUp();
    void MoveDown();

    int main_menuPressed()
    {
        return main_menuPressed;
    }
    ~main_menu();

    private:
    int main_menuSelected;
    Font font;
    Text mainMenu[Max_main_menu];
};
