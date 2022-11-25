//Author : Fabrice Faustin

// This program calculates the grade for students taking a simple quiz


//preprocessor directives
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Symbolic constants
const int NUM_OF_ANSWERS = 5;    //number of questions on the quiz
const int STUDENT_MAX_NUM = 100; //we assume that there will not be more than 100 students to record grades for
const int MAX_GRADE = 15;



//function prototypes
int getStudentNum();
void getAnswerKey(char[]);
void getStudentName(int, string[]);
void getStudentAnswers(int, string[], char[][NUM_OF_ANSWERS]);
void calcStudentGrade(int, char[], char[][NUM_OF_ANSWERS], int[]);
void displayQuizReport(int, char[], string[], char[][NUM_OF_ANSWERS], int[]);
bool repeat();


//main
int main()
{

	//needed variables
	char answer_key[NUM_OF_ANSWERS];
	char student_answers[STUDENT_MAX_NUM][NUM_OF_ANSWERS];
	string student_name[STUDENT_MAX_NUM];
	int student_grade[STUDENT_MAX_NUM] = { 0 };

	int actual_student_num = 0;

	do
	{
		
		cout << "This program calculates the grade for students taking a simple quiz." << endl << endl;

		//input
		actual_student_num = getStudentNum();

		cout << endl;

		getAnswerKey(answer_key);
		getStudentName(actual_student_num, student_name);
		getStudentAnswers(actual_student_num, student_name, student_answers);

		//process
		calcStudentGrade(actual_student_num, answer_key, student_answers, student_grade);

		//output
		displayQuizReport(actual_student_num, answer_key, student_name, student_answers, student_grade);

	} while (repeat());
	
}


//function definitions



//gets the number of students who took a quiz
int getStudentNum()
{
	int student_num = 0;

	do
	{
		cout << "How many students took the quiz? ";
		cin >> student_num;

		if (student_num <= 0)
		{
			cout << "----------------------------------------------------------------------------------------" << endl
				<< "**** ERROR - INVALID NUMBER OF STUDENTS - MUST BE GREATER THAN 0 - PLEASE TRY AGAIN ****" << endl
				<< "----------------------------------------------------------------------------------------" << endl;
		}

	} while (student_num <= 0);

	return student_num;
}


//gets the asnwer (combination of correct answers in order) key from the user
void getAnswerKey(char answer_key[])
{
	cout << "Please enter the answer key." << endl;

	for (int i = 0; i < NUM_OF_ANSWERS; i++)
	{
		cout << "Answer #" << i + 1 << " : ? ";
		cin >> answer_key[i];
	}
	cin.get();

	cout << endl;
}



//gets the name of every student who took a quiz and stores them in a list
void getStudentName(int actual_student_num, string student_name[])
{
	cout << "Please enter the students' names." << endl;

	for (int i = 0; i < actual_student_num; i++)
	{
		cout << "Student #" << i + 1 << " Name: ? ";
		getline(cin, student_name[i]);
	}

	cout << endl;
}


//gets the answers of every student who took a quiz on said quiz
void getStudentAnswers(int actual_student_num, string student_name[], char student_answers[][NUM_OF_ANSWERS])
{
	for (int i = 0; i < actual_student_num; i++)
	{
		cout << "Please enter the answers for " << student_name[i] << ".";
		cout << endl;
		for (int j = 0; j < NUM_OF_ANSWERS ; j++)
		{
			cout << "Answer #" << j + 1 << ": ? ";
			cin >> student_answers[i][j];
		}
		cout << endl;
	}

	cout << endl;
}



//calculates the grade of every student who took a quiz by comparing their answers with the answer key (list of correct answer)
void calcStudentGrade(int actual_student_num, char answer_key[], char student_answers[][NUM_OF_ANSWERS], int student_grade[])
{
	int grade = 0;

	for (int i = 0; i < actual_student_num; i++)
	{
		grade = 0;
		for (int j = 0; j < NUM_OF_ANSWERS; j++)  //grades every answer of one student and when it's done does the same for the next until the last student
		{
			if (student_answers[i][j] == answer_key[j])
			{
				grade += (MAX_GRADE/NUM_OF_ANSWERS); //the questions points are equally distributed among questions
			}
		}
		student_grade[i] = grade; // store the total grade of the student in a list
	}

}


//displays the quiz report/results
void displayQuizReport(int actual_student_num, char answer_key[], string student_name[], char student_answers[][NUM_OF_ANSWERS], int student_grade[])
{
	cout << setw(25) << left << "Student Name"
		 << setw(25) << "Quiz Answers"
		 << setw(25) << "Grade" << endl;
	cout << setw(25) << "-------------"
		 << setw(25) << "-------------"
		 << setw(25) << "-------------" << endl;

	//display the answer key
	cout << setw(25) << "Key";
	for (int i = 0; i < NUM_OF_ANSWERS; i++)
	{
		cout << answer_key[i] << " ";
	}

	//display the max grade
	cout << setw(25) << right << MAX_GRADE << endl;
	cout << endl;

	//display the student answers and grade
	for (int i = 0; i < actual_student_num; i++)
	{
		//print the specific student name
		cout << setw(25) << left << student_name[i];

		//display one student's answers for the quiz
		for (int j = 0; j < NUM_OF_ANSWERS; j++)
		{
			cout << student_answers[i][j] << " ";
		}

		//display the grade of the specific student
		cout << setw(25) << right << student_grade[i];
		cout << endl;

	}

	cout << endl;
}


//asks if the user wishes to repeat the program
bool repeat()
{
	char choice;

	cout << "Would you like to process another quiz? "
		<< "Please enter 'y' for yes or 'n' for no : ";
	cin >> choice;
	cin.get();

	cout << endl
		<< "--------------------------------------------------------------------------------------------------------" << endl
		<< endl;

	if (choice == 'y' or choice == 'Y')
		return true;
	else
		return false;

}