#include <iostream>
#include <string>

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

        int toReturn = '\0';

        if (this->isEmpty()) {
            return toReturn;
        }

        Node *temp = this->top;

        this->top = this->top->next;

        toReturn = temp->data;

        delete temp;

        return toReturn;
    }

	int peek() {
		if(this->isEmpty()) {
			return '\0';
		} 
		return this->top->data;
	}


};


bool isOperator(char symbol) {

	switch (symbol) {

		case '+':
		case '-':
		case '*':
		case '/':
			return true;
		
		default:
			return false;
			break;
	}

}


int getPrecedence(char symbol) {

	int precedence;

	switch(symbol) {

		case '+':
		case '-':
			precedence = 1;
			break;
		
		case '*':
		case '/':
			precedence = 2;
			break;

		default:
			precedence = 0;
			break;

	}

	return precedence;

}



int main() {

	/*
	
	Initialize an empty stack to store operands.
	Scan the postfix expression from left to right.
	For each character in the postfix expression:
	a. If it is an operand, push it onto the stack.
	b. If it is an operator:
	i. Pop the top two operands from the stack.
	ii. Perform the operation using the operator on the operands.
	iii. Push the result back onto the stack.
	After scanning the entire postfix expression, the final result will be on the top of the stack.


	*/

	// string expression = "79+3/68-*";
	string expression = "24+3/68-*";   // a = 2, b = 1
    Stack s;
	int i;


	// cout << "Enter expression: ";
	// getline(cin, expression);

	for(i = 0; i < expression.length(); i++) {

		char current = expression[i];
		char top = s.peek();



		if(current >= 48 && current <= 57) {
			s.push(current - '0');
			cout << "Pushed " << current - '0' << endl;
		}

		else if(isOperator(current)) {

			int op1 = s.pop();
			int op2 = s.pop();

			cout << "Popped " << op1 << " " << op2 << endl;

			if(current == '+') {
				s.push(op2 + op1);				
			}

			else if(current == '-') {
				s.push(op2 - op1);
			}

			else if(current == '*') {
				s.push(op2 * op1);
			}

			else if(current == '/') {
				s.push(op2 / op1);
			}

			// op2 - op1

		}

	}

	cout << s.peek();



    return 0;
}
