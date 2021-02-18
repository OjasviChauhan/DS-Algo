#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int d){
		data = d;
		next = NULL;
	}
};

int length(node* head){
	int cnt=0;
	while(head!=NULL){
		head = head->next;
		cnt++;
	}
	return cnt;
}

// passing pointer by reference in all insertion operation
void insertAtHead(node* &head, int d){
	if(head == NULL){
		head = new node(d);
		return;
	}
	node* newNode = new node(d);
	newNode->next = head;
	head = newNode;
}

void insertAtTail(node* &head, int d){
	if(head == NULL){
		head = new node(d);
		return;
	}
	node* tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}
	tail->next = new node(d);
}

void insertAtMiddle(node* &head, int d, int p){
	if(head == NULL or p==0){
		insertAtHead(head,d);
	}
	else if(p > length(head)){
		insertAtTail(head,d);
	}
	else{
		node* temp = head;
		while(p-- > 1){
			temp = temp->next;
		}
		node* newNode = new node(d);
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

// passing by reference in all delete operation
void deleteHead(node* &head){
	if(head==NULL){
		return;
	}
	node* temp = head->next;
	delete head;
	head = temp;
}

void deleteAtMiddle(node* &head,int p){
	if(head == NULL or p==0) return;

	node* n = head;
	node* prev = head;
	while(p-- > 2){
		prev = prev->next;
		n = n->next;
	}
	n = n->next;
	prev->next = n->next;
	delete n;
}

// passing pointer by value in printing operation
void print(node* head){
	while(head != NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

// Search Operation
// Linear Search
bool search(node* head, int key){
	if(head == NULL){
		return false;
	}
	node* temp = head;
	while(temp != NULL){
		if(temp->data == key)
			return true;
		temp = temp->next;
	}
	return false;
}

//recursively
bool searchRec(node* head, int key){
	if(head == NULL){
		return false;
	}
	if(head->data == key){
		return true;
	}
	return searchRec(head->next, key);
}

int main(){

	node* head = NULL;
	insertAtHead(head,5);
	insertAtHead(head,2);
	insertAtHead(head,1);
	insertAtHead(head,0);
	print(head);
	insertAtMiddle(head,4,3);
	insertAtTail(head,7);
	print(head);

	deleteHead(head);
	print(head);

	deleteAtMiddle(head,3);
	print(head);

	cout<<search(head,5)<<" "<<search(head,0)<<endl;
	cout<<searchRec(head,5)<<" "<<searchRec(head,0)<<endl;

	return 0;
}
