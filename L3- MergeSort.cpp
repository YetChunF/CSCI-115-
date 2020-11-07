#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <iomanip>

using namespace std; 
#define MAX 20000

//Function to swap values 
void exchange(int arr[], int x, int y) {
	int temp = arr[x]; 
	arr[x] = arr[y];
	arr[y] = temp; 
}

//Sort the first half of the array only 
void halfSort(int arr[], int n)
{
	sort(arr, arr + n / 2);
	sort(arr + n / 2, arr + n, greater<int>());
}

//Reverse the values of array 
void reverseArray(int arr[], int n) {
	reverse(arr, arr + n);
}


//Selection Sort 
void selection(int arr[], int n) {
    int i, j, min;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        exchange(arr, min, i);
    }
}

//Merge Sort 
void Merge(int arr[], int lo, int mid, int hi) {
	 int n1 = mid - lo + 1;
	 int n2 = hi - mid;

	 int* left = new int[n1];
	 int* right = new int[n2];
	int i, j, k;

	for (i = 0; i < n1; i++) {
		left[i] = arr[lo + i];
	}
	for (j = 0; j < n2; j++) {
		right[j] = arr[mid + 1 + j];
	}
	i = 0; j = 0; k = lo;
	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		}
		else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = left[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = right[j];
		j++;
		k++;
	}
}
void MergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
}

//Print function
void printArray(int arr[]) {
	int i;
	for (i = 0; i < 20; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int size = MAX;
	cout << "Input: " << size << endl;
	cout << endl;
	//Selection Sort 
	//Sorted Array
	cout << "Selection Sort:" << endl;
	int* sorted1 = new int[size]; 
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		sorted1[i] = rand() % size + 1;
	}
	MergeSort(sorted1, 0, size-1);
	auto start1 = chrono::high_resolution_clock::now();
	selection(sorted1, size-1);
	cout << "Sorted: " << endl;
	printArray(sorted1);
	cout << endl;
	auto end1 = chrono::high_resolution_clock::now();
	cout << "Time for sorted list: ";
	double time_taken1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
	time_taken1 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken1 << endl;
	delete sorted1;
	cout << endl;

	//Half Sorted Array
	int* half1 = new int[size]; 
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		half1[i] = rand() % size + 1;
	}
	halfSort(half1, size-1);
	auto start2 = chrono::high_resolution_clock::now();
	selection(half1, size-1);
	cout << "Half Sorted: " << endl;
	printArray(half1);
	cout << endl;
	auto end2 = chrono::high_resolution_clock::now();
	cout << "Time for half sorted list: ";
	double time_taken2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
	time_taken2 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken2 << endl;
	delete half1;
	cout << endl;

	//Reversed Array
	int* reverse1 = new int[size]; 
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		reverse1[i] = rand() % size + 1;
	}
	MergeSort(reverse1, 0, size - 1);
	reverseArray(reverse1, size-1);
	auto start3 = chrono::high_resolution_clock::now();
	selection(reverse1, size);
	cout << "Reverse: " << endl;
	printArray(reverse1);
	cout << endl;
	auto end3 = chrono::high_resolution_clock::now();
	cout << "Time for reverse list: ";
	double time_taken3 = chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count();
	time_taken3 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken3 << endl;
	delete reverse1;
	cout << endl;
	cout << "===================================================" << endl;
	//Merge Sort 
	//Sorted Array
	cout << "Merge Sort: " << endl;
	int* sorted2 = new int[size]; //Sorted List
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		sorted2[i] = rand()%size + 1;
	}
	MergeSort(sorted2, 0, size-1);
	auto start4 = chrono::high_resolution_clock::now();
	MergeSort(sorted2, 0, size-1);
	cout << "Sorted: " << endl;
	printArray(sorted2);
	cout << endl;
	auto end4 = chrono::high_resolution_clock::now();
	cout << "Time for sorted list: ";
	double time_taken4 = chrono::duration_cast<chrono::nanoseconds>(end4 - start4).count();
	time_taken4 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken4 << endl;
	delete sorted2;
	cout << endl;

	//Half Sorted Array 
	int* half2 = new int[size]; 
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		half2[i] = rand() % size + 1;
	}
	halfSort(half2, size - 1);
	auto start5 = chrono::high_resolution_clock::now();
	MergeSort(half2, 0, size - 1);
	cout << "Half Sorted: " << endl;
	printArray(half2);
	cout << endl;
	auto end5 = chrono::high_resolution_clock::now();
	cout << "Time for half sorted list: ";
	double time_taken5 = chrono::duration_cast<chrono::nanoseconds>(end5 - start5).count();
	time_taken5 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken5 << endl;
	delete half2;
	cout << endl;

	//Reverse 
	int* reverse2 = new int[size];  
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		reverse2[i] = rand() % size + 1;
	}
	MergeSort(reverse2, 0, size - 1);
	reverseArray(reverse2, size - 1);
	auto start6 = chrono::high_resolution_clock::now();
	MergeSort(reverse2, 0, size - 1);
	cout << "Reverse: " << endl;
	printArray(reverse2);
	cout << endl;
	auto end6 = chrono::high_resolution_clock::now();
	cout << "Time for reversed list: ";
	double time_taken6 = chrono::duration_cast<chrono::nanoseconds>(end6 - start6).count();
	time_taken6 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken6 << endl;
	delete reverse2;
	cout << endl;



	
}
