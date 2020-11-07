#include <iostream>
using namespace std;
#define Max 10

class stack {
	int value[Max]; //Array with size of Max (10)
	int top = -1; //Start the top from -1 to sync with array elements during push/pop

public:
	void push(int number) {
		if (top >= Max - 1) { //Max-1 because the elements of array starts from 0 to 9
			cout << "Stack overflow" << endl;
			return;
		}
		else {
			top++; //Increase the value of top because new value has been pushed into the stack
			value[top] = number; 
		}
	}

	void print() {
		if (top >= 0) { 
			cout << "Items in the stack: ";
			for (int i = top; i >= 0; i--) {
				cout << value[i] << " ";
			}
		}
		else {
			cout << "Empty Stack" << endl;
			return;
		}
	}

	void pop() {
		if (top < 0) { //If top is less than 0, it means the Stack is empty 
			cout << "Stack underflow" << endl;
			return;
		}
		else {
			cout << "Popped number is " << value[top] << endl;
			top--; //Decrement the number of top because of pop
		}
	}

	void peek() {
		if (top < 0) {
			cout << "Empty Stack" << endl;
			return;
		}
		else {
			int x = value[top];
			cout << "Peeked number is " << x << endl;
		}
	}

};

int main() {
	stack test;
	test.push(20);
	test.push(40);
	test.push(60);
	test.print();
	cout << endl;
	test.pop();
	test.peek();
	test.print();
}
