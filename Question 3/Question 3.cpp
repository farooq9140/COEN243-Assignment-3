#include <iostream>
#include <algorithm>
using namespace std;
void controllerMenu();
void display();
int arrayMap[10];

int main() {

	int command;
	controllerMenu();
	cin >> command;

	// Command Handling
	switch (command) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			cout << "Program is ending";
			return 0;
			break;
		default:
			cout << "Command could not be recognized";
	}

	return 0;
}

void controllerMenu() {
	cout << "Controller Menu: " << endl << "1. Right" << endl << " 2. Left" << endl << "3. Display" << endl << "4. Reboot" << endl << "5. Show Array" << endl <<  "6. Exit" << endl;
}

void display() {
	// Empty is 0, Robot 1 is 1, Robot 2 is 2.

}

void right() {
	for (int i = 0; i < 10; i++) {
		if (arrayMap[i] == 1) {
			arrayMap[i] = 0;
			arrayMap[i + 1] = 1;
		}
	}
}

void left() {
	for (int i = 0; i < 10; i++) {
		if (arrayMap[i] == 1) {
			arrayMap[i] = 0;
			arrayMap[i - 1] = 1;
		}
	}
}

void 