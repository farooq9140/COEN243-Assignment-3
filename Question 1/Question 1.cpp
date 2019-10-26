#include <iostream>
using namespace std;
int maximum(int*, int);
int minimum(int*, int);
double average(int*, int);
int aGrade(int*, int);
int bGrade(int*, int);
int cGrade(int*, int);
int dGrade(int*, int);
int fGrade(int*, int);


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
	cout << "Grade Median is: " << endl;
	cout << "Number of A Grades: " << aGrade(grades, gradeCount) << endl;
	cout << "Number of B Grades: " << bGrade(grades, gradeCount) << endl;
	cout << "Number of C Grades: " << cGrade(grades, gradeCount) << endl;
	cout << "Number of D Grades: " << dGrade(grades, gradeCount) << endl;
	cout << "Number of F Grades: " << fGrade(grades, gradeCount) << endl;
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

double median(int* grades, int gradeCount) {
	double medianValue = 0;
	int* ordered;
	sort();
	ordered = new int[gradeCount];
	if (gradeCount % 2 == 0) {
		medianValue = static_cast<double>(grades[(gradeCount / 2)] + grades[(gradeCount / 2) + 1])/2;
	}
	else {
		medianValue = grades[(gradeCount / 2) + 1];
	}
	return medianValue;
}

int aGrade(int* grades, int gradeCount) {
	int count = 0;
	for (int i{ 1 }; i < gradeCount; i++) {
		if (grades[i] >= 80) {
			count++;
		}
	}
	return count;
}

int bGrade(int* grades, int gradeCount) {
	int count = 0;
	for (int i{ 1 }; i < gradeCount; i++) {
		if (grades[i] >= 70 && grades[i] < 80) {
			count++;
		}
	}
	return count;
}

int cGrade(int* grades, int gradeCount) {
	int count = 0;
	for (int i{ 1 }; i < gradeCount; i++) {
		if (grades[i] >= 55 && grades[i] < 70) {
			count++;
		}
	}
	return count;
}

int dGrade(int* grades, int gradeCount) {
	int count = 0;
	for (int i{ 1 }; i < gradeCount; i++) {
		if (grades[i] >= 40 && grades[i] < 55) {
			count++;
		}
	}
	return count;
}

int fGrade(int* grades, int gradeCount) {
	int count = 0;
	for (int i{ 1 }; i < gradeCount; i++) {
		if (grades[i] < 40) {
			count++;
		}
	}
	return count;
}