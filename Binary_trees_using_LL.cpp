#include <iostream>
#include <queue>

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


class BinaryTree {

	public:

	Node* root;

	BinaryTree() {
		this->root = NULL;
	}

	void preOrderTraversal(Node* currentRoot) {

		if(currentRoot == NULL) {
			return;
		}

		cout << currentRoot->data << " ";
		preOrderTraversal(currentRoot->left);
		preOrderTraversal(currentRoot->right);

	}


	void inOrderTraversal(Node* currentRoot) {

		if(currentRoot == NULL) {
			return;
		}

		inOrderTraversal(currentRoot->left);
		cout << currentRoot->data << " ";
		inOrderTraversal(currentRoot->right);

	}


	void postOrderTraversal(Node* currentRoot) {

		if(currentRoot == NULL) {
			return;
		}

		postOrderTraversal(currentRoot->left);
		postOrderTraversal(currentRoot->right);
		cout << currentRoot->data << " ";

	}


	void levelOrderTraversal(Node* currentRoot) {

		queue<Node*> q;
		Node* front;

		q.push(currentRoot);

		while(! q.empty()) {

			front = q.front();
			q.pop();

			cout << front->data << " ";

			if(front->left != NULL) {
				q.push(front->left);
			}

			if(front->right != NULL) {
				q.push(front->right);
			}


		}


	}


	void insert(int element) {

		Node* nn = new Node(element);


		if(this->root == NULL) {

			this->root = nn;
			return;
		}


		queue<Node*> q;
		Node* front;


		q.push(this->root);

		while(! q.empty()) {

			front = q.front();
			q.pop();

			if(front->left != NULL) {
				q.push(front->left);
			}

			if(front->right != NULL) {
				q.push(front->right);
			}

			if(front->left == NULL) {
				front->left = nn;
				break;
			}

			if(front->right == NULL) {
				front->right = nn;
				break;
			}


		}


	}


	void remove(Node* currentRoot, Node* toRemove) {

		// static Node* prev;

		
		if(currentRoot == NULL || toRemove == NULL) {
			return;
		}


		queue<Node*> myQueue;
		Node* current = this->root;
		Node* prev = NULL;
		Node* prevs_prev = NULL;

		myQueue.push(this->root);

		while(! myQueue.empty()) {

			prevs_prev = prev;
			prev = current;
			current = myQueue.front();


			if(current == toRemove) {

				// Case 1

				if(current->left == NULL && current->right == NULL) {
					cout << "Case 1" << endl;
					// cout << prevs_prev->data << " -- " << current->data << endl;
					if(prevs_prev->left == current) {
						prevs_prev->left = NULL;
					}
					else {
						prevs_prev->right = NULL;
					}
					// current->data = -1;
					current = NULL;
					// prev = NULL;
					
				}


				// Case 2

				else if((current->left == NULL && current->right != NULL) || (current->left != NULL && current->right == NULL)) {
					cout << "Case 2" << endl;

					if(current->left != NULL) {
						current->data = current->left->data;
						current->left = NULL;
					}
					else {
						current->data = current->right->data;
						current->right = NULL;
					}

				}


				// Case 3

				else {

					cout << "Case 3" << endl;


					int inOrderSuccessor = current->right->data;

					current->data = inOrderSuccessor;
					this->remove(current, current->right);


				}

				return;





			}

			if(current->left != NULL) {
				myQueue.push(current->left);
			}

			if(current->right != NULL) {
				myQueue.push(current->right);
			}

			myQueue.pop();
		
		}




	}


	Node* search(int value) {
		queue<Node*> myQueue;
		myQueue.push(this->root);

		Node* front;

		while(! myQueue.empty()) {

			front = myQueue.front();
			myQueue.pop();

			if(front->data == value) {
				return front;
			}

			if(front->left != NULL) {
				myQueue.push(front->left);
			}

			if(front->right != NULL) {
				myQueue.push(front->right);
			}

		}

		return NULL;
	}




};


int main() {



	BinaryTree bt = BinaryTree();

	// Node* root = new Node(1);

	// Node* n1 = new Node(2);
	// Node* n2= new Node(3);

	// Node* n3= new Node(4);
	// Node* n4= new Node(5);


	// root->left = n1;
	// root->right = n2;

	// n1->left = n3;
	// n1->right = n4;

	// bt.root = root;

	// bt.levelOrderTraversal(bt.root);

	// cout << endl;


	// bt.insert(7);
	// bt.insert(8);


	bt.levelOrderTraversal(bt.root);
	cout << endl;


	bt.remove(bt.root, bt.search(1));

	bt.levelOrderTraversal(bt.root);
	cout << endl;






	

	return 0;

}


