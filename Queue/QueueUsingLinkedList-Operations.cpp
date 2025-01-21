#include <iostream>
using namespace std;

struct Element {
    int data;
    Element* next;
};

class Queue {
public:
    Element* head;
    Element* tail;

    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    bool isQueueEmpty() {
        return head == nullptr;
    }

    void addData(int val) {
        Element* newElem = new Element{val, nullptr};
        if (isQueueEmpty()) {
            head = tail = newElem;
        } else {
            tail->next = newElem;
            tail = newElem;
        }
    }

    void removeData() {
        if (isQueueEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Element* tempElem = head;
        head = head->next;
        delete tempElem;
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    int getFront() {
        if (isQueueEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return head->data;
    }

    void showQueue() {
        if (isQueueEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Element* tempElem = head;
        while (tempElem != nullptr) {
            cout << tempElem->data << " ";
            tempElem = tempElem->next;
        }
        cout << endl;
    }
};

int main() {
    int choice, val;
    Queue q;

    do {
        cout << "\n1.Add Data\n2.Remove Data\n3.Get Front Data\n4.Show Queue\n5.Exit\n";
        cout << "Enter your choice:";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value to add:";
                cin >> val;
                q.addData(val);
                break;
            case 2:
                q.removeData();
                break;
            case 3:
                cout << "Front element:" << q.getFront() << endl;
                break;
            case 4:
                q.showQueue();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 5);

    return 0;
}

