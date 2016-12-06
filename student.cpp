//Michael Gonzales
//Source Code For Student Class contains data
#include "student.h"

student::student(){
	nameFirst = "";
	nameMid = "";
	nameLast = "";
	social = 0;
	age = 0;
}

student::student(string fName, string lName, string mi, int ss, int uAge) {
	nameFirst=fName;
	nameLast =lName;
	nameMid=mi;
	social=ss;
	age=uAge;
}

void student::display() {
	cout << endl;
	cout <<"First Name: " << nameFirst << endl;
	cout <<"Middle Name: " << nameMid << endl;
	cout <<"Last Name: " <<nameLast << endl;
	cout <<"Social Security Number: " << social << endl;
	cout <<"Age: " << age << endl;
}

string student::getFirst() {
	return nameFirst;
}

string student::getMid() {
	return nameMid;
}

string student::getLast(){
	return nameLast;
}

int student::getAge(){
	return age;
}

int student::getSocial(){
	return social;
}
