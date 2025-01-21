#include <iostream>
using namespace std;

struct Stack{
    int arr[100];
    int topIndex;
    int maxCapacity;

    Stack(int size){
        maxCapacity = size;
        topIndex = -1;
    }

    bool isEmpty(){
        return topIndex == -1;
    }

    bool isFull(){
        return topIndex == maxCapacity - 1;
    }

    void push(int value){
        if(isFull()){
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = value;
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack Underflow\n";
            return;
        }
        topIndex--;
    }

    int peek(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[topIndex];
    }

    void display(){
        if(isEmpty()){
            cout << "Stack is empty\n";
            return;
        }
        for(int i = 0; i <= topIndex; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main(){
    int capacity, choice, value;
    cout << "Enter stack capacity: ";
    cin >> capacity;
    Stack s(capacity);

    do{
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display Stack\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Top element: " << s.peek() << endl;
                break;
            case 4:
                s.display();
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
