#include <iostream>
using namespace std;

class Node {
public:
	Node(int data) {
		this->data = data;
		this->LeftChild = NULL;
		this->RightChild = NULL;
	};
	int data;
	Node* LeftChild;
	Node* RightChild;

};

class BST {
private:
	Node* root;

public:
	BST() {
		root = NULL;
	}

	Node* getRoot() { return this->root; };

	void printTree(Node* root) {
		if (root == NULL) {
			return; 
		}
		printTree(root->LeftChild);
		printTree(root->RightChild);
		cout << root->data << " ";
	}

	void InsertNode(Node* node, int data) {
		if (node->data > data) {
			//If left node is not empty, then recursively move to left subtree 
			if (node->LeftChild != NULL) {
				InsertNode(node->LeftChild, data);
			}
			else {
				node->LeftChild = new Node(data);
			}
		}
		else { 
			//If right node is not empty, recursively move to right subtrees
			if (node->RightChild != NULL) {
				InsertNode(node->RightChild, data);
			}
			else {
				//Create new node 
				node->RightChild = new Node(data);
			}

		}
	}

	bool FindNode(Node* node, int data) {
		if (node == NULL) {
			return false; 
		}
		else if (data == node->data) {
			return true; 
		}
		else if (data <= node->data) {
			return FindNode(node->LeftChild, data);
		}
		else {
			return FindNode(node->RightChild, data);
		}
	}

	int Largest(Node* node) {
		while (node->RightChild != NULL) {
			node = node->RightChild;
		}

		return node->data;
	}

	//Utility function to perform print function 
	void print() {
		printTree(root);
		cout << endl;
	}
	//Utility function to perform insertion function 
	void Insertion(int key) {
		if (root == NULL) {
			root = new Node(key);
		}
		else {
			InsertNode(root, key);
		}
	}
	//Utility function to perform Largest function 
	void FinLarge() {
		cout << Largest(root) << endl;
	}
	//Utility function to perfrom FindNode function
	void Search(int data) {
		int temp = FindNode(root, data);
		if (temp == true) {
			cout << data << " found in the BST" << endl;
		}
		if (temp == false) {
			cout << data << " not found in the BST" << endl;
		}
	}

};

int main() {
	BST b; 
	b.Insertion(7);
	b.Insertion(20);
	b.Insertion(8);
	b.Insertion(9);
	b.Insertion(6);
	b.Insertion(1);
	b.Insertion(19);
	b.Insertion(15);
	b.Insertion(2);
	b.Insertion(10);
	cout << "Post- Order: ";
	b.print();
	cout << "Largest element in the list: ";
	b.FinLarge();
	b.Search(12);
	b.Search(10);

	
	
	

	
}
