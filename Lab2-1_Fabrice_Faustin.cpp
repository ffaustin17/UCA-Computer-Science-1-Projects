//Name : Fabrice Faustin
/*
The program prompts the user for a student’s three initials and four exam scores. Then it calculates the
total and the average of the four exam scores. Finally it displays the student’s initials, four exam scores, the total exam
score, and the calculated average.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//Declarations of variables.
	char initial1,
		initial2,
		initial3;
	double exam_score1,
		exam_score2,
		exam_score3,
		exam_score4;

	//Input. The user is asked their initials and exam scores
	cout << "Please enter the student's three initials when asked." << endl << endl ;
	
	cout << "First Initial : ";
	cin >> initial1;
	cout << "Second Initial : ";
	cin >> initial2;
	cout << "Last Initial : ";
	cin >> initial3;

	cout << "\n\nNext you will be asked to enter four exam scores.\n\n" ;
	cout << "Please enter the first exam score and then press <Enter> : ";
	cin >> exam_score1;
	cout << "\nPlease enter the second exam score and then press <Enter> : ";
	cin >> exam_score2;
	cout << "\nPlease enter the third exam score and then press <Enter> : ";
	cin >> exam_score3;
	cout << "\nPlease enter the fourth exam score and then press <Enter> : ";
	cin >> exam_score4;

	//Process and calculations
	double total = exam_score1 + exam_score2 + exam_score3 + exam_score4;
	double average = total / 4;

	//Display the information inputted as well as those that were calculated based on the user input
	cout << "\n\nStudent Initials : " << initial1 << " " << initial2 << " " << initial3;
	cout << setprecision(2) << fixed; // we allow only two decimals

	cout << "\n\nExam 1...................................." << exam_score1;
	cout << "\nExam 2...................................." << exam_score2;
	cout << "\nExam 3...................................." << exam_score3;
	cout << "\nExam 4...................................." << exam_score4;
	cout << "\nTotal....................................." << total;
	cout << "\nAverage:.................................." << average;

	cout << endl << endl;


	return 0;
}