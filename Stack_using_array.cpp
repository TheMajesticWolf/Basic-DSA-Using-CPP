#include <iostream>

using namespace std;

class Stack {

	public:

	int top;		// Index of topmost element
	int capacity;	// Max no. of elements stack can hold
	int *arr;		// Array to hold elements
	
	Stack(int capacity) {

		this->top = -1;
		this->capacity = capacity;
		this->arr = new int[this->capacity]();

	}

	bool isEmpty() {
		return (this->top == -1) ? true : false;
	}


	bool isFull() {
		return (this->top == this->capacity - 1) ? true : false;
	}

	void push(int data) {

		if(! this->isFull()) {
			this->arr[++this->top] = data;
		}
		
		else {
			cout << "Stack Overflow couldn't push " << data << endl;
		}




	}

	int pop() {

		int popped;

		if(! this->isEmpty()) {
			popped = this->arr[this->top--];

		}

		else {
			cout << "Stack undeflow couldn't pop" << endl;
			popped = -1;
		}


		return popped;

	}

	void display() {

		if(this->isEmpty()) {
			cout << "Stack is empty" << endl;
			return;
		}

		int i;

		for(i = this->top; i >= 0; i--) {
			cout << this->arr[i] << endl;
		}

	}
	 



};


int main() {

	Stack s = Stack(5);

	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	s.push(0);

	s.display();

	cout << "Popped: " << s.pop() << endl;
	cout << "Popped: " << s.pop() << endl;
	cout << "Popped: " << s.pop() << endl;
	cout << "Popped: " << s.pop() << endl;
	cout << "Popped: " << s.pop() << endl;
	cout << "Popped: " << s.pop() << endl;

	s.display();
	

	return 0;

}


