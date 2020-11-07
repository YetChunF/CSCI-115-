#include <iostream>

using namespace std;

class Heap
{
    public:
    vector<int> Arr;
    Heap();

    void printArray(vector<int> Arr[]);

     //Max heap
    void modifyKeyMax (vector<int> Arr, int n, int i); //Modify index value
    void insert_value_maxHeap (vector<int> Arr, int val); //Adds value at the end of array and calls max_heapify
    void max_heapify(vector<int> Arr, int i); //Maintains the max heap property
    int extract_maximum (vector<int>Arr); //Return the maximum element in heap and swap last element with first element
    void ascendingHeapSort(vector<int> Arr, int n); //Prints the array in ascending order 
    void buildMaxHeap(vector<int> Arr, int n); //Heapifies entire list


    //Min Heap
    void modifyKeyMin (vector<int> Arr, int n, int i); //Modify Index value
    void insert_value_minHeap (vector<int> Arr, int val); // Adds value at the end of array and calls min_heapify
    void min_heapify(vector<int> Arr, int i); //Maintains min heap property
    int extract_minimum (vector<int> Arr); //Return the minimum element in heap and swap last element with first element
    void descendingHeapSort(vector<int> Arr, int n); //Prints the array in descending order 
    void buildMinHeap(vector<int> Arr, int n); //Heapifies entire list


};

