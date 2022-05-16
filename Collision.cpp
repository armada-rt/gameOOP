#include <SFML/Graphics.hpp>
#include "Collision.h"

bool Collision::collisionDetect(int r1, int x1, int y1, int r2, int x2, int y2) {
	if (sqrt((x2 - x1)^2 + (y2 - y1)^2) < r1 + r2) {
		// cout << "collision detected" << endl;
		return true;
	}
	return false;
}