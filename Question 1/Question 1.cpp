#include <iostream>
using namespace std;
int maximum(int*, int);

int main() {
	// Setting the pointer of the dynamic grades array
	int* grades = NULL;

	int gradeCount;
	cout << "Please enter the total amount of grades to be entered: " << endl;
	cin >> gradeCount;

	// Defining the size of the grades array
	grades = new int[gradeCount];

	// Inputting the grades
	for (int i = 0; i < gradeCount; i++) {
		int gradeInput;
		cout << "Enter grade #" << i << endl;
		cin >> gradeInput;
		grades[i] = gradeInput;
	}



}

int maximum(int* grades, int gradeCount) {
	int maximum;
	for (int i; i < gradeCount; i++) {

	}
}

int minimum() {

}

int average() {

}

int median() {

}

int AGrades() {

}

int BGrades() {

}

int CGrades() {

}

int DGrades() {

}

int FGrades() {

}