#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;



int main () {

// current positions
float currentx;
float currenty;
// new positions
float newx;
float newy;
// set output to current positions
currentx = 0;
// currentx1 = 800;
currenty = 0;
// currenty1 = 800;
newx = currentx;
newy = currenty;

	// if x-coord < 0, set the new x-coord ox to current x-coord + window size
	// i.e. moves from left side of window to right side of window
	if (currentx <= 0.0f) {newx = currentx + (float)(800);}


	// if x-coord >= size of window, set the new x-coord ox to the current x-coord - window size
	// i.e. move from right side of window to left side of window	
	if (currentx >= (float)(800)) {newx = currentx - (float)(800);}
	
	
	// if y-coord < 0, set the new y-coord oy to current y-coord + window size
	// i.e. move from top of window to bottom of window
	if (currenty <= 0.0f) {newy = currenty + (float)(800);}
	
	
	// if y-coord is >= window size, set the new y-coord oy to the current y-coord - window size
	// i.e move from bottom of window to top of window
	if (currenty >= (float)(800)) {newy = currenty - (float)(800);}
	// give the new ox and oy to the asteroid position

	currentx = newx;
	currenty = newy;

	cout << "Expected: (" << 800 << "," << 800 << ")" << endl;
	cout << "Result: (" << currentx << "," << currenty << ")" << endl;

	return 0;
}