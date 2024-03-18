#include <iostream>

using namespace std;

class Node {

	public:

	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}


};


class BinarySearchTree {

	public:

	Node* root;

	BinarySearchTree() {
		this->root = NULL;
	}

	bool isEmpty() {
		return (this->root == NULL) ? true : false;
	}


	void insertIteratively(int data) {

		Node* nn = new Node(data);

		if(this->isEmpty()) {
			this->root = nn;
			return;
		}

		Node* currentRoot = this->root;
		Node* prev = NULL;


		while(currentRoot != NULL) {

			prev = currentRoot;

			if(data == currentRoot->data) {
				return;			// Cant insert duplicate values
			}

			else if(data > currentRoot->data) {
				currentRoot = currentRoot->right;
			}

			else if(data < currentRoot->data) {
				currentRoot = currentRoot->left;
			}
			
		}



		if(data > prev->data) {
			prev->right = nn;
		}

		else {
			prev->left = nn;
		}



	}

	
	void insertRecursively(Node* currentRoot, int data) {

		static Node* prev = NULL;

		if(this->isEmpty()) {
			this->root = new Node(data);
			return;
		}

		if(currentRoot == NULL) {
			return;
		}

		if(data == currentRoot->data) {
			return;
		}

		else if(data > currentRoot->data) {
			prev = currentRoot;
			insertRecursively(currentRoot->right, data);
		}
		
		else if(data < currentRoot->data) {
			prev = currentRoot;
			insertRecursively(currentRoot->left, data);
		}
		
		if(data > prev->data) {
			prev->right = new Node(data);
		}

		else {
			prev->left = new Node(data);

		}


	}


	void inOrderTraversal(Node* currentRoot) {

		if(currentRoot == NULL) {
			return;
		}

		inOrderTraversal(currentRoot->left);
		cout << currentRoot->data << " ";
		inOrderTraversal(currentRoot->right);


	}


	Node* serachIteratively(int key) {

		Node* temp = this->root;

		while(temp != NULL) {

			if(key == temp->data) {
				return temp;
			}

			else if(key > temp->data) {
				temp = temp->right;
			}

			else {
				temp = temp->left;

			}

		}

		return NULL;


	}


	Node* serachRecursively(Node* currentRoot, int key) {

		if(this->isEmpty()) {
			return NULL;
		}

		if(currentRoot == NULL) {
			return NULL;
		}

		if(key == currentRoot->data) {
			return currentRoot;
		}

		else if(key > currentRoot->data) {
			return serachRecursively(currentRoot->right, key);

		}

		else {
			return serachRecursively(currentRoot->left, key);

		}


	}


	int findMinValue(Node* currentRoot) {
		
		Node* temp = currentRoot;

		while(temp->left != NULL) {
			temp = temp->left;
		}

		return temp->data;

	}


	void remove(Node* currentRoot, int key) {

		
		static Node* prev = NULL;

		if(this->isEmpty()) {
			return;
		}

		if(currentRoot == NULL) {
			return;
		}

		if(key == currentRoot->data) {

			// Case 1: Node to be removed is leaf node;

			if(currentRoot->left == NULL && currentRoot->right == NULL) {

				if(prev->left == currentRoot) {
					prev->left = NULL	;
				}

				else {
					prev->right = NULL;
				}

				delete currentRoot;
				return;
			}


			// Case 2: Node to be removed has only single child;
			else if((currentRoot->left == NULL && currentRoot->right != NULL) || (currentRoot->right == NULL && currentRoot->left != NULL)) {

				Node* toMoveUp = (currentRoot->left != NULL) ? currentRoot->left : currentRoot->right;
				
				if(prev->left == currentRoot) {
					prev->left = toMoveUp;
				}
				
				else {
					prev->right = toMoveUp;
				}
				
				delete currentRoot;
				return;
			}

			// Case 3: Node has 2 children
			else {

				int minValInRightSubTree = this->findMinValue(currentRoot->right);
				currentRoot->data = minValInRightSubTree;
				prev = currentRoot;
				this->remove(currentRoot->right, minValInRightSubTree);
				return;
			}			
			
			

		}


		else if(key > currentRoot->data) {
			prev = currentRoot;
			this->remove(currentRoot->right, key);
		}

		else {
			prev = currentRoot;
			this->remove(currentRoot->left, key);
		}




	}


	int secondMinimumNode(Node* curentRoot) {

		// Node* temp = curentRoot;
		static Node* prev = NULL;

		if(curentRoot->left == NULL) {
			return prev->data;
		}

		else {
			prev = curentRoot;
			int a = secondMinimumNode(curentRoot->left);
			int b = secondMinimumNode(curentRoot->right);

			if(a < b) {
				return a;
			}
			else {
				return b;
			}
		}

	}
 
};


int main() {

	BinarySearchTree bst;

	// bst.insertIteratively(7);
	// bst.insertIteratively(5);
	// bst.insertIteratively(9);
	// bst.insertIteratively(3);
	// bst.insertIteratively(6);
	// bst.insertIteratively(8);
	// bst.insertIteratively(11);

	bst.insertRecursively(bst.root, 7);
	bst.insertRecursively(bst.root, 5);
	bst.insertRecursively(bst.root, 9);
	bst.insertRecursively(bst.root, 3);
	bst.insertRecursively(bst.root, 6);
	bst.insertRecursively(bst.root, 8);
	bst.insertRecursively(bst.root, 10);
	bst.insertRecursively(bst.root, 12);

	bst.inOrderTraversal(bst.root);

	cout << endl;

	// Node* searched = bst.serachIteratively(9);
	// cout << searched->data << endl;
	// cout << searched->left->data << endl;
	// cout << searched->right->data << endl;

	// Node* searched = bst.serachRecursively(bst.root, 9);
	// cout << searched->data << endl;
	// cout << searched->left->data << endl;
	// cout << searched->right->data << endl;

	bst.remove(bst.root, 7);

	bst.inOrderTraversal(bst.root);

	cout << endl;

	cout << bst.secondMinimumNode(bst.root);
	

	return 0;

}


