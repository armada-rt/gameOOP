#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
using namespace sf;
using namespace std;

//Testing method for position to be stored and accessed through vectors

int return_x(Vector2i &list){
    return list.x;
}

int return_y(Vector2i &list){
    return list.y;
}
/*
int main() {
    sf::Vector2i list(4, 7);

    cout << return_x(list) << endl;
    cout << return_y(list) << endl;

    return (0);
}
*/