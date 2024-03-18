// TO BE COMPLETED

#include <iostream>
#include <queue>

using namespace std;

class BinaryTree {

	public:

	int* arr;
	int topIndex;

	BinaryTree() {

		this->arr = new int[20]();
		this->topIndex = -1;

		for(int i = 0; i < 20; i++) {
			this->arr[i] = -1;
		}

	}

	bool isEmpty() {
		return (this->topIndex == -1) ? true : false;
	}

	int getLeftChildIndex(int rootIndex) {
		return 2 * rootIndex + 1;
	}

	int getRightChildIndex(int rootIndex) {
		return 2 * rootIndex + 2;
	}

	int getParentIndex(int rootIndex) {
		return rootIndex / 2;
	}

	void setLeftChild(int rootIndex, int data) {
		this->topIndex++;
		this->arr[this->getLeftChildIndex(rootIndex)] = data;
	}

	void setRightChild(int rootIndex, int data) {
		this->topIndex++;
		this->arr[this->getRightChildIndex(rootIndex)] = data;
	}

	void setRoot(int data) {
		this->arr[0] = data;
		this->topIndex++;
	}

	void levelOrderTraversal() {

		int i;

		for(i = 0; i <= this->topIndex; i++) {

			cout << this->arr[i] << " ";

		}

		cout << endl;

	}

	void insert(int data) {

		this->arr[++this->topIndex] = data;




	}

	int remove() {

		int toReturn = this->arr[this->topIndex];
		this->arr[this->topIndex] = -1;
		this->topIndex--;

		return toReturn;



	}





};


int main() {

	BinaryTree bt;

	// bt.setRoot(1);

	// bt.setLeftChild(0, 2);
	// bt.setRightChild(0, 3);

	// bt.setLeftChild(1, 4);
	// bt.setRightChild(1, 5);

	bt.insert(1);
	bt.insert(2);
	bt.insert(3);
	bt.insert(4);
	bt.insert(5);


	bt.levelOrderTraversal();
	cout << endl;

	// cout << bt.arr[bt.getLeftChildIndex(1)];

	bt.remove();


	bt.levelOrderTraversal();


	return 0;

}


