#include <iostream>
#include <string>

using namespace std;

void Choice() {
	int choice[91];
	int _choice;
	// get input from user for choice ... to navigate through menu
	for (int i = 0; i < 91; i++) {
		cin >> _choice;
		choice[i] =  _choice;
	}

	// validating input...

	for (int i = 0; i < 91; i++) {
		if (choice[i] == 1) {
			cout << choice[i] << ": choice 1!" << endl;
		} else if (choice[i] == 2) {
			cout << choice[i] << ": choice 2!" << endl;
		} else if (choice[i] == 3) {
			cout << choice[i] << ": choice 3!" << endl;
		} else {
			// for any other input...
			// ... else, get another input from user
			cout << choice[i] << ": Invalid" << endl;
		}
	}
}


int main () {
	
	Choice();

	return 0;
}