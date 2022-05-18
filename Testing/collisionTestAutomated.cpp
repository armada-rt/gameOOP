#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Point {
    public:
    int radius = 0;
    float pos_x;
    float pos_y;
    
    Point(int rad, float x, float y) {
        radius = rad;
        pos_x = x;
        pos_y = y;
    }

    void setPos(int i, int j) {
        pos_x = float(i);
        pos_y = float(j);
    }
};

int main () {
    //Intuitive implementation of points for testing purposes
    Point a = Point(3,  0,  0);         //Starts point a in a corner
    Point b = Point(3,  5,  5);         //Starts point b in centre of 11x11 square

    //Loops through a grid of size 11x11; places origin of point A in each grid square and tests if it is colliding with B.
    //We expect a somewhat CIRCULAR shape (!!!)

    //

    for (int i = 0; i < 11; i++) {          //X Coord
        for (int j = 0; j < 11; j++){       //Y Coord
            a.setPos(i,j);
            
            //Implementation of Distance calculator as separate components
            float x_dist = b.pos_x - a.pos_x;
            //cout << x_dist << endl;

            float y_dist = b.pos_y - a.pos_y;
            //cout << y_dist << endl;

            float total_dist = (pow(pow(y_dist,2) + pow(x_dist,2),0.5));
            //cout << total_dist << endl;
            
            if (total_dist < a.radius + b.radius) {
                cout << "X ";
            } else {cout << "O ";}

        }
        cout << endl;
    }
    





}