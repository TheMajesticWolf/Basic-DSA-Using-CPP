#include <iostream>

using namespace std;

class Node {

public:
	int data;
	Node *next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList {

public:
	Node *head;

	LinkedList() {
		this->head = NULL;
	}

	bool isEmpty() {

		return (this->head == NULL) ? true : false;
	}

	void addAtStart(int data) {

		Node *nn = new Node(data);

		if (this->head == NULL) {
			this->head = nn;
			return;
		}

		nn->next = this->head;
		this->head = nn;
	}

	void addAtEnd(int data) {

		Node *nn = new Node(data);
		Node *temp = this->head;

		if (this->head == NULL) {
			this->head = nn;
			return;
		}

		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = nn;
	}

	void printList() {

		if (this->isEmpty()) {
			cout << "List is empty" << endl;
			return;
		}

		Node *temp = this->head;

		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << endl;
	}

	int removeFromStart() {

		int toReturn = -1;

		if (this->isEmpty()) {
			return toReturn;
		}

		Node *temp = this->head;

		this->head = this->head->next;

		toReturn = temp->data;

		delete temp;

		return toReturn;
	}

	int removeFromEnd() {

		int toReturn = -1;

		if (this->isEmpty()) {
			return toReturn;
		}

		if (this->head->next == NULL) {
			toReturn = this->head->data;
			this->head = NULL;
			return toReturn;
		}

		Node *current = this->head;
		Node *nextPtr = this->head->next;

		while (nextPtr->next != NULL) {
			current = current->next;
			nextPtr = nextPtr->next;
		}

		current->next = NULL;

		toReturn = nextPtr->data;

		delete current;

		return toReturn;
	}

	Node* recursive_search(Node* currentHead, int key) {

		if(currentHead == NULL) {
			return NULL;
		}

		if(currentHead->data == key) {
			return currentHead;
		}

		else {
			return recursive_search( currentHead->next, key);
		}
	}


};

int main() {

	LinkedList ll;

	ll.addAtStart(30);
	ll.addAtStart(20);
	ll.addAtStart(10);

	ll.addAtEnd(40);
	ll.addAtEnd(50);
	ll.addAtEnd(60);

	ll.printList();

	// cout << ll.removeFromEnd() << endl;
	// cout << ll.removeFromEnd() << endl;
	// cout << ll.removeFromEnd() << endl;
	// cout << ll.removeFromEnd() << endl;
	// cout << ll.removeFromEnd() << endl;
	// cout << ll.removeFromEnd() << endl;
	// cout << ll.removeFromEnd() << endl;
	// cout << ll.removeFromEnd() << endl;

	// cout << ll.removeFromStart() << endl;
	// cout << ll.removeFromStart() << endl;
	// cout << ll.removeFromStart() << endl;
	// cout << ll.removeFromStart() << endl;
	// cout << ll.removeFromStart() << endl;
	// cout << ll.removeFromStart() << endl;
	// cout << ll.removeFromStart() << endl;
	// cout << ll.removeFromStart() << endl;



	ll.printList();

	return 0;
}
