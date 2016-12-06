//Michael Gonzales
//HeaderFile for the Student Object that holds data for linked list
#include <iostream>
#include <string>
using namespace std;

class student {

public:
	student();
	student(string, string, string, int, int);
	void display();
	string getFirst();
	string getMid();
	string getLast();
	int getAge();
	int getSocial();
private:
	string nameFirst, nameMid, nameLast;
	int social, age;
};
