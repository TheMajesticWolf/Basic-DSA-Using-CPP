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

class CircularQueue {

public:
	Node *front;
	Node *rear;

	CircularQueue() {
		this->front = NULL;
		this->rear = NULL;
	}

	bool isEmpty() {

		return (this->front == NULL) ? true : false;
	}



	void enqueue(int data) {

		Node *nn = new Node(data);
		Node *temp = this->front;

		if (this->front == NULL) {
			this->front = this->rear = nn;
			this->rear->next = this->front;
			return;
		}

		while (temp->next != this->front) {
			temp = temp->next;
		}

		temp->next = nn;
		nn->next = this->front;
		this->rear = nn;
	}

	void printList() {

		if (this->isEmpty()) {
			cout << "List is empty" << endl;
			return;
		}

		Node *temp = this->front;

		do {
			cout << temp->data << " ";
			temp = temp->next;

		} while(temp != this->front);

		cout << endl;
	}

	int dequeue() {

		int toReturn = -1;

		if (this->isEmpty()) {
			return toReturn;
		}

		if (this->front->next == this->front) {
			toReturn = this->front->data;
			this->front = this->rear =  NULL;
			return toReturn;
		}

		Node *temp = this->front;

		this->front = this->front->next;

		this->rear->next = this->front;

		toReturn = temp->data;

		delete temp;

		return toReturn;
	}

};

int main() {

	CircularQueue cq;

	cq.enqueue(10);
	cq.enqueue(20);
	cq.enqueue(30);

	cq.enqueue(40);
	cq.enqueue(50);
	cq.enqueue(60);

	cq.printList();

	cout << cq.dequeue() << endl;
	cout << cq.dequeue() << endl;
	cout << cq.dequeue() << endl;
	cout << cq.dequeue() << endl;
	cout << cq.dequeue() << endl;
	cout << cq.dequeue() << endl;
	cout << cq.dequeue() << endl;
	cout << cq.dequeue() << endl;


	cq.printList();

	return 0;
}
