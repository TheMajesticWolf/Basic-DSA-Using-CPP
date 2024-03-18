#include <iostream>

using namespace std;

class Node {

public:
	int data;
	Node *next;

	Node(char data) {
		this->data = data;
		this->next = NULL;
	}
};


class Queue {

	public:

	Node* front;
	Node* rear;

	Queue() {
		this->front = this->rear = NULL;
	}

	bool isEmpty() {

		if(this->front == NULL) {
			return true;
		}

		return false;

	}

	void enqueue(int data) {

		Node* nn = new Node(data);

		if(this->front == NULL) {
			this->front = this->rear = nn;
			return;
		}

		this->rear->next = nn;
		this->rear = nn;

	}

	int dequeue() {

		int toReturn = -1;

		if(this->isEmpty()) {
			return toReturn;
		}



		Node* tbd = this->front;

		toReturn = tbd->data;

		this->front = this->front->next;

		delete tbd;

		return toReturn;




	}

	void display() {

		if(this->isEmpty()) {
			cout << "Queue is empty" << endl;
			return;
		}

		Node* temp = this->front;

		while(temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << endl;

	}



};



int main() {

	Queue q;

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);

	q.display();

	cout << "Dequeued: " << q.dequeue() << endl;
	cout << "Dequeued: " << q.dequeue() << endl;
	cout << "Dequeued: " << q.dequeue() << endl;
	cout << "Dequeued: " << q.dequeue() << endl;
	cout << "Dequeued: " << q.dequeue() << endl;

	q.display();
	

	return 0;

}


