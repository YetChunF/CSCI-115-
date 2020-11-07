//YET CHUN FONG 300376480

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class HashMap {
private:
	static const int tableSize = 4001;
	string key;
	string HashTable[tableSize];
	float update[tableSize];
	float cost[tableSize];

public:
	HashMap();
	~HashMap();
	int hash(string key);
	void updates(string word);

	int temp = 0;
	int probes = 0;
	int size();
	void ratio();

};

//Constructor for Hash table 
HashMap::HashMap() {
	while (temp != tableSize) {
		HashTable[temp] = "NULL0";
		update[temp] = NULL; // Set the elements in array update to NULL
		cost[temp] = NULL; // Set the elements in array costs to NULL
		temp++;
	}
}

HashMap::~HashMap() {
}

//Hash function to return index for string key 
int HashMap::hash(string key) {
	int sum = 0;
	int index;

	for (int i = 0; i < key.length(); i++) {
		sum = sum + (int)key[i];
	}

	index = sum % tableSize;
	return index;
}

//Insertion function for Hash Table 
void HashMap::updates(string key) {
	string temp; 
	int index = hash(key);
	if (HashTable[index] == "NULL0") { //If slot is empty at that index
		HashTable[index] = key; //Insert the string key at that index
		update[index] = 1; //If the slot is empty, then update and cost will be just 1
		cost[index] = 1; //No probes required
	}
	else {
		if (key != HashTable[index]) {
			while ((HashTable[index] != "NULL0") && (HashTable[index] != key)) {
				index++; //Linear probes
				probes++;
				if (index == tableSize) { //If index is larger than the table size
					index = 0; //Index will be change to 0 and increment until it find an empty slot 
				}
				cost[index] = cost[index]++; // Increment cost when probes needed 
			}
		}
		else {
			cost[index] = cost[index]++; //Increment cost if the string is same with the one at HashTable
			probes++;
		}
		update[index] = update[index]++;
		HashTable[index] = key;
	}
}

//Return the size of unique words 
int HashMap::size() {
	int array_size = 0;
	for (int i = 0; i < tableSize; i++) {
		if (HashTable[i] != "NULL0") {
			array_size++;
		}
	}
	return array_size;
}

//Function to print ratios 
void HashMap::ratio() {
	float ratio;
	cout << "Ratios: " << endl;
	for (int a = 0; a < tableSize; a++) {
		if (update[a] != NULL) {
			ratio = (cost[a] / update[a]);
			cout << std::fixed;
			cout << std::setprecision(2);
			cout << ratio << " , ";
		}
	}
}

int main() {
	HashMap h;

	ifstream file;
	file.open("RomeoAndJuliet.txt");
	string key;
	key.clear(); //Make sure that the string is empty 
	while (file >> key) {
		h.updates(key);
		key.clear(); //Clear the string after each insertion 
	}
	cout << "The number of unique words:" << h.size() << endl;
	cout << endl;
	h.ratio();
}