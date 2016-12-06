//Michael Gonzales
//Doubly Linked List Class Header File
#include <iostream>
#include <fstream>
#include "node.h"
using namespace std;

class List {
public:
	//Constructors
	List();
	List(const List&, char);
	List(ifstream &);
	~List();
	//Accessor Functions
	bool isEmpty();
	int getNumNodes();
	void append(Node*);
	void Delete();
	void insert(Node*);
	void displayAscending();
	void displayDescending();
	void bubbleSort(char);
	void swap(Node*, Node*);
	Node*getHead()const ;
private:
	//Private Data Members
	Node * head;
	Node * tail;
};
