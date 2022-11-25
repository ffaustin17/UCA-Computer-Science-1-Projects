// Author : Fabrice Faustin
// This program inputs 20 integers and places them into even, odd, positive, or negative categories.


//preprocessor directives-----------------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;


//symbolic constants-----------------------------------------------------------------------------------------------
const int NUM_INTEGERS = 20;


//Function prototypes----------------------------------------------------------------------------------------------
void getIntegers(int[]);
void oddAndEvenList(int[], int[], int[]);
void positiveAndNegativeList(int[], int[], int[]);
void displayAllLists(int[], int[], int[], int[]);
bool repeat();


//main function---------------------------------------------------------------------------------------------------

int main()
{
	// needed variables
	int integers[NUM_INTEGERS],
		even[NUM_INTEGERS],     // list of the even numbers from a list of integers
		odd[NUM_INTEGERS],      // list of the odd numbers from a list of integers
		positive[NUM_INTEGERS], // list of the positive numbers from a list of integers
		negative[NUM_INTEGERS]; // list of the negative numbers from a list of integers

	
	
	do
	{
		//input 
		getIntegers(integers);

		//process
		oddAndEvenList(integers, even, odd);
		positiveAndNegativeList(integers, positive, negative);

		//output
		displayAllLists(even, odd, positive, negative);

		
	} while (repeat()); // programs runs again if the user wants to

	return 0;
}



//function definitions--------------------------------------------------------------------------------------------------


//gets the user the number to enter the name of an exam and the score every students in a class has obtained for said exam
void getIntegers(int list_of_integers[])
{

	cout << "This program inputs 20 integers and places them into even, odd, positive, or negative categories." << endl << endl;

	cout << "Please enter 20 integers." << endl;
	for (int i = 0; i < NUM_INTEGERS; i++)
	{
		cout << "Integer " << i + 1 << " =? " ;
		cin >> list_of_integers[i];
		cin.ignore();
	}
}



/*determines if values from a list to be checked are even or odd, 
  and assigns them accordingly to the even or odd integers lists.
  the first array parameter is the list to be cheked                */
void oddAndEvenList(int integers[], int even[], int  odd[])
{

	bool is_even; //variable that determines if a number is even


	/*iterates over the given list of int to check every numbers it holds.
	  each parameter list has the same size, therefore after we determine if the value in each subsequent element
	  of the list to be checked is even or odd, we can assign said value to the same element
	  of the corresponding list ( even or odd ) depending on the value's status.
	  an error value exclusive to each list is assigned to the element of the list that does not receive in a check (iteration of loop)   */
	for (int i = 0; i < NUM_INTEGERS; i++)
	{
		is_even = (integers[i] % 2) == 0; // true if the division between the number being checked (integers[i]) and 2 leaves no remainder

		if (is_even)                      // the number being checked is even
		{
			even[i] = integers[i]; 
			odd[i] = 2;                   // 2 is the error value stored for the negative list
		}
		else                              // the number is odd
		{
			even[i] = 1;                  // 1 is the error value stored for the negative list
			odd[i] = integers[i];
		}
	}

	
}


/*determines if values from a list to be checked are positive or negative, 
  and assigns them accordingly to the positive or negative integers lists.
  the first array parameter is the list to be checked                         */
void positiveAndNegativeList(int integers[], int positive[], int negative[])
{
	bool isPositive; //variable that determines if a number is positive

	/*iterates over the given list of int to check every numbers it holds.
	  each parameter list has the same size, therefore after we determine if the value in each subsequent element
	  of the list to be checked is positive or negative, we can assign said value to the same element 
	  of the corresponding list ( positive or negative ) depending on the value's status.
	  an error value exclusive to each list is assigned to the element of the list that does not receive in a check (iteration of loop)   */
	for (int i = 0; i < NUM_INTEGERS; i++)  
	{
		isPositive = integers[i] >= 0;  // for the purpose of this exercise, 0 is a positive integer


		if (isPositive)                 // the number we are checking is positive
		{
			positive[i] = integers[i];
			negative[i] = 0;            // 0 is the error value stored for the negative list
		}
		else                            //the number is negative
		{
			positive[i] = -1;           // -1 is the error value stored for the positive list
			negative[i] = integers[i];
		}
	}
}



//displays the given lists of even integers, odd integers, positive integers, and negative integers
void displayAllLists(int even[], int odd[], int positive[], int negative[])
{

	/*display the list of even integers  from the list of integers inputted
	  skips over elements that have an error value in them
	  for even int list, the error value is 1, as it cannot be an even integer.  */
	cout << endl;
	cout << "The even integers are : " << endl;
	for (int i = 0; i < NUM_INTEGERS; i++)
	{
		if (even[i] != 1)                       // only print the number if it is different from the error value (1).
		{
			cout << even[i] << "    ";
		}

	}


	/*displays the list of odd integers  from the list of integers inputted
	  skips over elements that have an error value in them
	  for odd int list, the error value is 2, as it cannot be an odd integer.   */
	cout << endl << endl;
	cout << "The odd integers are : " << endl;
	for (int i = 0; i < NUM_INTEGERS; i++)
	{
		if (odd[i] != 2)                 // only print the number if it is different from the error value (2).
		{
			cout << odd[i] << "    " ;
		}

	}


	/*display the list of positive integers  from the list of integers inputted
	  skips over elements that have an error value in them
	  for positive int list, the error value is -1, as it cannot be a positive integer.   */
	cout << endl << endl;
	cout << "The positive integers are : " << endl;
	for (int i = 0; i < NUM_INTEGERS; i++)
	{
		if (positive[i] != -1)           // only print the number if it is different from the error value (-1).
		{
			cout << positive[i] << "    ";
		}

	}


	/*display the list of negative integers  from the list of integers inputted
	  skips over elements that have an error value in them
	  for negative int list, the error value for the purpose of this program is 0, it cannot be a negative integer integer.   */
	cout << endl << endl;
	cout << "The negative integers are : " << endl;
	for (int i = 0; i < NUM_INTEGERS; i++)
	{
		if (negative[i] != 0)                   // only print the number if it is different from the error value (0).
		{
			cout << negative[i] << "    ";           
		}

	}

}


//gets the user's input on whether they wish to restart the program
bool repeat()
{
	char choice;

	cout << endl << endl
		<< "Would you like to process another 20 integers?" << endl
		<< "Please enter 'y' for yes or 'n' for no: ";
	cin >> choice;
	cin.ignore();

	cout << endl
		<< "------------------------------------------------------------------------" << endl
		<< endl;

	if (choice == 'y' || choice == 'Y')
		return true;
	else
		return false;

}

