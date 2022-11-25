//Fabrice Faustin
//This program displays a christmas tree

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//the different strings of stars which will be needed to display the christmas tree
	//there will be one string per line
	string one_str = "    *    ";
	string three_str = "   ***   ";
	string five_str = "  *****  ";
	string seven_str = " ******* ";
	string nine_str = "*********";

	cout << one_str << endl
		<< three_str << endl
		<< five_str << endl
		<< seven_str << endl
		<< nine_str << endl
		<< three_str << endl
		<< three_str << endl << endl;

	cout << "Merry Christmas" << endl;

	return 0;
}