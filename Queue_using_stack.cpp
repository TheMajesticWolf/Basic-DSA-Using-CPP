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



class Stack {

public:
	Node *top;

	Stack() {
		this->top = NULL;
	}

	bool isEmpty() {

		return (this->top == NULL) ? true : false;
	}

	void push(int data) {

		Node *nn = new Node(data);

		if (this->top == NULL) {
			this->top = nn;
			return;
		}

		nn->next = this->top;
		this->top = nn;
	}



	void display() {

		if (this->isEmpty()) {
			cout << "Queue is empty" << " ";
			return;
		}

		Node *temp = this->top;

		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << endl;

	}

	int pop() {

		int toReturn = -1;

		if (this->isEmpty()) {
			return toReturn;
		}

		Node *temp = this->top;

		this->top = this->top->next;

		toReturn = temp->data;

		delete temp;

		return toReturn;
	}


};



class QueueUsingStack {

	public:

	Stack s1;
	Stack s2;

	QueueUsingStack() {

		// In this implementation, the stack s1 is acting like a queue.
		// Here, enqueue operation is expensive whereas dequeue operation is not expensive;

		this->s1 = Stack();
		this->s2 = Stack();
	}

	void enqueue(int data) {

		while(! s1.isEmpty()) {
			s2.push(s1.pop());
		}

		s1.push(data);
 
		while(! s2.isEmpty()) {
			s1.push(s2.pop());
		}

	}


	int dequeue() {


		if(! s1.isEmpty()) {
			return s1.pop();
		}
		else {
			return -1;
		}


	}

	void display() {
		s1.display();
	}




};



int main() {

	QueueUsingStack q;

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);

	q.display();

	cout << "Dequeued: " << q.dequeue() << endl;
	cout << "Dequeued: " << q.dequeue() << endl;
	cout << "Dequeued: " << q.dequeue() << endl;
	cout << "Dequeued: " << q.dequeue() << endl;

	q.display();



	return 0;
}
