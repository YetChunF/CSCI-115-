//Yet Chun Fong 300376480 
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <chrono>
using namespace std; 

void swap(int arr[], int x, int y) {
	int temp;
	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

//Partition that pick the first element as pivot 
int partition_first(int arr[], int low, int hi) {
	int i = low + 1;
	int pivot = arr[low];

	for (int j = low + 1;j <= hi;j++) {
		if (arr[j] < pivot) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[low], arr[i - 1]);
	return i - 1;
}

//Partition that pick random element as pivot 
int partition_rand(int arr[], int low, int hi) {
	int pivot = low + rand() % (hi - low + 1); //Random pivot
	swap(arr[pivot], arr[low]); //Swap pivot with the first element
	return partition_first(arr, low, hi); //Call the first partition 
}


void quick_median(int arr[], int lo, int hi) {
	if (lo > hi) {
		return;
	}
	int i = lo; 
	int j = hi;
	int pivot = arr[(lo + hi) / 2];

	while (i <= j) {
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i <= j) {
			swap(arr, i, j);
			i++; 
			j--;
		}
	}
	quick_median(arr, lo, j);
	quick_median(arr, i, hi);

}

void quick_first(int arr[], int lo, int hi) {
	if (lo >= hi) {
		return;
	}
	int j = partition_first(arr, lo, hi);
	quick_first(arr, lo, j - 1);
	quick_first(arr, j + 1, hi);
}

void quick_random(int arr[], int lo, int hi) {
	if (lo >= hi) {
		return;
	}
	int j = partition_rand(arr, lo, hi);
	quick_random(arr, lo, j - 1);
	quick_random(arr, j + 1, hi);
}

void print(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		cout << " " << arr[i];
	}
	cout << endl;
}

int main() {
	int arr[] = { 35,7,8,15,32,143,1,6,17,10,3,22,54,111,77,33,12 };
	int arr1[] = { 17,14,10,11,202,4,15,6,8,23,19,12,34,65 };
	int arr2[] = { 43,9,11,32,13,6,25,10,20,110,8,17,21,5,57 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int n2 = sizeof(arr2) / sizeof(arr2[0]);

	cout << "Please select partition: " << endl;
	cout << "Select '1' for First element as pivot" << endl;
	cout << "Select '2' for random element as pivot" << endl;
	cout << "Select '3' for median element as pivot" << endl;
	cout << "Press 0 to exit this program" << endl;
	cout << endl;
	int input;
	cin >> input;

	if (input == 0) {
		cout << "Program Exit" << endl;
		cout << "============================================" << endl;
		return 0;
	}

	if (input == 1) {
		cout << "First element as pivot: " << endl;
		cout << "Before: ";
		print(arr, n);
		srand(time(NULL));
		auto start = chrono::high_resolution_clock::now();
		quick_first(arr, 0, n - 1);
		cout << "After: ";
		print(arr, n);
		auto end = chrono::high_resolution_clock::now();
		cout << "Time for first element: ";
		double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;
		cout << std::fixed << std::setprecision(6) << time_taken << endl;
		cout << "=============================================" << endl;
		return main();
	}

	if (input == 2) {
		cout << "Random element as pivot: " << endl;
		cout << "Before: ";
		print(arr1, n1);
		srand(time(NULL));
		auto start1 = chrono::high_resolution_clock::now();
		quick_random(arr1, 0, n1 - 1);
		cout << "After: ";
		print(arr1, n1);
		auto end1 = chrono::high_resolution_clock::now();
		cout << "Time for random element: ";
		double time_taken1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
		time_taken1 *= 1e-9;
		cout << std::fixed << std::setprecision(6) << time_taken1 << endl;
		cout << "==============================================" << endl;
		return main();
	}

	if (input == 3) {
		cout << "Median element as pivot: " << endl;
		cout << "Before: ";
		print(arr2, n2);
		srand(time(NULL));
		auto start2 = chrono::high_resolution_clock::now();
		quick_median(arr2, 0, n2 - 1);
		print(arr2, n2);
		auto end2 = chrono::high_resolution_clock::now();
		cout << "Time for median element: ";
		double time_taken2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
		time_taken2 *= 1e-9;
		cout << std::fixed << std::setprecision(6) << time_taken2 << endl;
		cout << "===============================================" << endl;
		return main();
	}
	else
	{
		cout << "Error" << endl;
		cout << "===============================================" << endl;
		return main();
	}
	
}
