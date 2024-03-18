#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    queue<int> originalQueue;
    queue<int> sortedQueue;
    stack<int> auxiliaryStack;
    stack<int> auxiliaryStack2;

    originalQueue.push(4);
    originalQueue.push(2);
    originalQueue.push(5);
    originalQueue.push(1);
    originalQueue.push(3);

    while (!originalQueue.empty()) {
        int currentElement = originalQueue.front();
        originalQueue.pop();

        // If the sortedQueue is empty or the current element is greater than the front of the sortedQueue
        if (sortedQueue.empty() || currentElement >= sortedQueue.back()) {
            sortedQueue.push(currentElement);
        } 
		
		else {
            // Move elements from the sortedQueue to the auxiliaryStack until we find the correct position
            while (!sortedQueue.empty() && currentElement < sortedQueue.back()) {
                auxiliaryStack.push(sortedQueue.front());
                sortedQueue.pop();
            }


            while (!auxiliaryStack.empty()) {
                auxiliaryStack2.push(auxiliaryStack.top());
                auxiliaryStack.pop();
            }

            // Insert the current element at the correct position in the sortedQueue
            sortedQueue.push(currentElement);

            // Move elements back from the auxiliaryStack to the sortedQueue
            while (!auxiliaryStack2.empty()) {
                sortedQueue.push(auxiliaryStack2.top());
                auxiliaryStack2.pop();
            }
        }
    }

    // Print the sorted elements
    while (!sortedQueue.empty()) {
        cout << sortedQueue.front() << " ";
        sortedQueue.pop();
    }

    cout << endl;

    return 0;
}














// // TO BE DONE

// #include <iostream>
// #include <stack>
// #include <queue>

// using namespace std;

// int main() {

// 	queue<int> originalQueue;
// 	queue<int> sortedQueue;
// 	stack<int> auxiliaryStack;

// 	originalQueue.push(4);
// 	originalQueue.push(2);
// 	originalQueue.push(5);
// 	originalQueue.push(1);
// 	originalQueue.push(3);

// 	while(! originalQueue.empty()) {


// 		if(auxiliaryStack.empty()) {
// 			sortedQueue.push(originalQueue.front());
// 			originalQueue.pop();
// 		}

// 		else {

// 			if(originalQueue.front() < sortedQueue.front()) {

// 				while(! sortedQueue.empty()) {
// 					auxiliaryStack.push(sortedQueue.front());
// 					sortedQueue.pop();

// 				}

// 				sortedQueue.push(originalQueue.front());
// 				originalQueue.pop();

// 				while(! auxiliaryStack.empty()) {
// 					sortedQueue.push(auxiliaryStack.top());
// 					auxiliaryStack.pop();

// 				}

// 			}

// 		}

// 		// originalQueue.pop();

		
// 	}

	

//     // while (! auxiliaryStack.empty()) {
//     //     sortedQueue.push(auxiliaryStack.top());
//     //     auxiliaryStack.pop();
//     // }

// 	// int i;

// 	while(! sortedQueue.empty()) {
// 		cout << sortedQueue.front() << " ";
// 		sortedQueue.pop();
// 	}






	

// 	return 0;

// }


