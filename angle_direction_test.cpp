#include <random>
#include <time.h>
#include <iostream>

using namespace std;

int main() {

	srand(time(0));
	float angle;
		angle = 2*M_PI * ((float) rand() / RAND_MAX);
		cout << "angle: " << angle << endl;

	float cosine = cos(angle);
	float sine = sin(angle);

	cout << "cos: " << cosine << endl;
	cout << "sin: " << sine << endl;

	return 0;
}
