#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void controllerMenu();
void display();
int left(int);
int right(int);
void reboot();
void showArray();
void cancel(int);
int arrayMap[10];
int movesCount = 0;
vector<int> movesHistory;
vector<int> cancelledMoves;

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
		int movement;
		switch (command) {
		case 1:
			cout << endl << "How many tiles to the right would you like to move the robot? " << endl;
			cin >> n;
			movement = right(n);
			if (movement > 0) {
				if (movement < n) {
					cout << endl << n << " moves will result in a out of bounds. Instead, robot was moved to the right by " << movement << " tiles." << endl << endl;
				}
				else {
					cout << endl << "Robot was moved to the right by " << movement << " tiles." << endl << endl;
				}
			}
			else {
				cout << "Unable to move to the right, out of bounds. " << endl << endl;
			}
			movesCount++;
			break;
		case 2:
			cout << endl << "How many tiles to the left would you like to move the robot? " << endl;
			cin >> n;
			movement = left(n);
			if (movement > 0) {
				if (movement < n) {
					cout << endl << n << " moves will result in a out of bounds. Instead, robot was moved to the left by " << movement << " tiles." << endl << endl;
				}
				else {
					cout << endl << "Robot was moved to the left by " << movement << " tiles." << endl << endl;
				}
			}
			else {
				cout << "Unable to move to the left, out of bounds. " << endl << endl;
			}
			movesCount++;
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
			cout << endl << "Displaying the empty array map" << endl;
			showArray();
			break;
		case 6:
			cout << endl << "How many moves would you like to cancel? " << endl;
			cin >> n;
			cancel(n);
			break;
		case 7:
			cout << endl << "How many of the last cancelled moves would you like to view? " << endl;
			cin >> n;
			cancel(n);
			break;
		case 8:
			cout << "Program is ending.";
			programRunning = false;
			break;
		default:
			cout << "Command could not be recognized, please try again. " << endl << endl;
		}
	}
	return 0;
}

void controllerMenu() {
	cout << "[Controller Menu] " << endl << "1. Right" << endl << "2. Left" << endl << "3. Display" << endl << "4. Reboot" << endl << "5. Show Array" << endl << "6. Cancel a number of moves" << endl << "7. Replay the moves that were cancelled" << endl <<  "8. Exit" << endl;
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
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << " " << i;
	}
	cout << endl << endl;
}

int right(int n) {
	int moves = 0;
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < 10; i++) {
			if (arrayMap[i] == 1) {
				if (i != 9) {
					moves = moves+1;
					arrayMap[i] = 0;
					arrayMap[i + 1] = 1;
					break; // Stops the function from looping a move to the right
				}
				else {
					break;
				}
			}
		}
	}
	movesHistory.push_back(moves);
	return moves;
}

int left(int n) {
	int moves = 0;
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < 10; i++) {
			if (arrayMap[i] == 1) {
				if (i != 0) {
					moves = moves+1;
					arrayMap[i] = 0;
					arrayMap[i - 1] = 1;
					break; // Stops the function from looping after an action was taken
				}
				else {
					break;
				}
			}
		}
	}
	movesHistory.push_back(-moves);
	return moves;
}

void reboot() {
	for (int i = 0; i < 10; i++) {
		// Resets the array
		arrayMap[i] = 0;
	}
	arrayMap[0] = 1;
}

void showArray() {
	for (int i = 0; i < 21; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << "|";
			cout << " ";
	}
	cout << "|" << endl;
	for (int i = 0; i < 21; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << " " << i;
	}
	cout << endl << endl;
}

void cancel(int n) {
	int vectorSize = movesHistory.size();
	if (n > vectorSize) {
		n = vectorSize;
		if (vectorSize > 0) {
			cout << "Only " << vectorSize << " moves were performed. " << vectorSize << " moves will be cancelled instead." << endl << endl;
		}
		else {
			cout << "No moves were performed. Thus none can be cancelled." << endl << endl;
			return;
		}
	}
	for (int i = 0; i < n; i++) {
			int lastMove = movesHistory.back();
			if (lastMove > 0) {
				// Moved to the right
				cout << "Cancel right" << endl;
				cout << lastMove << endl;
				left(lastMove);
				cancelledMoves.push_back(lastMove);
			}
			else if (lastMove < 0) {
				// Moved to the left
				cout << "Cancel left" << endl;
				cout << lastMove << endl;
				lastMove *= -1;
				right(lastMove);
				cancelledMoves.push_back(-lastMove);
			}
			movesHistory.pop_back();
	}
}

void showCancelled(int n) {
	for (int i = 0; i < n; i++) {

	}
}