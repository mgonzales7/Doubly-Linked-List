//Michael Gonzales
//Driver Program
#include "doublelist.h"
#include <iostream>
using namespace std;

//Main Function
int main(){
	char ans;
	ifstream file ("file.txt");
	cout <<"Unsorted Linked List created from file in Ascending\n"
	     <<"--------------------------------------\n";
	List A(file);
	A.displayAscending();
	cout <<"Unsorted Linked List created from file in Descending\n"
	     <<"--------------------------------------\n";
	A.displayDescending();
	cout <<"Will now test copy constructer, Would you like the copied list to be sorted? (Y/N): ";
	cin >> ans;
	cout <<"\nNow displaying copy in ascending order via Copy Constructor\n"
	     <<  "----------------------------------------------\n";
	List B(A, ans);
	B.displayAscending();
	cout <<"\nNow displaying list in descending order\n"
	     <<  "------------------------------\n";
	B.displayDescending();
	cout <<" Would you like to delete a name? (Y/N): ";
	cin >> ans;
	if (ans == 'Y')
		B.Delete();
	cout <<"Displaying new list\n";
	cout <<"--------------------\n";
	B.displayAscending();
	return 0;
}



