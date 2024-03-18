#include <iostream>

using namespace std;

class Queue {

	public:

	int front;		// Index of front element
	int rear;		// Index of rear element
	int *arr;		// Array to hold data
	int capacity;

	Queue(int capacity) {
		this->capacity = capacity;
		this->front = -1;
		this->rear = -1;
		this->arr = new int[this->capacity];
	}

	bool isEmpty() {
		// if(this->front == -1 && this->rear == - 1) {
		if(this->front > this->rear || this->front == -1) {
			return true;
		}

		return false;

	}


	bool isFull() {
		if(this->rear == this->capacity - 1) {
			return true;
		}

		return false;

	}

	void enqueue(int data) {

		if(this->isFull()) {
			cout << "Queue overflow, couldn't enqueue " << data << endl;
			return; 
		}
		
		if(this->isEmpty()) {

			this->arr[++this->front] = data;
			this->rear = this->front;


			return;

		}

		this->arr[++this->rear] = data;
	


	}

	int dequeue() {

		if(this->isEmpty()) {
			return -1;
		}

		int toReturn = this->arr[this->front];

		this->front++;

		return toReturn;


	}


	void display() {

		if(this->isEmpty()) {
			cout << "Queue is empty" << endl;
			return;
		}

		int i;

		for(i = this->front; i <= this->rear; i++) {
			cout << this->arr[i] << " ";
		}

		cout << endl;

	}
	 


};


int main() {

	Queue q = Queue(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);

	q.display();

	cout << "Dequeued: " << q.dequeue() << endl;
	cout << "Dequeued: " << q.dequeue() << endl;
	cout << "Dequeued: " << q.dequeue() << endl;
	cout << "Dequeued: " << q.dequeue() << endl;
	cout << "Dequeued: " << q.dequeue() << endl;
	cout << "Dequeued: " << q.dequeue() << endl;

	
	q.display();

	return 0;

}


