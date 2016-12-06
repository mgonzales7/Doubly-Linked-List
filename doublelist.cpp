//Michael Gonzales
//Source Code for List Class
#include "doublelist.h"

List::List(){
	head = NULL;
	tail = NULL;
}
List::List(const List & x, char ans){
	Node *curr = x.head;
	head = NULL;
	tail = NULL;
	while( curr!=NULL ){
		Node *nPtr = new Node ( curr );
		append( nPtr );
		curr=curr->getNext();
	}
	if (ans=='Y')
		this->bubbleSort('a');

}
List::List(ifstream &InputFile){
        string fname, lname, mi;
        int ss, age;
	head = NULL;
	tail = NULL;
        if(InputFile.is_open()){
                while (InputFile >> fname >> mi >> lname >> ss >> age) {
                	Node*nPtr;
			nPtr = new Node (fname, lname, mi, ss, age);
			append( nPtr);       
                }
        InputFile.close();
        }
}

List::~List(){
	Node*curr;
	Node*next;
	curr=head;
	while(curr !=NULL) {
		next=curr->getNext();
		delete curr;
		curr=next;
	}
}	
	
bool List::isEmpty(){
	bool value=false;
	if (head==NULL)
		value=true;	
	return value;
}
int List::getNumNodes(){
	Node*curr=head;
	int count=0;
	if(head==NULL)
		count=0;
	else{
		while(curr){
			count++;
			curr=curr->getNext();	
		}
	}
	return count;

}
void List::append(Node * nPtr){
	Node*curr;
        curr=head;
        if (head == NULL){
                head=nPtr;
		tail=nPtr;
		head->setPrev(NULL);
	}
        else {
                while(curr->getNext()!= NULL)
                        curr=curr->getNext();
                	curr->setNext(nPtr);
			nPtr->setPrev(curr);
			nPtr->setNext(NULL);
			tail=nPtr;
        }
}
void List::Delete(){
	bool deleted=false;
	string fname, lname;
	cout<<"Please Enter First and Last name to be deleted: ";
	cin >> fname >> lname;
	Node*curr;
	curr=head;
	if(head==NULL)
		cout <<"List is empty";
	else{
		while(curr!=NULL && deleted==false) {
			if(curr->getFirst() == fname && curr->getLast()==lname) {
					if(curr==head){
						head=curr->getNext();
						head->setPrev(NULL);
					}
					else if(curr==tail){
						tail=curr->getPrev();
						tail->setNext(NULL);
					}
					else{
						curr->getPrev()->setNext(curr->getNext());
						curr->getNext()->setPrev(curr->getPrev());
					}
					delete curr;
					deleted=true;
			}
			else{
				curr=curr->getNext();
			}
		}
	
	if (deleted)
		cout<<fname <<" "<<lname<<" successfully deleted\n";
	else
		cout<<"name not found\n";
}
void List::insert(Node* nPtr){
	append(nPtr);
	this->bubbleSort('a');
}
void List::displayAscending(){
        Node*curr;
        curr=head;
        if(head == NULL)
                cout <<"Empty list\n";
        else{
                while(curr!= NULL){
                        curr->display();
                        curr=curr->getNext();
                }
        }
	
}
void List::displayDescending(){
	Node*curr;
	curr=tail;
	if(tail==NULL)
		cout <<"Empty list\n";
	else{
		while(curr!=NULL){
			curr->display();
			curr=curr->getPrev();
		}
	}
}	
void List::bubbleSort(char ans){
	int size=this->getNumNodes();
	for(int i=0; i<size;i++){	
		Node*curr=head;
		Node*next=head->getNext();
		if (next==NULL){
			cout<<"List has One Node Only";
		}
		else {
				if (ans == 'a'){		
					while(next->getNext() != NULL){
						if (curr->getAge() > next->getAge()){
                                        	swap(curr, next);
						next=curr->getNext();
						}
						else {
						curr=next;
						next=next->getNext();
						}
					}	
				}
				else {		
                                        while(curr->getNext() != NULL){
                                                if (curr->getAge() < next->getAge()){
                                                swap(curr, next);
                                                next=curr->getNext();
                                                }
                                                else {
                                                curr=next;
                                                next=next->getNext();
                                                }
                                        }
                                }
	
		}
		
	}
}	
Node* List::getHead()const{
	return head;
}
void List::swap(Node*curr, Node*next){
	 if (curr==head) {
                curr->setNext(next->getNext());
                curr->setPrev(next);
                next->setNext(curr);
                next->setPrev(NULL);
                head=next;
        }
        else {
		curr->getPrev()->setNext(next);
		next->setPrev(curr->getPrev());
                curr->setNext(next->getNext());
		curr->getNext()->setPrev(curr);
                curr->setPrev(next);
                next->setNext(curr);
		if (curr->getNext()==NULL)
			tail=curr;
        }
}

