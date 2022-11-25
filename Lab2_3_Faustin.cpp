//Name: Fabrice Faustin

/*
This programs calculates
the total sales for the home football games. 

There are three seating levels at a football stadium. 
- Level 1 seats cost $25.50 each,
- Level 2 seats cost $20.50 each, 
- Level 3 seats cost $15.50 each. 

The program asks how many tickets were sold for each seating level and then displays the dollar
amount for each level and the amount of income generated from all ticket sales. 
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	//Declaration and Initialization of variables

	/*just below are values that will not change during the course of this program,
	  but can still be tweaked by any developper to produce different results if they so choose.
	  for example, if the prices increase.
	*/
	const double  LEV_1_COST = 25.50,
				  LEV_2_COST = 20.50,
				  LEV_3_COST = 15.50;

	int lev_1_tickets = 0,
		lev_2_tickets = 0,
		lev_3_tickets = 0;

	double lev_1_sales = 0,
		   lev_2_sales = 0,
		   lev_3_sales = 0,
		   total_sales = 0;

	//input
	cout << "Please enter the total # of tickets sold for Level 1 seating : ";
	cin >> lev_1_tickets;
	cout << "Please enter the total # of tickets sold for Level 2 seating : ";
	cin >> lev_2_tickets;
	cout << "Please enter the total # of tickets sold for Level 3 seating : ";
	cin >> lev_3_tickets;

	cout << endl << endl;

	//Process and calculations
	lev_1_sales = LEV_1_COST * lev_1_tickets;
	lev_2_sales = LEV_2_COST * lev_2_tickets;
	lev_3_sales = LEV_3_COST * lev_3_tickets;
		
	total_sales = lev_1_sales + lev_2_sales + lev_3_sales ;

	//output

	cout << setprecision(2) << fixed;

	cout << "Level 1 ticket sales................$" << lev_1_sales << endl;
	cout << "Level 2 ticket sales................$" << lev_2_sales << endl;
	cout << "Level 3 ticket sales................$" << lev_3_sales << endl;
	cout << "Total ticket sales..................$" << total_sales << endl << endl;

	return 0;
}