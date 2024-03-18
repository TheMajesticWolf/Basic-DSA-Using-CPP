#include <iostream>
#include <string>

using namespace std;

template <typename T_Key, typename T_Val>
class HashTableObject {

	public:

	T_Key key;
	T_Val value;

	HashTableObject<T_Key, T_Val>(T_Key key, T_Val value) {
		this->key = key;
		this->value = value;
	}

};

template <typename T_Key, typename T_Val>
class HashMap {

	public:

	HashTableObject<T_Key, T_Val>** hashTableObjectArr;
	int tableSize;

	HashMap(int tableSize) {
		this->tableSize = tableSize;
		this->hashTableObjectArr = new HashTableObject<T_Key, T_Val> * [this->tableSize];


		int i;

		for(i = 0; i < this->tableSize; i++) {
			this->hashTableObjectArr[i] = NULL;
		}


	}

	int hashFunc(T_Key key) {

		int checksum = 0;
		int i;

        for (const auto& ch : key) {
            checksum += ch;
            checksum = (checksum * ch) % this->tableSize;
        }

		// return key % this->tableSize;
		return checksum;
		
	}

	void insert(T_Key key, T_Val value) {

		int index = this->hashFunc(key);
		int i;

		for(i = 0; i < this->tableSize; i++) {

			int tryIndex = (i + index) % this->tableSize;

			if(this->hashTableObjectArr[tryIndex] == NULL) {
				this->hashTableObjectArr[tryIndex] = new HashTableObject<T_Key, T_Val>(key, value);
				return;
			}
		}
		
		return;

	}


	HashTableObject<T_Key, T_Val>* search(T_Key key) {

		int index = this->hashFunc(key);

		int i;

		for(i = 0; i < this->tableSize; i++) {

			int tryIndex = (i + index) % this->tableSize;

			if(this->hashTableObjectArr[tryIndex] != NULL && this->hashTableObjectArr[tryIndex]->key == key) {
				return this->hashTableObjectArr[tryIndex];
			}
		}

		
		return NULL;

	}

	HashTableObject<T_Key, T_Val>* remove(T_Key key) {

		int index = this->hashFunc(key);

		HashTableObject<T_Key, T_Val>* toReturn = NULL;

		int i;

		for(i = 0; i < this->tableSize; i++) {

			int tryIndex = (i + index) % this->tableSize;

			if(this->hashTableObjectArr[tryIndex] != NULL && this->hashTableObjectArr[tryIndex]->key == key) {
				toReturn = this->hashTableObjectArr[tryIndex];
				this->hashTableObjectArr[tryIndex] = NULL;
				return toReturn;
			}
		}

		return NULL;
		

	
	}




	void display() {
		int i;

		cout << "***************************************************" << endl;
		
		for(i = 0; i < this->tableSize; i++) {

			HashTableObject<T_Key, T_Val>* obj = this->hashTableObjectArr[i];

			if(obj == NULL) {
				cout << i << "\t---\t" << endl;
			}
			else {
				cout << i << "\t---\t" << obj->key << "---" << obj->value << endl;

			}
		}

		cout << "***************************************************" << endl;

	}




};



int main() {

	HashMap<string, int> hm(10);

	// hm.insert(459866, 10);
	// hm.insert(846524, 20);
	// hm.insert(845612, 30);
	// hm.insert(785269, 40);
	// hm.insert(694200, 50);
	// hm.insert(694204, 60);
	// hm.insert(846527, 70);
	// hm.insert(946527, 75);

	hm.insert("Person 10", 10);
	hm.insert("Person 20", 20);
	hm.insert("Person 30", 30);
	hm.insert("Person 40", 40);
	hm.insert("Person 50", 50);
	hm.insert("Person 60", 60);
	hm.insert("Person 70", 70);
	hm.insert("Person 75", 75);
	hm.insert("Person 80", 80);
	hm.insert("Person 100", 100);
	hm.insert("Person 90", 90);


	hm.display();

	HashTableObject<string, int>* deleted = hm.remove("Person 70");

	if(deleted != NULL) {
		cout << deleted->key << "  " << deleted->value << endl;
	}
	else {
		cout << "Key not found" << endl;
	}

	hm.display();


	

	return 0;

}


