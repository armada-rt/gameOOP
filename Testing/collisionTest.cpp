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

    Point() {    }
    
    Point(int rad, float x, float y) {
        radius = rad;
        pos_x = x;
        pos_y = y;
    }
};

int main () {
    //Intuitive implementation of points for testing purposes
    Point a = Point(3,  5.5,  5.5);
    Point b = Point(3,  6.5,  5.0);

    //Implementation of Distance calculator
    float x_dist = b.pos_x - a.pos_x;
    cout << x_dist << endl;

    float y_dist = b.pos_y - a.pos_y;
    cout << y_dist << endl;

    float total_dist = (pow(pow(y_dist,2) + pow(x_dist,2),0.5));
    cout << total_dist << endl;

    if (total_dist< a.radius+b.radius) {
        cout << "COLLISION" << endl;
    }

}