#include <iostream>
#include <queue>
#include <random>
#include <stack>
#include <vector>

using namespace std;

class Graph {

public:
    vector<vector<int>> adjList;
    int numOfVertices;

    Graph(int numOfVertices) {

        vector<vector<int>>(this->adjList);
        this->numOfVertices = numOfVertices;

        int i, j;

        for (i = 0; i < this->numOfVertices; i++) {
            this->adjList.push_back({});
        }
    }

    void addEdgeFromTo(int startVertex, int endVertex) {

        this->adjList[startVertex].push_back(endVertex);
        // this->adjList[endVertex].push_back(startVertex);
    }

    void displayAdjacencyList() {

        int i, j;

        for (i = 0; i < this->adjList.size(); i++) {
            cout << i << " ==> ";
            for (j = 0; j < this->adjList[i].size(); j++) {
                cout << this->adjList[i][j] << " ";
            }

            cout << endl;
        }
    }

    void BFT(int startVertex) {

        if (startVertex >= this->numOfVertices) {
            return;
        }

        queue<int> myQueue;
        int current;

        bool *visited = new bool[this->numOfVertices]();

        myQueue.push(startVertex);
        visited[startVertex] = true;

        while (!myQueue.empty()) {

            current = myQueue.front();
            myQueue.pop();

            cout << current << " ";

            int i, j;

            for (auto &neighbor : this->adjList[current]) {

                if (!visited[neighbor]) {
                    myQueue.push(neighbor);
                    visited[neighbor] = true;
                }
            }

        }
    }

    void DFTRecursive(int currentVertex) {

        if (currentVertex >= this->numOfVertices) {
            return;
        }

        static bool *visited = new bool[this->numOfVertices]();
        int i;

        visited[currentVertex] = true;
        cout << currentVertex << " ";


		for(auto &neighbor : this->adjList[currentVertex]) {
			if (!visited[neighbor]) {
				this->DFTRecursive(neighbor);
			}

		}

    }

    void DFTIterative(int startVertex) {

        if (startVertex >= this->numOfVertices) {
            return;
        }

        stack<int> myStack;
        int top;

        bool *visited = new bool[this->numOfVertices]();

        int i;

        myStack.push(startVertex);
        visited[startVertex] = true;

        while (!myStack.empty()) {

            top = myStack.top();
            myStack.pop();

            cout << top << " ";

            // Both the for loops work, the second one gives the same order of printing as DFTRecursive

            // for(i = 0; i < this->adjList[top].size(); i++) {
            // for (i = this->adjList[top].size() - 1; i >= 0; i--) {

			for(auto &neighbor : this->adjList[top]) {

				if (!visited[neighbor]) {
					myStack.push(neighbor);
					visited[neighbor] = true;
				}
            }
        }
    }
};

int main() {

    Graph g(6);

    // g.addEdgeFromTo(0, 2);
    // g.addEdgeFromTo(0, 3);
    // g.addEdgeFromTo(0, 4);

    // g.addEdgeFromTo(1, 2);
    // g.addEdgeFromTo(1, 3);
    // g.addEdgeFromTo(1, 4);

	g.addEdgeFromTo(0, 1);
	g.addEdgeFromTo(0, 2);

	g.addEdgeFromTo(1, 0);
	g.addEdgeFromTo(1, 2);
	g.addEdgeFromTo(1, 4);

	g.addEdgeFromTo(2, 0);
	g.addEdgeFromTo(2, 3);
	g.addEdgeFromTo(2, 4);

	g.addEdgeFromTo(3, 2);

	g.addEdgeFromTo(4, 1);
	g.addEdgeFromTo(4, 2);
	g.addEdgeFromTo(4, 5);

	g.addEdgeFromTo(5, 4);

 

    // Graph g(7);

    // g.addEdgeFromTo(0, 2);
    // g.addEdgeFromTo(0, 3);

    // g.addEdgeFromTo(1, 2);
    // g.addEdgeFromTo(1, 6);

    // g.addEdgeFromTo(2, 0);
    // g.addEdgeFromTo(2, 1);
    // g.addEdgeFromTo(2, 3);

    // g.addEdgeFromTo(3, 0);
    // g.addEdgeFromTo(3, 2);

    // g.addEdgeFromTo(4, 5);
    // g.addEdgeFromTo(4, 6);

    // g.addEdgeFromTo(5, 4);
    // g.addEdgeFromTo(5, 6);

    // g.addEdgeFromTo(6, 1);
    // g.addEdgeFromTo(6, 4);
    // g.addEdgeFromTo(6, 5);

    g.displayAdjacencyList();

    cout << endl;
    cout << endl;

    g.BFT(0);

    cout << endl;
    cout << endl;

    g.DFTRecursive(0);

    cout << endl;
    cout << endl;

    g.DFTIterative(0);

    return 0;
}
