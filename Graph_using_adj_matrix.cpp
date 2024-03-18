#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;


class Graph {

	public:

	int **adjMatrix;
	int numOfVertices;

	Graph(int numOfVertices) {

		this->numOfVertices = numOfVertices;

		int i;

		this->adjMatrix = new int*[this->numOfVertices];

		for(i = 0; i < this->numOfVertices; i++) {
			this->adjMatrix[i] = new int[this->numOfVertices]();
		}


	}

	void printAdjMatrix() {

		int i, j;

		for(i = 0; i < this->numOfVertices; i++) {
			for(j = 0; j < this->numOfVertices; j++) {
				cout << this->adjMatrix[i][j] << " ";
			}
			cout << endl;
			
		}


	}

	void addEdgeFromTo(int startVertex, int endVertex) {

		this->adjMatrix[startVertex][endVertex] = 1;
		// this->adjMatrix[endVertex][startVertex] = 1;

	}

	void BFT() {

		queue<int> myQueue;
		bool *visited = new bool[this->numOfVertices]();
		int vertexCount = 0;

		myQueue.push(0);
		visited[0] = true;


		int front;

		while(! myQueue.empty()) {

			front = myQueue.front();
			myQueue.pop();

			cout << front << " -- ";

	


			for(int i = 0; i < this->numOfVertices; i++) {
				if(this->adjMatrix[front][i] == 1 && ! visited[i]) {
					myQueue.push(i);
					visited[i] = true;
				}
			}



		}




	}


	void DFT() {

		stack<int> myStack;
		bool *visited = new bool[this->numOfVertices]();
		int vertexCount = 0;

		myStack.push(0);
		visited[0] = true;


		int front;

		while(! myStack.empty()) {

			front = myStack.top();
			myStack.pop();

			cout << front << " -- ";

	


			for(int i = 0; i < this->numOfVertices; i++) {
				if(this->adjMatrix[front][i] == 1 && ! visited[i]) {
					myStack.push(i);
					visited[i] = true;
				}
			}



		}




	}




};



int main() {

	Graph g(5);

	g.addEdgeFromTo(0, 1);
	g.addEdgeFromTo(0, 2);
	g.addEdgeFromTo(0, 3);

	g.addEdgeFromTo(1, 0);

	g.addEdgeFromTo(2, 0);
	g.addEdgeFromTo(2, 3);
	g.addEdgeFromTo(2, 4);

	g.addEdgeFromTo(3, 0);
	g.addEdgeFromTo(3, 2);

	g.addEdgeFromTo(4, 2);




	g.printAdjMatrix();

	cout << endl;

	g.DFT();

	

	return 0;

}


