#include <iostream>
using namespace std;

struct Queue {
    int *arr;
    int frontIdx;
    int rearIdx;
    int maxCapacity;

    Queue(int size) {
        arr = new int[size];
        maxCapacity = size;
        frontIdx = -1;
        rearIdx = -1;
    }

    bool isEmpty() {
        return frontIdx == -1;
    }

    bool isFull() {
        return rearIdx == maxCapacity - 1;
    }

    void enqueue(int val) {
        if(isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if(frontIdx == -1) {
            frontIdx = 0;
        }
        arr[++rearIdx] = val;
    }

    void dequeue() {
        if(isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        if(frontIdx == rearIdx) {
            frontIdx = rearIdx = -1;
        } else {
            frontIdx++;
        }
    }

    int peek() {
        if(isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[frontIdx];
    }

    void display() {
        if(isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for(int i = frontIdx; i <= rearIdx; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int size, option, value;
    cout << "Capacity:";
    cin >> size;
    Queue q(size);

    do {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display Queue\n5.Exit\n";
        cout << "Enter your choice:";
        cin >> option;
        switch(option) {
            case 1:
                cout << "Enter value to enqueue:";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Front element:" << q.peek() << endl;
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(option != 5);

    return 0;
}

