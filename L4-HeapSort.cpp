#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Heap {
private:
	vector<int> a;

	int parent(int i) {
		return (i - 1) / 2;
	}

	int left(int i) {
		return(2 * i + 1);
	}

	int right(int i) {
		return(2 * i + 2);
	}
public:

	void printAll(vector<int> a, int n) {
		for (int i = 0; i < n;i++) {
			cout << " " << a[i];
		}
		cout << endl;
	}

	//Max Heap
	void max_Heapify(vector<int>& a, int n, int i) {
		int l = left(i);
		int r = right(i);
		int largest = i;

		if (l<n && a[l]>a[i]) { //If left child is larger than parent node
			largest = l; // Let left child to be the largest
		}
		if (r<n && a[r]> a[largest]) { //If right child is larger than the 'largest' node
			largest = r; // Let right child to be the largest
		}

		if (largest != i) { //If largest has been changed, and not equal to i 
			swap(a[i], a[largest]); //Swap the i node and largest node (Swap parent node with child node)
			max_Heapify(a, n, largest); //Heapify the swapped node
		}
	}

	void buildMaxHeap(vector<int>& a, int n) {
		for (int i = n / 2 - 1; i >= 0; i--) { //Find the last leaf node in the heap tree 
			max_Heapify(a, n, i); //Heapify the tree from that node
		}
	}

	void Ascending(vector<int>& a, int n) {
		buildMaxHeap(a, n);
		int size = n;

		for (int i = n - 1; i >= 0;i--) {
			swap(a[0], a[i]); //Swap last node and first node 
			size--; //Decrease size so that the last node of the vector will be the previous of the last node
			max_Heapify(a, i, 0); //After swapping, must sort the vector according to Max-Heap properties 
		}
	}

	void insertMax(vector<int>& a, int& n, int data) {
		a.push_back(data);
		//n = n + 1; (This is the code that caused the pop up of error message mentioned in the report)
		max_Heapify(a, n, 0);
	}

	void modifyMax(vector<int>& a, int i, int newVal) {
		a[i] = newVal;
		while (i != 0 && a[parent(i)] > a[i]) {
			swap(a[i], a[parent(i)]);
			i = parent(i);
		}
	}

	int extractMax(vector<int>& a, int n) {
		int temp = a.back();
		a.pop_back();
		return temp;
	}

	int getMax(vector<int>& a, int n) {
		int temp = a.back();
		return temp;
	}

	//Min Heap
	void min_Heapify(vector<int>& a, int n, int i) {
		int l = left(i);
		int r = right(i);
		int smallest = i;

		if (l < n && a[l] < a[i]) { //Similar to Max-Heap, but Min-Heap will check if the left child is smaller than parent node
			smallest = l; // If yes, the smallest node will be assign to left child node 
		}
		if (r < n && a[r] < a[smallest]) { // Check if the right child is smaller than smallest node
			smallest = r; // If yes, then assign smallest to the right child node 
		}
		if (smallest != i) { //After checking both conditions, if the smallest node is not equal to i
			swap(a[i], a[smallest]); // Then swap the parent node with child node 
			min_Heapify(a, n, smallest); //Then recursively heapify the tree 
		}
	}

	void buildMinHeap(vector<int>& a, int n) {
		for (int i = n / 2 - 1;i >= 0;i--) {
			min_Heapify(a, n, i);
		}
	}

	void Descending(vector<int>& a, int n) {
		buildMinHeap(a, n);
		int size = n;

		for (int i = n - 1; i >= 0;i--) {
			swap(a[0], a[i]); //Swap last node and root node because must delete from right to left.
			size--; // Reduce the size of heap tree, so that the heap tree can be sorted properly. 
			min_Heapify(a, i, 0); //Heapify the swapped root node to proper position
		}
	}

	void insertMin(vector<int>& a, int& n, int data) {
		a.push_back(data);
		//n = n + 1; (This is the line of code that caused the error message pop up mentioned in the lab report) 
		min_Heapify(a, n, 0);
	}

	void modifyMin(vector<int>& a, int i, int newVal) {
		a[i] = newVal;
		while (i != 0 && a[parent(i)] < a[i]) {
			swap(a[i], a[parent(i)]);
			i = parent(i);
		}
	}

	int extractMin(vector<int>& a, int n) {
		int temp = a.back();
		a.pop_back();
		return temp;
	}

	int getMin(vector<int>& a, int n) {
		int temp = a.back();
		return temp;
	}
};

int main() {
	Heap h;
	vector<int> test = { 4,3,2,6 };
	int n = test.size();

	cout << "Enter 0 for Ascending, 1 for Descending, 2 for Exit the Program: " << endl;
	int input;
	cin >> input;

	if (input == 0) {
		//Max Heap, Ascending order
		cout << "Input: ";
		h.printAll(test, n);
		cout << "Input Element: 9" << endl;
		h.insertMax(test, n, 9);
		h.Ascending(test, n);
		cout << "Sorted Heap: ";
		h.printAll(test, n);
		cout << "Extract Max: ";
		cout << h.extractMax(test, n) << endl;
		cout << "Sorted Heap: ";
		h.printAll(test, n);
		cout << "============================================================" << endl;
		return main();
	}

	if (input == 1) {
		//Min Heap, Descending order
		cout << "Input: ";
		h.printAll(test, n);
		cout << "Input Element: 9" << endl;
		h.insertMin(test, n, 9);
		h.Descending(test, n);
		cout << "Sorted Heap: ";
		h.printAll(test, n);
		cout << "Extract Min: ";
		cout << h.extractMin(test, n) << endl;
		cout << "Sorted Heap: ";
		h.printAll(test, n);
		cout << "============================================================" << endl;
		return main();
	}

	if (input == 2) {
		cout << "Program exit" << endl;
		cout << "============================================================" << endl;
		return 0; 
	}

	else {
		cout << "Error" << endl;
		return main();
	}
}
