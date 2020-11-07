#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
}; //Structure to store integer data and pointer next

class List {
private: //Pointer head node to point to the first front node
	Node* head;

public:
	List() {
		head = NULL;
	}

	//Print all elements in the linked list
	void print() {
		Node* h = head;
		while (h != NULL) { //Keep going if the h pointer is not NULL
			cout << " " << h->data;
			h = h->next;
		}
	}

	//Insert to front function
	void insertFront(int number) {
		Node* a = new Node;
		a->data = number;
		a->next = head;
		head = a;
	}

	//Delete the front node function
	void deleteFront() {
		if (head == NULL) {
			return;
		}
		else {
			Node* b = head; //New pointer points to the head 
			head = head->next; //Update/move head to the next Node 
			delete b; //Delete the pointer that point to the head
		}
	}

	//Delete the last node function
	void deleteLast() {
		Node* c = head;
		Node* prev = NULL;
		if (head == NULL) {
			cout << "Linked List Empty" << endl;
			return;
		}

		if (head->next == NULL) {
			head = NULL;
			delete c;
			return;
		}

		while (c->next != NULL) {
			prev = c; //Assign prev to the c node 
			c = c->next; // Continue moving the c node 
		}
		prev->next = NULL;
	}


};

int main() {
	List test;
	test.insertFront(60);
	test.insertFront(40);
	test.insertFront(20);
	cout << "Items in the list: ";
	test.print();
	cout << endl;
	test.deleteFront();
	cout << "Items in the linked list after deleting the first element: ";
	test.print();
	cout << endl;
	test.deleteLast();
	cout << "Items in the linked list after deleting the last element: ";
	test.print();
}

