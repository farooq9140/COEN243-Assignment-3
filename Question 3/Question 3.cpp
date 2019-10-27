#include <iostream>
#include <algorithm>
using namespace std;
void controllerMenu();
void display();
void left(int);
void right(int);
void reboot();
int arrayMap[10];

int main() {
	bool programRunning = true;
	arrayMap[0] = 1;
	// Command Handling
	// Loop allows the display menu to display each time a command has been issued
	while (programRunning == true) {
		int command;
		controllerMenu();
		cin >> command;
		// n is a number variable used by the right/left functions
		int n = 1;
		switch (command) {
		case 1:
			cout << endl << "How many tiles to the right would you like to move the robot? " << endl;
			cin >> n;
			cout << endl << "Robot was moved to the right by " << n << " tiles." << endl << endl;
			right(n);
			break;
		case 2:
			cout << endl << "How many tiles to the left would you like to move the robot? " << endl;
			cin >> n;
			cout << endl << "Robot was moved to the left by " << n << " tiles." << endl << endl;
			left(n);			
			break;
		case 3:
			cout << endl << "Displaying the array map" << endl;
			display();
			break;
		case 4:
			cout << endl << "Resetting the array to the initial state" << endl;
			reboot();
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
	cout << "[Controller Menu] " << endl << "1. Right" << endl << "2. Left" << endl << "3. Display" << endl << "4. Reboot" << endl << "5. Show Array" << endl <<  "6. Exit" << endl;
}

void display() {
	// Empty is 0, Robot 1 is 1, Robot 2 is 2.
	// 21x "-" on the top and bottom as the horizontal lines
	// 10x "| " as the vertical lines + one "|" as the last vertical line
	// "^" replaces the space if it is the current location of the robot
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
	cout << endl << endl;
}

void right(int n) {
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < 10; i++) {
			if (arrayMap[i] == 1) {
				if (i != 9) {
					arrayMap[i] = 0;
					arrayMap[i + 1] = 1;
					break; // Stops the function from looping a move to the right
				}
				else {
					cout << "Unable to move to the right, out of bounds. " << endl << endl;
				}
			}
		}
	}
}

void left(int n) {
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < 10; i++) {
			if (arrayMap[i] == 1) {
				if (i != 0) {
					arrayMap[i] = 0;
					arrayMap[i - 1] = 1;
					break; // Stops the function from looping after an action was taken
				}
				else {
					cout << "Unable to move to the left, out of bounds. " << endl << endl;
				}
			}
		}
	}

}

void reboot() {
	for (int i = 0; i < 10; i++) {
		// Resets the array
		arrayMap[i] = 0;
	}
	arrayMap[0] = 1;
}