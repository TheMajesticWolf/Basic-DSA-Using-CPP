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
	
	1. Create an empty stack to hold operators.
	2. Initialize an empty string for the postfix expression.
	3. Scan the infix expression from left to right.
	4. For each character in the infix expression:
	a. If it is an operand, append it to the postfix string.
	b. If it is an operator:
		i. Pop operators from the stack and append them to the postfix string until the stack is empty or the top operator has lower precedence.
		ii. Push the current operator onto the stack.
	c. If it is an opening parenthesis '(', push it onto the stack.
	d. If it is a closing parenthesis ')':
		i. Pop operators from the stack and append them to the postfix string until an opening parenthesis '(' is encountered. Pop and discard the '('.
	5. After scanning the entire infix expression, pop any remaining operators from the stack and append them to the postfix string.
	6. The final postfix expression is obtained.


	*/

	// string expression = "(3 + 5) * (7 - 2)";
	// string expression = "6+7*8-2+3";
	// string expression = "(a+b)/3*(6-8)";
	// string expression = "A*(b+c)+(b/d)*a+z*u";
	string expression = "a+b*(c-d)/e";

	// Uncomment the below line for infix to prefix
	// reverse(expression.begin(), expression.end());

	
	Stack s;
	string output = "";
	int i;

	// *
	// ab+3/68-*


	// cout << "Enter expression: ";
	// getline(cin, expression);

	for(i = 0; i < expression.length(); i++) {
	// Uncomment the below line and comment the above line for infix to prefix
	// for(i = expression.length() - 1; i >= 0; i--) {

		char current = expression[i];
		char top = s.peek();

		int currentPrecedence, topPrecedence;

		currentPrecedence = getPrecedence(current);
		topPrecedence = getPrecedence(s.peek());


		if(isalnum(current)) {
			output += current;
		}

		else if(current == '(') {
			s.push(current);
		}

		else if(isOperator(current)) {
			
			// while(! s.isEmpty() && (topPrecedence >= currentPrecedence)) {
			while(! s.isEmpty() && (currentPrecedence <= topPrecedence )) {

				output += s.pop();

				currentPrecedence = getPrecedence(current);
				topPrecedence = getPrecedence(s.peek());

			}

			s.push(current);

		}

		else if (current == ')') {

			while(! s.isEmpty() && s.peek() != '(') {
				output += s.pop();
			}

			s.pop();			// Popping the '('

		}


	}

	while(! s.isEmpty()) {
		output += s.pop();
	}

	// Uncomment the below line when doing infix to prefix
	// reverse(output.begin(), output.end());

	cout << output << endl;

		






    return 0;
}
