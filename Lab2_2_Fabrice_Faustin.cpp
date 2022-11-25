//Name : Fabrice Faustin
/*
This program  allows a user to enter the number of pennies, nickels, dimes, quarters, half-dollar,
and one-dollar coins a customer has to cash in. 

It calculates and displays the total amount of
money the customer should receive for the coins.

Important values:
- Penny = 1 cent
- Nickel = 5 cents
- Dime = 10 cents
- Quarter = 25 cents
- Half-Dollar = 50 cents
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//Declaration and Initialization of variables
	const double PENNY = 0.01,
		      NICKEL = 0.05,
		      DIME = 0.10,
		      QUARTER = 0.25,
		      HALF_DOLLAR = 0.50,
			  DOLLAR = 1;

	int num_pennies = 0,
		num_nickel = 0,
		num_dime = 0,
		num_quarter = 0,
		num_half_dollar = 0,
		num_dollar = 0 ;

	double total = 0;// This is the total amount of all the user's coins in dollars

	//Input
	cout << "Please enter the amount of each coins when asked." << endl << endl;
	cout << "Number of pennies ? ";
	cin >> num_pennies;
	cout << "Number of nickels ? ";
	cin >> num_nickel;
	cout << "Number of dimes ? ";
	cin >> num_dime;
	cout << "Number of quarters ? ";
	cin >> num_quarter;
	cout << "Number of half_dollars ? ";
	cin >> num_half_dollar;
	cout << "Number of dollars ? ";
	cin >> num_dollar;

	cout << endl << endl;

	//Process and calculations
	//the total amount of money is the sum of all the total amount of each coins(dollar, half_dollars, quarters,...,penny)
	total = num_dollar + (num_half_dollar * HALF_DOLLAR) + (num_quarter * QUARTER) + (num_dime * DIME) + (num_nickel * NICKEL) + (num_pennies * PENNY);

	//Output
	cout << setprecision(2) << fixed;//we only need two decimals when displaying currency

	cout << "You have :" << endl;
	cout << "\t" << num_pennies << " pennies," << endl;
	cout << "\t" << num_nickel << " nickels," << endl;
	cout << "\t" << num_dime << " dimes," << endl;
	cout << "\t" << num_quarter << " quarters," << endl;
	cout << "\t" << num_half_dollar << " half-dollars," << endl;
	cout << "\t" << num_dollar << " dollars," << endl;
	cout << "for a total of $" << total << endl << endl;

	return 0;
}