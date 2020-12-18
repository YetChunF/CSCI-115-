#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <iomanip>
#include <random>
using namespace std;

//Utility function for swapping (Insertion Sort)
void in_swap(vector<int>& a, int b, int c)
{
	int temp = a[b];
	a[b] = a[c];
	a[c] = temp;
}

//Utility function for swapping with pointers (Quick Sort)
void quick_swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

//Utility function to find the largest element (Radix Sort)
int getMax(int arr[], int size) {
	int max = arr[1];
	for (int i = 2; i <= size;i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}


/*___________________INSERTION SORT_________________________*/
void InsertionSort(vector<int>& a) {
	for (int j = 1; j < a.size(); j++) { //pass a vector and its first and last index 
		int i = j - 1;
		while (i >= 0 && a[i] > a[j]) {
			in_swap(a, i, j); //Swap i and j if a[i] is larger than a[j] 
			i = i - 1;
			j = j - 1;
		}
	}
}


/*___________________SELECTION SORT_________________________*/
void Selection_sort(vector<int>& vec) {
	for (int i = 0; i < vec.size() - 1;i++) {
		int min = i; //Min will start from 0
		for (int j = i + 1; j < vec.size();j++) {
			if (vec[j] < vec[min]) { // j will iterate and element that are smaller than min 
				min = j; //If found, update min
			}
		} //After finding the minimum element, swap with vec[i]
		int temp = vec[i];
		vec[i] = vec[min];
		vec[min] = temp;
	}
}


/*___________________BUBBLE SORT_________________________*/
void BubbleSort(vector<int>& A) {
	int i, j;
	bool swapped;

	for (i = 0; i < A.size() - 1; i++) {
		swapped = false;
		for (j = 0; j < A.size() - i - 1; j++) {
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}


/*___________________MERGE SORT_________________________*/
void merge(vector <int>& a, int l, int m, int r) //merge two vector into one sorted vector
{
	int n1 = m - l + 1;//size of left vector
	int n2 = r - m;//size of right vector

	vector <int> auxl(n1); //create temp vector for left vector
	vector <int> auxr(n2);//create temp vector for right vector

	for (int o = 0; o < n1; o++)//copy left vector
	{
		auxl[o] = a[l + o];
	}
	for (int u = 0; u < n2; u++)//copy right vector
	{
		auxr[u] = a[m + u + 1];
	}
	int i = 0; //index in left vector
	int j = 0; //index in right vector
	int k = l; //index in the original vector
	while (i < n1 && j < n2) //while haven't reached the end of any of both vectors
	{
		//Compare the elements of both vectors, copy the smaller element into the result vector
		//move to the next elements and continue comparing
		if (auxl[i] <= auxr[j])
		{
			a[k] = auxl[i];
			i++;
		}
		else
		{
			a[k] = auxr[j];
			j++;
		}
		k++;
	}
	while (i < n1) //while reached the end of right vector but still have elements in left vector
	//copy all the remaining elements in left vector to the original vector
	{
		a[k] = auxl[i];
		i++;
		k++;
	}
	while (j < n2) //while reached the end of left vector but still have elements in right vector
	//copy all the remaining elements in right vector to the original vector
	{
		a[k] = auxr[j];
		j++;
		k++;
	}
}
void mergeSort(vector <int>& a, int l, int r)
{
	if (l < r) //check if left < right. If left >= right, then return.
	//when the size of the sequences is 1, l=r, return. 
	{
		int mid = (l + r) / 2; //calculate middle element. The result always runs down.
		mergeSort(a, l, mid); //left subsequences from left to mid, sort the left subsequences recursively using merge sort
		mergeSort(a, mid + 1, r); //right subsequences from mid+1 to right, the right subsequences recursively using merge sort
		merge(a, l, mid, r); //merge the two sorted subsequences
	}
	else return;
}


/*___________________QUICK SORT_________________________*/
//pivot as the first element
int partition(int a[], int l, int h) {
	int pivot = a[l]; //pivot as the first element
	int i = (l + 1);
	for (int j = l + 1; j <= h; j++) {
		if (a[j] < pivot) {
			quick_swap(&a[i], &a[j]);
			i++;
		}
	}
	quick_swap(&a[l], &a[i - 1]);
	return(i - 1);
}

//random pivot
int randomPartition(int a[], int l, int h) {
	int p;
	int i;
	p = l + rand() % (h - l + 1); //randomizing pivot point
	quick_swap(&a[l], &a[p]); //swap the l with high so when we call the partition function it takes the new radomized pivot value
	return partition(a, l, h); //calling the partition function
}

//partition for median pivot
int medianPartition(int a[], int l, int h) {
	int n = sizeof(a) / sizeof(a[0]); //size of the array
	int m = a[(n / 2)];
	int median;
	if (m < l)
		median = l;
	else
		median = m;
	if (median > h)
		median = h;
	quick_swap(&a[l], &a[median]);
	return partition(a, l, h);
}

//quicksort for first element as pivot
void quickSort_first(int a[], int l, int h) {
	if (l < h) {
		int i = partition(a, l, h);
		quickSort_first(a, l, i - 1);
		quickSort_first(a, i + 1, h);
	}
}

//quicksort for random pivot
void quickSort_random(int a[], int l, int h) {
	if (l < h) {
		int i = randomPartition(a, l, h);
		quickSort_random(a, l, i - 1);
		quickSort_random(a, i + 1, h);
	}
}

//quicksort for median of first, middle and last pivot
void quickSort_med(int a[], int l, int h) {
	if (l < h) {
		int i = medianPartition(a, l, h);
		quickSort_med(a, l, i - 1);
		quickSort_med(a, i + 1, h);
	}
}



/*___________________HEAP SORT_________________________*/
//Max Heapify function
void max_Heapify(vector<int>& a, int n, int i) {
	int l = (2 * i + 1);
	int r = (2 * i + 2);
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

void Heap_sort(vector<int>& a) {
	int n = a.size();
	buildMaxHeap(a, n);
	int size = n;

	for (int i = n - 1; i >= 0;i--) {
		swap(a[0], a[i]); //Swap last node and first node 
		size--; //Decrease size so that the last node of the vector will be the previous of the last node
		max_Heapify(a, i, 0); //After swapping, must sort the vector according to Max-Heap properties 
	}
}


/*___________________COUNTING SORT_________________________*/
void countingSort(vector<int>& a, int n) {
	int* aux = new int[n];
	int max = a[0];

	//Find the largest element to set it as range
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}

	int* count = new int[max];

	//Assign all element in count array to 0
	for (int i = 0; i <= max; i++) {
		count[i] = 0;
	}

	//Count the frequency of each element
	for (int i = 0; i < n; i++) {
		count[a[i]]++;
	}

	//Count the cumulative sum of the array
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	//Place the elements in count in sorted order
	for (int i = n - 1; i >= 0; i--) {
		aux[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	//Copy the sorted array into the original array
	for (int i = 0; i < n; i++) {
		a[i] = aux[i];
	}
}


/*___________________RADIX SORT_________________________*/
void countingRadix(int arr[], int size, int k) { //Counting sort that are specifically for Radix Sort
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


/*___________________PRINT FUNCTION_________________________*/
void printAll(vector<int> a) {
	for (int i = 0; i < 100;i++) {
		cout << " " << a[i];
	}
	cout << endl;
}


int main() {
	int size1 = 4000;

	cout << "Input size: " << size1 << endl;
	cout << endl;

	//Insertion Sort
	cout << "Insertion Sort: " << endl;
	vector<int> insertion1(size1);
	srand(time(NULL));
	for (int i = 0;i < size1;i++) {
		insertion1[i] = rand() % size1 + 1;
	}
	auto insertion_start1 = chrono::high_resolution_clock::now();
	InsertionSort(insertion1);
	auto insertion_end1 = chrono::high_resolution_clock::now();

	cout << "Time taken for average case: ";
	double insertion_time_taken1 = chrono::duration_cast<chrono::milliseconds>(insertion_end1 - insertion_start1).count();
	insertion_time_taken1 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << insertion_time_taken1 << endl;

	vector<int>insertion2(size1);
	srand(time(NULL));
	for (int i = 0; i < size1;i++) {
		insertion2[i] = rand() % size1 + 1;
	}
	sort(insertion2.begin(), insertion2.end());
	auto insertion_start2 = chrono::high_resolution_clock::now();
	InsertionSort(insertion2);
	auto insertion_end2 = chrono::high_resolution_clock::now();

	cout << "Time taken for best case: ";
	double insertion_time_taken2 = chrono::duration_cast<chrono::milliseconds>(insertion_end2 - insertion_start2).count();
	insertion_time_taken2 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << insertion_time_taken2 << endl;

	vector<int>insertion3(size1);
	srand(time(NULL));
	for (int i = 0; i < size1;i++) {
		insertion3[i] = rand() % size1 + 1;
	}
	sort(insertion3.begin(), insertion3.end());
	reverse(insertion3.begin(), insertion3.end());

	auto insertion_start3 = chrono::high_resolution_clock::now();
	InsertionSort(insertion3);
	auto insertion_end3 = chrono::high_resolution_clock::now();

	cout << "Time taken for worst case: ";
	double insertion_time_taken3 = chrono::duration_cast<chrono::milliseconds>(insertion_end3 - insertion_start3).count();
	insertion_time_taken3 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << insertion_time_taken3 << endl;
	cout << endl;


	//Selection Sort
	cout << "Selection Sort: " << endl;
	//First data set is random input
	vector<int> selection1(size1);
	srand(time(NULL));
	for (int i = 0; i < size1;i++) {
		selection1[i] = rand() % size1 + 1;
	}

	//cout << "First 100 sorted output for random vector: " << endl;
	auto Selection_start1 = chrono::high_resolution_clock::now();
	Selection_sort(selection1);
	auto Selection_end1 = chrono::high_resolution_clock::now();
	//printAll(selection1);
	cout << "Time taken for random vector: ";
	double Selection_time_taken1 = chrono::duration_cast<chrono::milliseconds>(Selection_end1 - Selection_start1).count();
	Selection_time_taken1 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << Selection_time_taken1 << endl;


	//Second data set is pre sorted array
	vector<int> selection2(size1);
	srand(time(NULL));
	for (int i = 0; i < size1;i++) {
		selection2[i] = rand() % size1 + 1;
	}
	sort(selection2.begin(), selection2.end());  //Sort the list first before the timer  
	//cout << "First 100 sorted output for pre-sorted vector: " << endl;
	auto Selection_start2 = chrono::high_resolution_clock::now();
	Selection_sort(selection2); //This is the one we are measuring time with 
	auto Selection_end2 = chrono::high_resolution_clock::now();
	//printAll(selection2);
	cout << "Time taken for pre-sorted vector: ";
	double Selection_time_taken2 = chrono::duration_cast<chrono::milliseconds>(Selection_end2 - Selection_start2).count();
	Selection_time_taken2 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << Selection_time_taken2 << endl;


	//Third data set is reversed array
	vector<int> selection3(size1);
	srand(time(NULL));
	for (int i = 0; i < size1;i++) {
		selection3[i] = rand() % size1 + 1;
	}
	sort(selection3.begin(), selection3.end());//Sort the array first 
	reverse(selection3.begin(), selection3.end()); //Then reverse the sorted array 
	//cout << "First 100 sorted output for reversed vector: " << endl;
	auto Selection_start3 = chrono::high_resolution_clock::now();
	Selection_sort(selection3);
	auto Selection_end3 = chrono::high_resolution_clock::now();
	//printAll(selection3);
	cout << "Time taken for reversed vector: ";
	double Selection_time_taken3 = chrono::duration_cast<chrono::milliseconds>(Selection_end3 - Selection_start3).count();
	Selection_time_taken3 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << Selection_time_taken3 << endl;
	cout << endl;

	// First test of BubbleSort
	cout << "Bubble Sort: " << endl;
	//cout << "First test of BubbleSort\n"
		//<< "Average case: O(nlogn)" << endl;
	vector<int> vec1(size1);
	srand(time(NULL));
	for (int i = 0; i < size1; i++)
		vec1[i] = rand() % size1 + 1;

	auto Bubble_start1 = chrono::high_resolution_clock::now(); // start the chronometer
	BubbleSort(vec1);
	auto Bubble_end1 = chrono::high_resolution_clock::now(); // stop the chronometer
	//printAll(vec1);
	cout << "Time taken for average case: ";
	double Bubble_time_taken1 = chrono::duration_cast<chrono::milliseconds>(Bubble_end1 - Bubble_start1).count();
	Bubble_time_taken1 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << Bubble_time_taken1 << endl;


	// Second test of BubbleSort
	//cout << "Second test of BubbleSort\n"
		//<< "Best case: O(n)" << endl;
	vector<int> vec2(size1);
	srand(time(NULL));
	for (int i = 0; i < size1; i++)
		vec2[i] = rand() % size1 + 1;

	sort(vec2.begin(), vec2.end()); // list already sorted to test best case scenario
	auto Bubble_start2 = chrono::high_resolution_clock::now(); // start the chronometer
	BubbleSort(vec2);
	auto Bubble_end2 = chrono::high_resolution_clock::now(); // stop the chronometer
	//printAll(vec2);
	cout << "Time taken best case: ";
	double Bubble_time_taken2 = chrono::duration_cast<chrono::milliseconds>(Bubble_end2 - Bubble_start2).count();
	Bubble_time_taken2 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << Bubble_time_taken2 << endl;


	// Third test of BubbleSort
	//cout << "Third test of BubbleSort\n"
		//<< "Worst case: O(n^2)" << endl;
	vector<int> vec3(size1);
	srand(time(NULL));
	for (int i = 0; i < size1; i++)
		vec3[i] = rand() % size1 + 1;

	sort(vec3.begin(), vec3.end());
	reverse(vec3.begin(), vec3.end()); // reverse sorted to test worst case scenario
	auto Bubble_start3 = chrono::high_resolution_clock::now(); // start the chronometer
	BubbleSort(vec3);
	auto Bubble_end3 = chrono::high_resolution_clock::now(); // stop the chronometer
	//printAll(vec2);
	cout << "Time taken for worst case: ";
	double Bubble_time_taken3 = chrono::duration_cast<chrono::milliseconds>(Bubble_end3 - Bubble_start3).count();
	Bubble_time_taken3 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << Bubble_time_taken3 << endl;
	cout << endl;

	//Merge Sort algorithm 
	cout << "Merge Sort: " << endl;

	vector<int> merge1(size1);
	srand(time(NULL));
	for (int i = 0; i < size1; i++) {
		merge1[i] = rand() % size1 + 1;
	}
	auto merge_start1 = chrono::high_resolution_clock::now();
	mergeSort(merge1, 0, merge1.size() - 1);
	auto merge_end1 = chrono::high_resolution_clock::now();

	cout << "Time taken for random vector: ";
	double merge_time_taken1 = chrono::duration_cast<chrono::milliseconds>(merge_end1 - merge_start1).count();
	merge_time_taken1 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << merge_time_taken1 << endl;


	vector<int> merge2(size1);
	srand(time(NULL));
	for (int i = 0; i < size1; i++) {
		merge2[i] = rand() % size1 + 1;
	}
	sort(merge2.begin(), merge2.end());
	auto merge_start2 = chrono::high_resolution_clock::now();
	mergeSort(merge2, 0, merge2.size() - 1);
	auto merge_end2 = chrono::high_resolution_clock::now();

	cout << "Time taken for pre-sorted vector: ";
	double merge_time_taken2 = chrono::duration_cast<chrono::milliseconds>(merge_end2 - merge_start2).count();
	merge_time_taken2 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << merge_time_taken2 << endl;

	vector<int> merge3(size1);
	srand(time(NULL));
	for (int i = 0; i < size1; i++) {
		merge3[i] = rand() % size1 + 1;
	}
	sort(merge3.begin(), merge3.end());
	reverse(merge3.begin(), merge3.end());

	auto merge_start3 = chrono::high_resolution_clock::now();
	mergeSort(merge3, 0, merge3.size() - 1);
	auto merge_end3 = chrono::high_resolution_clock::now();

	cout << "Time taken for reversed vector: ";
	double merge_time_taken3 = chrono::duration_cast<chrono::milliseconds>(merge_end3 - merge_start3).count();
	merge_time_taken3 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << merge_time_taken3 << endl;
	cout << endl;


	//Quick Sort
	cout << "Quick Sort: " << endl;
	int* quick1 = new int[size1];
	srand(time(NULL));
	for (int i = 0; i < size1;i++) {
		quick1[i] = rand() % size1 + 1;
	}
	auto quick_start1 = chrono::high_resolution_clock::now();
	quickSort_first(quick1, 0, size1);
	auto quick_end1 = chrono::high_resolution_clock::now();
	cout << "Time taken for random vector: ";
	double quick_time_taken1 = chrono::duration_cast<chrono::milliseconds>(quick_end1 - quick_start1).count();
	quick_time_taken1 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << quick_time_taken1 << endl;

	int* quick2 = new int[size1];
	srand(time(NULL));
	for (int i = 0; i < size1;i++) {
		quick2[i] = rand() % size1 + 1;
	}
	quickSort_first(quick2, 0, size1);
	auto quick_start2 = chrono::high_resolution_clock::now();
	quickSort_first(quick2, 0, size1);
	auto quick_end2 = chrono::high_resolution_clock::now();
	cout << "Time taken for sorted vector: ";
	double quick_time_taken2 = chrono::duration_cast<chrono::milliseconds>(quick_end2 - quick_start2).count();
	quick_time_taken2 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << quick_time_taken2 << endl;

	int* quick3 = new int[size1];
	srand(time(NULL));
	for (int i = 0; i < size1;i++) {
		quick3[i] = rand() % size1 + 1;
	}
	quickSort_first(quick3, 0, size1);
	reverse(quick3, quick3 + size1);
	auto quick_start3 = chrono::high_resolution_clock::now();
	quickSort_first(quick3, 0, size1);
	auto quick_end3 = chrono::high_resolution_clock::now();
	cout << "Time taken for sorted vector: ";
	double quick_time_taken3 = chrono::duration_cast<chrono::milliseconds>(quick_end3 - quick_start3).count();
	quick_time_taken3 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << quick_time_taken3 << endl;
	cout << endl;


	cout << "Heap Sort: " << endl;

	//Heap Sort 
	 //First data set is random input
	vector<int> heap1(size1);
	srand(time(NULL));
	for (int i = 0; i < size1;i++) {
		heap1[i] = rand() % size1 + 1;
	}
	//cout << "First 100 sorted output for random vector: " << endl;
	auto Heap_start1 = chrono::high_resolution_clock::now();
	Heap_sort(heap1);
	auto Heap_end1 = chrono::high_resolution_clock::now();
	//printAll(heap1);
	cout << "Time taken for random vector: ";
	double Heap_time_taken1 = chrono::duration_cast<chrono::milliseconds>(Heap_end1 - Heap_start1).count();
	Heap_time_taken1 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << Heap_time_taken1 << endl;


	//Second data set is pre sorted array
	vector<int> heap2(size1);
	srand(time(NULL));
	for (int i = 0; i < size1;i++) {
		heap2[i] = rand() % size1 + 1;
	}
	Heap_sort(heap2); //Sort the list first before the timer 
	//cout << "First 100 sorted output for pre-sorted vector: " << endl;
	auto Heap_start2 = chrono::high_resolution_clock::now();
	Heap_sort(heap2); //This is the one we are measuring time with 
	auto Heap_end2 = chrono::high_resolution_clock::now();
	//printAll(heap2);
	cout << "Time taken for pre-sorted vector: ";
	double Heap_time_taken2 = chrono::duration_cast<chrono::milliseconds>(Heap_end2 - Heap_start2).count();
	Heap_time_taken2 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << Heap_time_taken2 << endl;


	//Third data set is reversed array
	vector<int> heap3(size1);
	srand(time(NULL));
	for (int i = 0; i < size1;i++) {
		heap3[i] = rand() % size1 + 1;
	}
	Heap_sort(heap3); //Sort the array first 
	reverse(heap3.begin(), heap3.end()); //Then reverse the sorted array 
	//cout << "First 100 sorted output for reversed vector: " << endl;
	auto Heap_start3 = chrono::high_resolution_clock::now();
	Heap_sort(heap3);
	auto Heap_end3 = chrono::high_resolution_clock::now();
	//printAll(heap3);
	cout << "Time taken for reversed vector: ";
	double Heap_time_taken3 = chrono::duration_cast<chrono::milliseconds>(Heap_end3 - Heap_start3).count();
	Heap_time_taken3 *= 1e-3;
	cout << std::fixed << std::setprecision(3) << Heap_time_taken3 << endl;
	cout << endl;


	//Counting Sort
	cout << "Counting Sort: " << endl;
	vector<int> count1(size1);

	for (int i = 0; i < size1; i++) {
		int j = (rand()); //Multiple digit number
		//int j = (rand() % 10);  //Single digit number 
		count1.push_back(j);
	}

	auto counting_start = chrono::high_resolution_clock::now();
	srand(time(NULL));
	countingSort(count1, size1);
	auto counting_end = chrono::high_resolution_clock::now();
	double counting_time = chrono::duration_cast<chrono::milliseconds>(counting_end - counting_start).count();
	cout << "Time taken: " << counting_time << endl;
	cout << endl;


	//Radix Sort 
	cout << "Radix Sort: " << endl;
	int* radix1 = new int[size1];

	srand(time(NULL));
	for (int i = 0; i < size1;i++) {
		radix1[i] = rand() % size1 + 1;
	}

	auto radix_start1 = chrono::high_resolution_clock::now();
	srand(time(NULL));
	radixSort(radix1, size1);
	auto radix_end1 = chrono::high_resolution_clock::now();
	cout << "Time Taken for Radix Sort: " << endl;
	double radix_time_taken = chrono::duration_cast<chrono::milliseconds>(radix_end1 - radix_start1).count();
	radix_time_taken *= 1e-3;
	cout << std::fixed << std::setprecision(3) << radix_time_taken << endl;
}




