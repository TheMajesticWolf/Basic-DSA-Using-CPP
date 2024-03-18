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

class CircularLinkedList {

public:
	Node *head;
	Node *tail;

	CircularLinkedList() {
		this->head = NULL;
		this->tail = NULL;
	}

	bool isEmpty() {

		return (this->head == NULL) ? true : false;
	}

	void addAtStart(int data) {

		Node *nn = new Node(data);

		if (this->head == NULL) {
			this->head = this->tail =  nn;
			this->tail->next = this->head;
			return;
		}

		nn->next = this->head;
		this->head = nn;
		this->tail->next = this->head;
	}

	void addAtEnd(int data) {

		Node *nn = new Node(data);
		Node *temp = this->head;

		if (this->head == NULL) {
			this->head = this->tail = nn;
			return;
		}

		while (temp->next != this->head) {
			temp = temp->next;
		}

		nn->next = this->head;
		temp->next = nn;
		this->tail = nn;
	}

	void printList() {

		if (this->isEmpty()) {
			cout << "List is empty" << endl;
			return;
		}

		Node *temp = this->head;

		do {
			cout << temp->data << " ";
			temp = temp->next;

		} while(temp != this->head);

		cout << endl;
	}

	int removeFromStart() {

		int toReturn = -1;

		if (this->isEmpty()) {
			return toReturn;
		}

		if (this->head->next == this->head) {
			toReturn = this->head->data;
			this->head = this->tail =  NULL;
			return toReturn;
		}

		Node *temp = this->head;

		this->head = this->head->next;

		this->tail->next = this->head;

		toReturn = temp->data;

		delete temp;

		return toReturn;
	}

	int removeFromEnd() {

		int toReturn = -1;

		if (this->isEmpty()) {
			return toReturn;
		}

		if (this->head->next == this->head) {
			toReturn = this->head->data;
			this->head = this->tail =  NULL;
			return toReturn;
		}

		Node *current = this->head;
		Node *nextPtr = this->head->next;

		while (nextPtr->next != this->head) {
			current = current->next;
			nextPtr = nextPtr->next;
		}

		current->next = this->head;

		toReturn = nextPtr->data;

		delete current;

		return toReturn;
	}
};

int main() {

	CircularLinkedList ll;

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

	cout << ll.removeFromStart() << endl;
	cout << ll.removeFromStart() << endl;
	cout << ll.removeFromStart() << endl;
	cout << ll.removeFromStart() << endl;
	cout << ll.removeFromStart() << endl;
	cout << ll.removeFromStart() << endl;
	cout << ll.removeFromStart() << endl;
	cout << ll.removeFromStart() << endl;

	ll.printList();

	return 0;
}
