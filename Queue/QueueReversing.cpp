#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* nextNode;
};

class Queue {
public:
    Node* frontNode;
    Node* rearNode;

    Queue() {
        frontNode = nullptr;
        rearNode = nullptr;
    }

    bool isQueueEmpty() {
        return frontNode == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node{value, nullptr};
        if (isQueueEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->nextNode = newNode;
            rearNode = newNode;
        }
    }

    void reverseQueue() {
        if (isQueueEmpty() || frontNode == rearNode) {
            return;
        }
        Node* prevNode = nullptr;
        Node* currentNode = frontNode;
        Node* nextNode = nullptr;
        rearNode = frontNode;

        while (currentNode != nullptr) {
            nextNode = currentNode->nextNode;
            currentNode->nextNode = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        frontNode = prevNode;
    }

    void displayQueue() {
        if (isQueueEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* tempNode = frontNode;
        while (tempNode != nullptr) {
            cout << tempNode->value << " ";
            tempNode = tempNode->nextNode;
        }
        cout << endl;
    }
};

int main() {
    int choice, value;
    Queue q;

    do {
        cout << "\n1.Enqueue\n2.Reverse Queue\n3.Display Queue\n4.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.reverseQueue();
                cout << "Queue reversed.\n";
                break;
            case 3:
                q.displayQueue();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 4);

    return 0;
}
