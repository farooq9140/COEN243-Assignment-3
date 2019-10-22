#include <iostream>
using namespace std;
int maximum(int*, int);
int minimum(int*, int);
double average(int*, int);


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
		cout << "Enter grade #" << i+1 << endl;
		cin >> gradeInput;
		grades[i] = gradeInput;
	}

	cout << "Maximum grade is: " << maximum(grades, gradeCount) << endl;
	cout << "Minimum grade is: " << minimum(grades, gradeCount) << endl;
	cout << "Grade Average is: " << average(grades, gradeCount) << endl;
	cout << "Grade Median is: ";
	cout << "Number of A Grades: ";
	cout << "Number of B Grades: ";
	cout << "Number of C Grades: ";
	cout << "Number of D Grades: ";
	cout << "Number of F Grades: ";
	return 0;
}

int maximum(int* grades, int gradeCount) {
	int maximum = grades[0];
	for (int i{ 1 }; i < gradeCount; i++) {
		if (grades[i] > maximum) {
			maximum = grades[i];
		}
	}
	return maximum;
}

int minimum(int* grades, int gradeCount) {
	int minimum = grades[0];
	for (int i{ 1 }; i < gradeCount; i++) {
		if (grades[i] < minimum) {
			minimum = grades[i];
		}
	}
	return minimum;
}

double average(int* grades, int gradeCount) {
	int sum = 0;
	for (int i{ 0 }; i < gradeCount; i++) {
		sum += grades[i];
	}
	return static_cast<double>(sum) / gradeCount;
}