#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std; 

//Brute Force Solution 
bool bruteForce(vector<int> vec, int target) { //Time = O(n2) because it have to go through the array again and again
	int n = vec.size();

	for (int i = 0; i < n;i++) { //Remain
		for (int j = i + 1; j < n;j++) { //Iterate through the vector to find addition 
			int sum = vec[i] + vec[j]; //Sum i and j check if it matched with target

			if (sum == target) { //If yes return true 
				return true; 
			}
		}
	}//After tested all combination, if not found, then return false. 
	return false;
}

bool Efficient(vector<int>vec, int target) { //Time = O(n), HashTable used O(1) to find the difference. Only go through the vector once.  
	unordered_map<int, int> HashTable; //Declare a Hash Table
	int n = vec.size(); 
	for (int i = 0; i < n;i++) {
		int diff = target - vec[i]; //The difference between target and value of vector[i]
		if (HashTable.count(diff)) { //Search for the difference inside Hash Table
			return true; //If the value of 'difference', is found in the Hash Table then return true
		}
		else {
			HashTable[vec[i]] = i; //If not, then we will place the number in Hash Table
		}   
	}
	return false; //If iterated through the array and no match can be found, then return false. 
}

int main() {
	vector<int> test = { 4,1,12,6,3,5,9,11,34,2,3,7,9 };
	vector<int> test2 = { 1,1,1,1 };
	cout << bruteForce(test, 4) << endl;
	cout << Efficient(test, 9) << endl;
}