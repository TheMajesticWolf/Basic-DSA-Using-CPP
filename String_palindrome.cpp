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

		char toReturn = -1;

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

	string word;
	getline(cin, word);

	int i;
	bool isPalindrome = true;

	for(i = 0; i < word.length(); i++) {
		s.push(word[i]);
	}

	
	for(i = 0; i < word.length(); i++) {
		
		char popped = s.pop();

		if(popped != word[i]) {
			isPalindrome = false;
			break;
		}
		
	}

	(isPalindrome == true) ? cout << "String is palindrome" : cout << "String is not palindrome";





	return 0;
}
