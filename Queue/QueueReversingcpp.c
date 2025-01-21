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

    void dequeue() {
        if (isQueueEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* tempNode = frontNode;
        frontNode = frontNode->nextNode;
        delete tempNode;
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
    }

    int peekFront() {
        if (isQueueEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return frontNode->value;
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

    void reverseQueue() {
        if (isQueueEmpty() || frontNode == rearNode) {
            return;
        }
        Node* previousNode = nullptr;
        Node* currentNode = frontNode;
        Node* nextNode = nullptr;
        rearNode = frontNode;

        while (currentNode != nullptr) {
            nextNode = currentNode->nextNode;
            currentNode->nextNode = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }
        frontNode = previousNode;
    }
};

int main() {
    int choice, value;
    Queue q;

    do {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Peek Front\n4.Display Queue\n5.Reverse Queue\n6.Exit\n";
        cout << "Enter your choice:";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value to enqueue:";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Front element: " << q.peekFront() << endl;
                break;
            case 4:
                q.displayQueue();
                break;
            case 5:
                q.reverseQueue();
                cout << "Queue reversed.\n";
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 6);

    return 0;
}

