//Michael Gonzales
//Header File for Node Class
#include <iostream>
#include "student.h"
#include <string>
#include <fstream>
using namespace std;

class Node{
public:
	//Constructorrs
	Node();
	Node(string, string, string, int, int);
	Node(const Node*);	
	Node*getNext();        //Returns Next data member
	void setNext(Node*);   //Sets next data member
	Node*getPrev();
	void setPrev(Node*);
	void display();
	string getFirst()const;
	string getMid()const;
	string getLast()const;
	int getAge ()const;
	int getSocial()const;
private:
	student *sPtr;    //pointer to Student Object
	Node *Next;       //pointer to next node
	Node *Prev;
};

