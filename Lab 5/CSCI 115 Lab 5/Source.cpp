#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

int getMax(int arr[], int size) {
	int max = arr[1];
	for (int i = 2; i <= size;i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max; 
}

void countingSort(int arr[], int n) {
	int* output = new int[n];
	int* count = new int[n];
	int max = arr[0];

	//To find the largest element in the array 
	for (int i = 1;i < n;i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	//Initialize count array with all zeros 
	for (int i = 0;i <= max;++i) {
		count[i] = 0;
	}

	//Store the count of each element
	for (int i = 0;i < n;i++) {
		count[arr[i]]++;
	}

	for (int i = 1; i <= max;i++) {
		count[i] += count[i - 1];
	}

	for (int i = n - 1;i >= 0;i--) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	for (int i = 0;i < n;i++) {
		arr[i] = output[i];
	}
}

void countingRadix(int arr[], int size, int k) {
	const int base = 10; 
	int* output = new int[size];
	int count[base] = { 0 };

	
	for (int i = 0;i < base;++i) {
		count[i] = 0;
	}
	//Calculate count of elements 
	for (int i = 0;i < size;i++) {
		count[(arr[i] / k) % 10]++;
	}
	//Calculate cummulative count
	for (int i = 1;i < base;i++) {
		count[i] += count[i - 1];
	}
	//Fill up the output array 
	for (int i = size - 1; i >= 0;i--) {
		output[count[(arr[i] / k) % 10] - 1] = arr[i];
		count[(arr[i] / k) % 10]--;
	}
	//Copy the output array to arr[], arr[] contains sorted numbers 
	for (int i = 0;i < size;i++) {
		arr[i] = output[i];
	}
}

void radixSort(int arr[], int size) {
	int max = getMax(arr, size);
	//Use counting sort because Radix Sort requires stable sorting algorithm 
	for (int k = 1;max / k > 0; k *= 10) {
		countingRadix(arr, size, k);
	}
}

void print(int arr[], int n) {
	for (int i = 1; i < n;i++) {
		cout << " " << arr[i];
	}
	cout << endl; 
}

int main() {
	int a[] = { 1,5,6,7,9,5,3,7,8 };
	
	int n = sizeof(a) / sizeof(a[0]);
	
	cout << "Before sorting: ";
	print(a, n);
	cout << endl;
	cout << "After sorting:" << endl;
	cout << " (1) Counting Sort: ";
	srand(time(NULL));
	auto start1 = chrono::high_resolution_clock::now();
	countingSort(a, n);
	print(a, n);
	auto end1 = chrono::high_resolution_clock::now();
	cout << "     Time for Counting Sort: ";
	double time_taken1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
	time_taken1 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken1 << endl;

	srand(time(NULL));
	cout << " (2) Radix Sort: ";
	auto start2 = chrono::high_resolution_clock::now();
	radixSort(a, n);
	print(a, n);
	auto end2 = chrono::high_resolution_clock::now();
	cout << "     Time for Radix Sort: ";
	double time_taken2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
	time_taken2 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken2 << endl;

}