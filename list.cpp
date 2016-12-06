//Michael Gonzales
//Source Code for List Class
#include "list.h"

List::List(){
	head = NULL;
}
List::List(const List & x){
	Node *curr = x.head;
	head = NULL;

	while( curr!=NULL ){
		Node *nPtr = new Node ( curr );
		append( nPtr );
		curr=curr->getNext();
	}

}
List::List(ifstream &InputFile){
        string fname, lname, mi;
        int ss, age;
	head = NULL;
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
        if (head == NULL)
                head=nPtr;
        else {
                while(curr->getNext()!= NULL)
                        curr=curr->getNext();
                curr->setNext(nPtr);
        }
}
void List::Delete(){
	
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
void List::bubbleSort(){
	int size=this->getNumNodes();
	for(int i=0; i<size;i++){
		Node*prev=head;	
		Node*curr=head;
		Node*next=head->getNext();
		if (next==NULL){
			cout<<"List has One Node Only";
		}
		else {
			if (curr==head) {
				if (curr->getAge() > next->getAge()){
					swap(prev, curr, next);
					prev=next;
					next=curr->getNext();
				}
			}
			while(curr->getNext() != NULL){
				if (curr->getAge() > next->getAge()){
                                        swap(prev, curr, next);
					prev=next;
					next=curr->getNext();
				}
				else {
				prev=curr;
				curr=next;
				next=next->getNext();
				}
			}	
		
		}
	}
}	
Node* List::getHead()const{
	return head;
}
void List::swap(Node*prev, Node*curr, Node*next){
	if (prev==curr) {
		curr->setNext(next->getNext());
		curr->setPrev(next);
		next->setNext(curr);
		next->setPrev(NULL);
		head=next;
	}
	else {
		prev->setNext(next);
		curr->setNext(next->getNext());
		curr->setPrev(next);
		next->setNext(curr);
		next->setPrev(prev);
	}
}
