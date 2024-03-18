#include <iostream>
#include <string>

using namespace std;

class Node {

public:
	char data;
	Node *next;

	Node(char data) {
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

	void push(char data) {

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

	char pop() {

		char toReturn = '\0';

		if (this->isEmpty()) {
			return toReturn;
		}

		Node *temp = this->top;

		this->top = this->top->next;

		toReturn = temp->data;

		delete temp;

		return toReturn;
	}

	char peek() {

		if (this->isEmpty()) {
			return '\0';
		}

		return this->top->data;



	}
 

};


bool isMatchingBrackets(char opening, char closing) {

	if(opening == '(' && closing == ')') {
		return true;
	}

	else if(opening == '[' && closing == ']') {
		return true;
	}

	else if(opening == '{' && closing == '}') {
		return true;
	}

	else if(opening == '<' && closing == '>') {
		return true;
	}

	else {
		return false;
	}


}



int main() {

	Stack s;

	string expression;
	getline(cin, expression);

	int i;
	char current;
	char topOfStack;
	char popped;
	bool isValid = true;

	

	for(i = 0; i < expression.length(); i++) {

		current = expression[i];
		topOfStack = s.peek();

		if(current == '(' || current == '[' || current == '{' || current == '<') {
			s.push(current);
		}

		else if(current == ')' || current == ']' || current == '}' || current == '>') {

			popped = s.pop();

			if(! isMatchingBrackets(popped, current)) {
				isValid = false;
				break;
			}


		}

	}

	if(! s.isEmpty()) {
		isValid = false;
	}

	if(isValid) {
		cout << "Given expression is valid" << endl;
	}

	else {
		cout << "Given expression is not valid" << endl;

	}




	return 0;
}
