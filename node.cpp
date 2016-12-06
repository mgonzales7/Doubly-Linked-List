//Michael Gonzales
//Source Code for Node Class
#include "node.h"

Node::Node() {
	Next=NULL;
	Prev=NULL;
}
Node::Node(string fname, string lname, string mi, int ss, int age){
	student * temp;
	temp = new student(fname, lname, mi, ss, age);
	sPtr= temp;
	Next=NULL;
	Prev=NULL;
}
Node::Node(const Node* x){

	sPtr = new student(x->getFirst(),x->getLast(),x->getMid(), x->getSocial(), x->getAge());
	Next=NULL;
	Prev=NULL;
}

Node*Node::getNext(){
	return Next;
}
void Node::display(){
	sPtr->display();
}
void Node::setNext(Node* n){
	Next=n;
}
Node*Node::getPrev(){
	return Prev;
}
void Node::setPrev(Node* n){
	Prev=n;
}
string Node:: getFirst() const {
	return sPtr->getFirst();
}
string Node:: getMid() const {
	return sPtr->getMid();
}
string Node:: getLast() const {
	return sPtr->getLast();
}
int Node:: getAge() const {
	return sPtr->getAge();
} 
int Node:: getSocial() const {
	return sPtr->getSocial();
}
