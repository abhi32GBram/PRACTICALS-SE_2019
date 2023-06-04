#include<iostream>
using namespace std;

#define TABLE_SIZE 15
#define PRIME 7

class DoubleHash 
{
	int* hashTable;
	int curr_size;
public:
	bool isFull() 
	{
		return (curr_size == TABLE_SIZE);
	}

	int hash1(int key) 
	{
		return (key % TABLE_SIZE);
	}

	int hash2(int key) {
		return (PRIME - (key % PRIME));
	}

	// Constructor 
	DoubleHash() {
		hashTable = new int[TABLE_SIZE];
		curr_size = 0;

		for (int i = 0; i < TABLE_SIZE; i++) {
			hashTable[i] = -1; // Populate all elements with -1
		}
	}

	void insertHash(int key) {
		if (isFull()) {
			return;
		}

		int index = hash1(key);

		// If collision occurs
		if (hashTable[index] != -1) {
			int index2 = hash2(key);
			int i = 1;

			while (true) {
				int newIndex = (index + i * index2) % TABLE_SIZE;

				if (hashTable[newIndex] == -1) {
					hashTable[newIndex] = key;
					break;
				}

				i++;
			}
		}
		else {
			hashTable[index] = key;
		}

		curr_size++;
	}

	void linprob(int key) {
		int index1 = hash1(key);

		if (isFull()) {
			return;
		}

		hashTable[index1] = key;

		for (int i = index1; i < TABLE_SIZE + 1; i++) {
			if (hashTable[i] != -1) {
				hashTable[i + 1] = key;
				break;
			}
		}
	}

	void display() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			if (hashTable[i] != -1) {
				cout << i << "-->" << hashTable[i] << endl;
			}
			else {
				cout << i << endl;
			}
		}
	}
};

int main() 
{
	int a[TABLE_SIZE];

	
	cout << "ENTER THE SIZE OF YOUR HASH TABLE: ";
	int n = 0;
	cin >> n;
	cout << "ENTER THE PHONE NUMBERS OF CLIENTS:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "ENTER: ";
		cin >> a[i];
	}

	DoubleHash h;

	int collisionResTechnique;
	cout << "SELECT COLLISION RESOLUTION TECHNIQUE:" << endl;
	cout << "1. Double Hashing" << endl;
	cout << "2. Linear Probing" << endl;
	cout << "Enter your choice (1 or 2): ";

	cin >> collisionResTechnique;

	if (collisionResTechnique == 1) {
		for (int i = 0; i < n; i++) {
			h.insertHash(a[i]);
		}
	}
	else if (collisionResTechnique == 2) {
		for (int i = 0; i < n; i++) {
			h.linprob(a[i]);
		}
	}
	else {
		cout << "Invalid choice. Exiting the program." << endl;
		return 0;
	}

	cout << "HASH TABLE CONTENTS:" << endl;
	h.display();

	return 0;
}
