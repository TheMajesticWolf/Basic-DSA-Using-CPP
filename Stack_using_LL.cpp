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
			cout << "Stack is empty" << endl;
			return;
		}

		Node *temp = this->top;

		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}

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




int main() {

	Stack s;

	s.push(60);
	s.push(50);
	s.push(40);
	s.push(30);
	s.push(20);
	s.push(10);


	s.display();


	cout << "Popped: " << s.pop() << endl;
	cout << "Popped: " << s.pop() << endl;
	cout << "Popped: " << s.pop() << endl;
	cout << "Popped: " << s.pop() << endl;
	cout << "Popped: " << s.pop() << endl;
	cout << "Popped: " << s.pop() << endl;
	cout << "Popped: " << s.pop() << endl;
	cout << "Popped: " << s.pop() << endl;

	s.display();

	return 0;
}
