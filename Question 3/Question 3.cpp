#include <iostream>
#include <algorithm>
using namespace std;
void controllerMenu();
void display();
void left();
void right();
int arrayMap[10];

int main() {
	bool programRunning = true;
	arrayMap[0] = 1;
	// Command Handling
	while (programRunning == true) {
		int command;
		controllerMenu();
		cin >> command;
		switch (command) {
		case 1:
			right();
			break;
		case 2:
			left();			
			break;
		case 3:
			cout << "Displaying the array map" << endl;
			display();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			cout << "Program is ending";
			programRunning = false;
			break;
		default:
			cout << "Command could not be recognized";
		}
	}


	return 0;
}

void controllerMenu() {
	cout << "Controller Menu: " << endl << "1. Right" << endl << "2. Left" << endl << "3. Display" << endl << "4. Reboot" << endl << "5. Show Array" << endl <<  "6. Exit" << endl;
}

void display() {
	// Empty is 0, Robot 1 is 1, Robot 2 is 2.
	for (int i = 0; i < 21; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << "|";
		if (arrayMap[i] == 1) {
			cout << "^";
		}
		else {
			cout << " ";
		}
	}
	cout << "|" << endl;
	for (int i = 0; i < 21; i++) {
		cout << "-";
	}
	cout << endl;
}

void right() {
	for (int i = 0; i < 10; i++) {
		if (arrayMap[i] == 1) {
			arrayMap[i] = 0;
			if (i + 1 != 10) {
				arrayMap[i + 1] = 1;
			}
			else {
				cout << "Unable to move to the right, out of bounds. " << endl;
			}
		}
	}
}

void left() {
	for (int i = 0; i < 10; i++) {
		if (arrayMap[i] == 1) {
			arrayMap[i] = 0;
			if (i != 0) {
				arrayMap[i - 1] = 1;
			}
			else {
				cout << "Unable to move to the left, out of bounds. " << endl;
			}
		}
	}
}