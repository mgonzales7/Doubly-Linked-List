//Michael Gonzales
//Linked List Class Header File
#include <iostream>
#include <fstream>
#include "node.h"
using namespace std;

class List {
public:
	//Constructors
	List();
	List(const List&);
	List(ifstream &);
	~List();
	//Accessor Functions
	bool isEmpty();
	int getNumNodes();
	void append(Node*);
	void Delete();
	void displayAscending();
	void bubbleSort();
	void swap(Node*, Node*, Node*);
	Node*getHead()const ;
private:
	//Private Data Members
	Node * head;
};
