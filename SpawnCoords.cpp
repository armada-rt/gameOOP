#include <random>
#include <time.h>
#include <iostream>

using namespace std;

int main() {

	srand(time(0));
	int axes_spawn_choice = rand() % 2;
	float x_spawn_coord;
	float y_spawn_coord;

	// cout << axes_spawn_choice << endl;
	for (int i = 0; i < 500; i++) {
		cout << (float)rand() / (float)(RAND_MAX/800) << endl;
	}

	// switch (axes_spawn_choice) {
	// case 0:
	// 	x_spawn_coord = (float)rand() / (float)(RAND_MAX/800);
	// 	// cout << "x-axis spawn" << endl;
	// 	cout << x_spawn_coord << endl;
	// 	break;
	// case 1:
	// 	// cout << "y-axis spawn" << endl;
	// 	y_spawn_coord = (float)rand() / (float)(RAND_MAX/800);
	// 	cout << y_spawn_coord << endl;
	// 	break;
	// default:
	// 	break;
	// }

	return 0;
}
