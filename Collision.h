#ifndef COLLISION_H
#define COLLISION_H

#include <iostream>
#include <math.h>
using namespace std;

class Collision {
    public:
        static bool collisionDetect(int r1, int x1, int y1, int r2, int x2, int y2);
};

#endif // COLLISION_H