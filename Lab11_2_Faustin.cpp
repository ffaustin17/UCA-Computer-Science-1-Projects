// Author : Fabrice Faustin

/*This program calculates the passing average of the top 5 quarterbacks of the last
4 years to present an ESPY Award (Excellence in Sports Performance Yearly) to for the quarterback with
highest average of completed passes. (The completed passes do not include interceptions.)
*/

//preprocessor directives
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//symbolic constants
const int QUARTERBACKS_NUM = 5;

//structure declarations

//record(s) of a quarterback during a competition
struct QuarterbackRecord
{
	string name;
	int pass_completion;
	int attempts;
	double average;
};

//record(s) of the stats of a particular competition
struct CompStats
{
	int total_pass_completed;
	int total_attempts;
	double overall_avg;
	double highest_avg;
	string espy_winner;
};

//function prototypes
void readQuarterbackInfo(QuarterbackRecord[]);
void calcQuarterbackAvg(QuarterbackRecord top_5_quarterbacks[]);
void calcTotalsnOverallAvg(CompStats& nfl, QuarterbackRecord top_5_quarterbacks[]);
void determineESPYWinner(CompStats& nfl, QuarterbackRecord top_5_quarterbacks[]);
void displayEspyAwardChart(CompStats nfl, QuarterbackRecord top_5_quarterbacks[]);

//main
int main()
{
	//needed variables
	QuarterbackRecord top_5_quarterbacks[QUARTERBACKS_NUM]; //list of stats of the top 5 quarterbacks of the competition
	CompStats nfl;                                          //overall stats of the nfl competition

	//input
	readQuarterbackInfo(top_5_quarterbacks);

	//process
	calcQuarterbackAvg(top_5_quarterbacks);
	calcTotalsnOverallAvg(nfl, top_5_quarterbacks);
	determineESPYWinner(nfl, top_5_quarterbacks);

	//output
	displayEspyAwardChart(nfl, top_5_quarterbacks);


	return 0;
}


//function definitions

//reads the info about the top 5 quarterbacks of the competition (their name, number of passes completed, and passes attempted)
void readQuarterbackInfo(QuarterbackRecord top_5_quarterbacks[])
{
	for (int i = 0; i < QUARTERBACKS_NUM; i++)
	{
		cout << "Please enter the name of quarterback " << i + 1 << ": ";
		getline(cin, top_5_quarterbacks[i].name);

		cout << "Please enter the amount of pass they have completed: ";
		cin >> top_5_quarterbacks[i].pass_completion;

		cout << "Please enter the amount of attempts they have made: ";
		cin >> top_5_quarterbacks[i].attempts;
		cin.get();

		cout << endl;
	}
}


//calculated the pass average of each player from the top 5 quarterbacks
void calcQuarterbackAvg(QuarterbackRecord top_5_quarterbacks[])
{
	for (int i = 0; i < QUARTERBACKS_NUM; i++)
	{
		top_5_quarterbacks[i].average = double(top_5_quarterbacks[i].pass_completion) / top_5_quarterbacks[i].attempts;
	}
}


//calculates the the total number of pass completed and attempted by all 5 top quarterbacks of the competition.
//With this, calculates the overall pass average of all 5 top quarterbacks of the competition.
void calcTotalsnOverallAvg(CompStats& nfl, QuarterbackRecord top_5_quarterbacks[])
{
	nfl.total_pass_completed = 0;
	nfl.total_attempts = 0;
	nfl.overall_avg = 0;

	for (int i = 0; i < QUARTERBACKS_NUM; i++)
	{
		nfl.total_pass_completed += top_5_quarterbacks[i].pass_completion;
		nfl.total_attempts += top_5_quarterbacks[i].attempts;
	}

	nfl.overall_avg = (double)nfl.total_pass_completed / nfl.total_attempts;
}


//determines the ESPY (Excellence in Sports Performance Yearly) winner from the list of top 5 quarterbacks of the competition by comparing their pass average
void determineESPYWinner(CompStats& nfl, QuarterbackRecord top_5_quarterbacks[])
{
	//assume at first that the first quarterback has the highest average
	//and therefore is (if no changes are made) the espy winner as a placeholder
	nfl.highest_avg = top_5_quarterbacks[0].average;
	nfl.espy_winner = top_5_quarterbacks[0].name;

	//check the entire list of the top 5 quarterbacks
	for (int i = 0; i < QUARTERBACKS_NUM; i++)
	{
		//test if the placeholder espy winner of the list is indeed the espy winner.
		//if another has a higher average, they become the espy winner
		if (top_5_quarterbacks[i].average > nfl.highest_avg)
		{
			nfl.highest_avg = top_5_quarterbacks[i].average;
			nfl.espy_winner = top_5_quarterbacks[i].name;
		}
	}
}


//displays the list of the top 5 quarterbacks as well as their respective stats (pass completed, pass attempted, pass average).
//displays the stats of the competition total passes completed, total passes attempted, and total pass average).
//finally displays the name of the ESPY winner and their pass average.
void displayEspyAwardChart(CompStats nfl, QuarterbackRecord top_5_quarterbacks[])
{
	int len = 20; // length of a block of text

	cout << setprecision(3) << fixed;

	//headers of the table
	cout << left << setw(len) << "Quarterbacks"
		<< setw(len) << right << "Completions"
		<< setw(len) << "Attempts"
		<< setw(len) << "AVE"
		<< endl;

	//print top 5 quarterbacks info
	for (int i = 0; i < QUARTERBACKS_NUM; i++)
	{
		cout << left << setw(len) << top_5_quarterbacks[i].name
			<< right << setw(len) << top_5_quarterbacks[i].pass_completion
			<< setw(len) << top_5_quarterbacks[i].attempts
			<< setw(len) << top_5_quarterbacks[i].average
			<< endl;
	}

	cout << endl;

	//print competition stats
	cout << left << setw(len) << "Totals"
		<< right << setw(len) << nfl.total_pass_completed
		<< setw(len) << nfl.total_attempts
		<< setw(len) << nfl.overall_avg << " Overall"
		<< endl
		<< endl;

	//espy winner announcement
	cout << nfl.espy_winner << " wins the ESPY award for highest average (" << nfl.highest_avg << ") of completed passes." << endl;

}