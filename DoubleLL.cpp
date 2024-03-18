#include <iostream>

using namespace std;

class Node {

public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoubleLinkedList {

public:
    Node* head;
    Node* tail;

    DoubleLinkedList() {
        this->head = NULL;
		this->tail = NULL;
    }

    bool isEmpty() {

        return (this->head == NULL) ? true : false;
    }


    void addAtStart(int data) {

        Node *nn = new Node(data);

        if (this->isEmpty()) {
            this->head = this->tail = nn;
			return;
        }

        nn->next = this->head;
        this->head->prev = nn;

        this->head = nn;
    }


	void addAtEnd(int data) {

		Node* nn = new Node(data);

		if (this->isEmpty()) {
            this->head = this->tail = nn;
			return;
        }


		nn->prev = this->tail;
		this->tail->next = nn;
		this->tail = nn;
		




	}


    void printList() {

        if (this->isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = this->head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }


    void printListReverse() {

        if (this->isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = this->tail;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }


	int removeFromStart() {

		int toReturn = -1;

		if(this->isEmpty()) {
			return toReturn;
		}

		if(this->head->next == NULL) {
			toReturn = this->head->data;
			this->head = this->tail = NULL;
			return toReturn;
		}

		Node* temp = this->head;

		this->head = this->head->next;
		this->head->prev = NULL;

		toReturn = temp->data;

		// delete temp;

		return toReturn;


	}


	int removeFromEnd() {

		int toReturn = -1;

		if(this->isEmpty()) {
			return toReturn;
		}

		if(this->head->next == NULL) {
			toReturn = this->head->data;
			this->head = this->tail = NULL;
			return toReturn;
		}

		Node* prevNode = this->tail->prev;

		toReturn = this->tail->data;

		prevNode->next = NULL;
		this->tail->prev = NULL;

		this->tail = prevNode;

		return toReturn;


	}



};

int main() {

	DoubleLinkedList dll = DoubleLinkedList();

	dll.addAtStart(50);
	dll.addAtStart(40);
	dll.addAtStart(30);
	dll.addAtStart(20);
	dll.addAtStart(10);

	dll.addAtEnd(60);
	dll.addAtEnd(70);
	dll.addAtEnd(80);

	dll.printList();
	dll.printListReverse();

	cout << "Removed from end: " << dll.removeFromStart() << endl;
	cout << "Removed from end: " << dll.removeFromStart() << endl;
	cout << "Removed from end: " << dll.removeFromStart() << endl;
	cout << "Removed from end: " << dll.removeFromStart() << endl;
	cout << "Removed from end: " << dll.removeFromStart() << endl;
	cout << "Removed from end: " << dll.removeFromStart() << endl;
	cout << "Removed from end: " << dll.removeFromStart() << endl;
	cout << "Removed from end: " << dll.removeFromStart() << endl;
	cout << "Removed from end: " << dll.removeFromStart() << endl;

	dll.printList();
	dll.printListReverse();

	dll.addAtStart(50);
	dll.addAtStart(40);
	dll.addAtStart(30);
	dll.addAtStart(20);
	dll.addAtStart(10);

	dll.addAtEnd(60);
	dll.addAtEnd(70);
	dll.addAtEnd(80);

	dll.printList();
	dll.printListReverse();


    return 0;
}
